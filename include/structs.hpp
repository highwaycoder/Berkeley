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
		irr::core::position2d<irr::s32> position;
		irr::core::rect<irr::s32> size;
	};
	
	struct SRoomLayer
	{
		irr::video::ITexture* image;
		std::map<std::string, SRoomItem> items;
		typedef std::map<std::string, SRoomItem>::const_iterator const_item_iterator;
		typedef std::map<std::string, SRoomItem>::iterator item_iterator;
	};
	
	struct SPlayerEvent
	{
		unsigned int points_value;
		EPlayerEventType type;
		std::string description;
	};
};

#endif
