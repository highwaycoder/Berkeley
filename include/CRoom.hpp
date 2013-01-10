#ifndef CROOM_HPP
#define CROOM_HPP

#include "IRoom.hpp"
#include "structs.hpp"
#include "ISprite.hpp"
#include "IRoomLayer.hpp"

/* -- we really need to sort out the hierarchy of this include
 * at the moment IRoomLayer includes it so this file doesn't need to
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop
*/

#include <vector>

namespace berk
{
	class CRoom : public IRoom
	{
	public:
		CRoom(irr::io::IXMLReader* xml,irr::video::IVideoDriver* vd);
		~CRoom();
		void add_room(ERoomDirection direction,IRoom* room);
		IRoom* move_rooms(ERoomDirection direction);
		void delete_room(ERoomDirection direction);
		void set_room(ERoomDirection direction, IRoom* room);
		void render(void);
		void add_sprite(ISprite* sprite);
		virtual irr::core::stringw get_name(void);
	private:
	
		irr::core::stringw name;
		IRoomLayer* underlay;
		IRoomLayer* tile_layer;
		std::vector<ISprite*> sprites;
		IRoomLayer* overlay;
		
		irr::video::IVideoDriver* video_driver;
		
	};
};

#endif
