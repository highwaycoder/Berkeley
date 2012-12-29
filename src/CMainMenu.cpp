#include "CMainMenu.hpp"
#include "enums.hpp"
#ifdef DEBUG
#include <iostream>
#endif

using namespace berk;

void CMainMenu::load(void)
{
	#ifdef DEBUG
	std::cout << "Loaded Main Menu" << std::endl;
	#endif
	load_gui();
}

void CMainMenu::unload(void)
{
	#ifdef DEBUG
	std::cout << "Unloaded Main Menu" << std::endl;
	#endif
	unload_gui();
}

void CMainMenu::load_gui(void)
{
	using namespace irr;
	using namespace gui;
	IGUIEnvironment* gui = irrlicht_device->getGUIEnvironment();
	// waiting on Bret to come back with some artwork for the menu system
	
	// in the mean time, let's just add a button so we can move on with the "room" system
	gui->addButton(core::rect<s32>(200,100,350,150),0,(s32)EMB_NEW_GAME,L"New Game",L"Just a test though");
	
}

void CMainMenu::unload_gui(void)
{
	
}

void CMainMenu::render(void)
{
	gui->drawAll();
}
