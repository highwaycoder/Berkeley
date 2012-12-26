#include "CMainMenu.hpp"
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
	// waiting on Bret to come back with some artwork
}

void CMainMenu::unload_gui(void)
{
	
}

void CMainMenu::render(void)
{
	gui->drawAll();
}
