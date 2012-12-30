#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include "enums.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop
#include <map>

namespace berk
{
	struct SRoomLayer
	{
		irr::video::ITexture* image;
		std::map< irr::core::position2d<irr::s32>, irr::core::rect<irr::s32> > items;
		typedef std::map< irr::core::position2d<irr::s32>, irr::core::rect<irr::s32> >::const_iterator const_item_iterator;
		typedef std::map< irr::core::position2d<irr::s32>, irr::core::rect<irr::s32> >::iterator item_iterator;
	};
	
	struct SPlayerEvent
	{
		unsigned int points_value;
		EPlayerEventType type;
		std::string description;
	};
};

#endif
