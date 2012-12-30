#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include "enums.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop
#include <map>

namespace berk
{
	struct SRoomItem
	{
		irr::core::position2d<irr::s32> draw_location;
		irr::core::rect<irr::s32> sheet_location;
	};
	
	struct SRoomLayer
	{
		irr::video::ITexture* image;
		std::map<irr::core::stringw, SRoomItem> items;
		typedef std::map<irr::core::stringw, SRoomItem>::const_iterator const_item_iterator;
		typedef std::map<irr::core::stringw, SRoomItem>::iterator item_iterator;
	};
	
	struct SPlayerEvent
	{
		unsigned int points_value;
		EPlayerEventType type;
		std::string description;
	};
};

#endif
