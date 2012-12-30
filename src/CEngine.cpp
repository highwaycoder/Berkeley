#include "CEngine.hpp"
#include "CMainMenu.hpp"
#include "CEventReceiver.hpp"
#include "CPlayer.hpp"
#include "CSprite.hpp"
#include "CRoom.hpp"
#include <iostream>

using namespace berk;
using namespace irr;

CEngine::CEngine(const EGraphicsLibrary gl,unsigned int xr,unsigned int yr) : graphics_library(gl), xres(xr), yres(yr)
{
	error_status = 0;
	event_receiver = new CEventReceiver(this);
}

CEngine::~CEngine(void)
{
	if(event_receiver)
		delete event_receiver;
}

int CEngine::run(void)
{
	init();
	while(irrlicht_device->run() && irrlicht_driver)
	{
		render();
	}
	irrlicht_device->drop();
	return error_status;
}

void CEngine::init(void)
{
	switch(graphics_library)
	{
		case EGL_OPENGL:
			irrlicht_device = createDevice(video::EDT_OPENGL,core::dimension2d<u32>(xres,yres));
			break;
		case EGL_DIRECTX11:
			std::cerr << "Warning: DX11 not yet supported.  Defaulting to DX9";
		case EGL_DIRECTX9:
			irrlicht_device = createDevice(video::EDT_DIRECT3D9,core::dimension2d<u32>(xres,yres));
			break;
	}
	
	irrlicht_device->setEventReceiver(event_receiver);
	irrlicht_driver = irrlicht_device->getVideoDriver();
	irrlicht_scene_manager = irrlicht_device->getSceneManager();
	
	// start off with the logos
	current_scene = create_cut_scene(ECS_LOGO);

	current_scene->load();
}

void CEngine::new_game(void)
{
	if(current_scene)
	{
		current_scene->unload(); // important to always do this before calling the destructor
		delete current_scene;
	}
	IRoom* starting_room = load_room("rooms/start.xml");
	ISprite* player_sprite = load_sprite("sprites/player.tga",irr::core::position2d<irr::s32>(
	
	));
	player = new CPlayer(player_sprite,starting_room);
	current_scene = create_room_scene(player);
	try {
		current_scene->load();
	} catch (EException e) {
		switch(e)
		{
			case EE_INVALID_ROOM: // we can't handle this exception, so let's throw it further up the stack
			default:
			{
				// by default, pass the exception further up so we make sure we do actually handle it somewhere
				throw e;
				break;
			}
		}
	}
}

void CEngine::render(void)
{
	irrlicht_driver->beginScene();
	try {
		current_scene->render();
	} catch (EException e) {
		switch(e)
		{
			case EE_LOGOS_FINISHED:
			{
				current_scene->unload();
				delete current_scene;
				current_scene = create_main_menu();
				current_scene->load();
				break;
			}
			case EE_INVALID_SCENE:
			{
				std::cerr << "Warning: invalid scene loaded (or perhaps the scene has been unloaded prematurely?)" << std::endl;
				break;
			}
			default:
			{
				throw e;
				break;
			}
		}
	}
	irrlicht_driver->endScene();
}

irr::video::ITexture* CEngine::load_image(const std::string& file)
{
	irr::video::ITexture* rv;
	std::map<std::string,irr::video::ITexture*>::iterator loaded_image = loaded_images.find(file);
	if(loaded_image == loaded_images.end())
	{
		rv = irrlicht_driver->getTexture(irr::io::path(file.c_str()));
	}
	else
	{
		rv = loaded_image->second;
	}
	return rv;
}

IRoom* CEngine::load_room(const std::string& room_file)
{
	if(!irrlicht_device->getFileSystem()->existFile(irr::io::path(room_file.c_str())))
	{
		#ifdef DEBUG
		std::cerr << "Could not load room, room file could not be opened: " << room_file << std::endl;
		#endif
		return NULL;
	}
	irr::io::IXMLReader* xml = irrlicht_device->getFileSystem()->createXMLReader(irr::io::path(room_file.c_str()));
	return new CRoom(xml);
}

ISprite* CEngine::load_sprite(const std::string& image_file,irr::core::position2d<irr::s32> sprite_loc)
{
	return new CSprite(load_image(image_file),sprite_loc);
}
