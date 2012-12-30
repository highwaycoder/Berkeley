#ifndef CROOM_HPP
#define CROOM_HPP

#include "IRoom.hpp"
#include "structs.hpp"
#include "ISprite.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop
#include <vector>

namespace berk
{
	class CRoom : public IRoom
	{
	public:
		CRoom(irr::io::IXMLReader* xml,irr::video::IVideoDriver* vd);
		void add_room(ERoomDirection direction,IRoom* room);
		IRoom* move_rooms(ERoomDirection direction);
		void delete_room(ERoomDirection direction);
		void render(void);
		void add_sprite(ISprite* sprite);
	private:
		void draw_layer(const SRoomLayer& layer);
		
		SRoomLayer* underlay;
		std::vector<ISprite*> sprites;
		SRoomLayer* overlay;
		
		irr::video::IVideoDriver* video_driver;
	};
};

#endif
