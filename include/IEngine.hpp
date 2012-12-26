#ifndef IENGINE_HPP
#define IENGINE_HPP

#include "enums.hpp"
#include "IScene.hpp"
#include "CCutScene.hpp"
#include "CMainMenu.hpp"

namespace berk
{
    class IEngine
    {
    public:
		virtual int run(void) = 0;
		IScene* createCutScene(ECutScene cutscene) { return new CCutScene(irrlicht_device,cutscene); }
		IScene* createMainMenu(void) { return new CMainMenu(irrlicht_device); }
    protected:
		irr::IrrlichtDevice* irrlicht_device;
    };
};

#endif
