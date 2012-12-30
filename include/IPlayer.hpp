#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "IRoom.hpp"
#include "structs.hpp"

namespace berk
{
	class IPlayer
	{
	public:
		IPlayer(IRoom* r) : room(r) {}
		virtual IRoom* get_location(void) = 0;
		virtual void render(void) = 0;
		virtual void add_points(SPlayerEvent event) = 0;
		virtual void remove_points(SPlayerEvent event) = 0;
	protected:
		IRoom* room;
	};
};

#endif
