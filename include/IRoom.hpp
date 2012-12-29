#ifndef IROOM_HPP
#define IROOM_HPP

#include <string>
#include "enums.hpp"

namespace berk
{
	class IRoom
	{
	public:
		IRoom() { north = east = south = west = NULL; }
		virtual ~IRoom()
		{
			if(north) delete north;
			if(east) delete east;
			if(south) delete south;
			if(west) delete west;
		}
		virtual void add_room(ERoomDirection direction,IRoom* room) = 0;
		virtual IRoom* move_rooms(ERoomDirection direction) = 0;
		virtual void delete_room(ERoomDirection direction) = 0;
		virtual void render(void) = 0;
		virtual void add_room(ERoomDirection direction, const std::string& room_filename) = 0;
	protected:
	// hack to get around the fact C++ can't specify pointer types in a list
		typedef IRoom* pIRoom;
		pIRoom north,east,south,west;
	};
};

#endif
