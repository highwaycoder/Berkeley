#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "IRoom.hpp"

namespace berk
{
	class IPlayer
	{
	public:
		virtual IRoom* get_location(void) = 0;
	protected:
	};
};

#endif
