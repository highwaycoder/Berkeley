#include "CEngine.hpp"
#include "CMainMenu.hpp"
#include <iostream>

using namespace berk;
using namespace irr;

CEngine::CEngine(const EGraphicsLibrary gl,unsigned int xr,unsigned int yr) : graphics_library(gl), xres(xr), yres(yr)
{
	error_status = 0;
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
	
	irrlicht_driver = irrlicht_device->getVideoDriver();
	irrlicht_scene_manager = irrlicht_device->getSceneManager();
	
	// start off with the company logo
	current_scene = createCutScene(ECS_LOGO);

	current_scene->load();
}

void CEngine::render(void)
{
	irrlicht_driver->beginScene();
	// by deferring to the IScene class, we don't need to unnecessarily call (for example) gui->drawAll() in scenes without a GUI
	try {
		current_scene->render();
	} catch (EException e) {
		switch(e)
		{
			case EE_LOGOS_FINISHED:
			{
				current_scene->unload();
				current_scene = createMainMenu();
				current_scene->load();
				break;
			}
			case EE_INVALID_SCENE:
			{
				std::cerr << "Warning: invalid scene loaded (or perhaps the scene has been unloaded prematurely?)" << std::endl;
				break;
			}
		}
	}
	irrlicht_driver->endScene();
}
