#ifndef CROOM_HPP
#define CROOM_HPP

#include "IRoom.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class CRoom : public IRoom
	{
	public:
		CRoom(irr::io::IXMLReader* xml) : xml(xml) {}
		void add_room(ERoomDirection direction,IRoom* room);
		IRoom* move_rooms(ERoomDirection direction);
		void delete_room(ERoomDirection direction);
		void render(void);
		void add_room(ERoomDirection direction, const std::string& room_filename);
	private:
		irr::io::IXMLReader* xml;
	};
};

#endif
