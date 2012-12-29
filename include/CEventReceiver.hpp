#ifndef CEVENT_RECEIVER_HPP
#define CEVENT_RECEIVER_HPP

#include "IEngine.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class CEventReceiver : public irr::IEventReceiver
	{
	public:
		CEventReceiver(IEngine* e) : engine(e) {}
		virtual bool OnEvent(const irr::SEvent& event);
	private:
		virtual bool handle_GUI_event(const irr::SEvent::SGUIEvent& event);
		
		IEngine* engine;
	};
};

#endif
