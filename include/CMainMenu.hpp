#ifndef CMAIN_MENU_HPP
#define CMAIN_MENU_HPP

#include "IScene.hpp"

namespace berk
{
	class CMainMenu : public IScene
	{
	public:
		CMainMenu(irr::IrrlichtDevice* d) : IScene(d) { gui = d->getGUIEnvironment(); }
		virtual void load(void);
		virtual void unload(void);
		virtual void render(void);
	private:
		virtual void load_gui(void);
		virtual void unload_gui(void);
		irr::gui::IGUIEnvironment* gui;
	};
};

#endif
