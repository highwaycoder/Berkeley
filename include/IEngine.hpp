#ifndef IENGINE_HPP
#define IENGINE_HPP

#include "enums.hpp"
#include "IScene.hpp"
#include "CCutScene.hpp"
#include "CMainMenu.hpp"
#include "IPlayer.hpp"
#include "CRoomScene.hpp"
#include <iostream>

namespace berk
{
    class IEngine
    {
    public:
		virtual int run(void) = 0;
		IScene* create_cut_scene(ECutScene cutscene) { return new CCutScene(irrlicht_device,cutscene); }
		IScene* create_main_menu(void) { return new CMainMenu(irrlicht_device); }
		IScene* create_room_scene(IPlayer* player = NULL) { if(player==NULL) return new CRoomScene(irrlicht_device); else return new CRoomScene(irrlicht_device,player->get_location()); }
		virtual void new_game(void) = 0;
		virtual void shutdown(const std::string& reason) { std::cout << "shutting down: " << reason << std::endl; irrlicht_device->closeDevice(); }
    protected:
		irr::IrrlichtDevice* irrlicht_device;
    };
};

#endif
