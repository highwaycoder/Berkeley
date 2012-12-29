#include "CEventReceiver.hpp"
#ifdef DEBUG
#include <iostream>
#endif

using namespace berk;

bool CEventReceiver::OnEvent(const irr::SEvent& event)
{
	bool rv = false; // assume we didn't handle the event, unless we did
	switch(event.EventType)
	{
		case irr::EET_GUI_EVENT:
		{
			rv = handle_GUI_event(event.GUIEvent);
			break;
		}
		//! \todo implement enough event handlers that we can remove this without causing an "unhandled case statement" warning
		default:
		{
			break;
		}
	}
	return rv;
}

bool CEventReceiver::handle_GUI_event(const irr::SEvent::SGUIEvent& event)
{
	bool rv = false;
	switch(event.Caller->getID())
	{
		case EMB_NEW_GAME:
		{
			if(event.EventType == irr::gui::EGET_BUTTON_CLICKED)
			{
				#ifdef DEBUG
				std::cout << "New game button pressed" << std::endl;
				#endif
				engine->new_game();
			}
			break;
		}
	}
	return rv;
}
