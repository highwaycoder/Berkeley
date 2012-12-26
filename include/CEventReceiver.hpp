#ifndef CEVENT_RECEIVER_HPP
#define CEVENT_RECEIVER_HPP

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class CEventReceiver : public irr::IEventReceiver
	{
	public:
		virtual bool OnEvent(const irr::SEvent& event);
	};
};

#endif
