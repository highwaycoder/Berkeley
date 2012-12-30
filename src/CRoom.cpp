#include "CRoom.hpp"

using namespace berk;

SRoomItem createSRoomItem(irr::s32 x,irr::s32 y,irr::s32 sheet_loc_x,irr::s32 sheet_loc_y,irr::s32 w, irr::s32 h)
{
	SRoomItem rv;
	rv.draw_location = irr::core::position2d<irr::s32>(x,y);
	rv.sheet_location = irr::core::rect<irr::s32>(sheet_loc_x,sheet_loc_y,sheet_loc_x+w,sheet_loc_y+h);
	return rv;
}

CRoom::~CRoom()
{
	if(underlay) delete underlay;
	if(overlay) delete overlay;
}

CRoom::CRoom(irr::io::IXMLReader* xml,irr::video::IVideoDriver* vd) : video_driver(vd)
{
	underlay = new SRoomLayer();
	overlay = new SRoomLayer();
	while(xml && xml->read())
	{
		irr::core::stringw node_name = xml->getNodeName();
		if(node_name == L"underlay" || node_name == L"overlay")
		{
			while(xml && xml->read())
			{
				if(node_name == xml->getNodeName() && xml->getNodeType() == irr::io::EXN_ELEMENT_END) break;
				if(irr::core::stringw("image") == xml->getNodeName())
				{
					if(node_name == L"underlay")
						underlay->image = vd->getTexture(xml->getAttributeValueSafe(L"src"));
					else if(node_name == L"overlay")
						overlay->image = vd->getTexture(xml->getAttributeValueSafe(L"src"));
				}
				else if(irr::core::stringw("item") == xml->getNodeName())
				{
					if(node_name == L"underlay")
					{
						underlay->items[xml->getAttributeValueSafe(L"name")] =
							createSRoomItem(
								xml->getAttributeValueAsInt(L"x"),
								xml->getAttributeValueAsInt(L"y"),
								xml->getAttributeValueAsInt(L"sheet_loc_x"),
								xml->getAttributeValueAsInt(L"sheet_loc_y"),
								xml->getAttributeValueAsInt(L"width"),
								xml->getAttributeValueAsInt(L"height")
							);
					}
					else if(node_name == L"overlay")
					{
						//! \todo
					}
				}
			}
		}
	}
	// we can draw rooms without an overlay, but drawing rooms without an underlay would be pointless
	if(underlay->image == NULL) throw EE_INVALID_ROOM;
}

void CRoom::add_room(ERoomDirection direction,IRoom* room)
{
	switch(direction)
	{
		case ERD_NORTH:
			room->set_room(ERD_SOUTH,this);
			north = room;
			break;
		case ERD_EAST:
			room->set_room(ERD_WEST,this);
			east = room;
			break;
		case ERD_SOUTH:
			room->set_room(ERD_NORTH,this);
			south = room;
			break;
		case ERD_WEST:
			room->set_room(ERD_EAST,this);
			west = room;
			break;
	}
}

IRoom* CRoom::move_rooms(ERoomDirection direction)
{
	IRoom* rv = NULL;
	switch(direction)
	{
		case ERD_NORTH:
			rv = north;
			break;
		case ERD_EAST:
			rv = east;
			break;
		case ERD_SOUTH:
			rv = south;
			break;
		case ERD_WEST:
			rv = west;
			break;
	}
	if(rv == NULL) throw EE_INVALID_ROOM;
	else
	{
		// we're no longer the "active" room, so we need to clean up all our 'connections'
		// note that architecturally this could be done better, but for now this will do the job
		delete north;
		delete south;
		delete west;
		delete east;
		north = south = west = east = NULL;
	}
	
	return rv;
}

void CRoom::set_room(ERoomDirection direction,IRoom* room)
{
	switch(direction)
	{
		case ERD_NORTH:
			north = room;
			break;
		case ERD_EAST:
			east = room;
			break;
		case ERD_SOUTH:
			south = room;
			break;
		case ERD_WEST:
			west = room;
			break;
	}
}

void CRoom::delete_room(ERoomDirection direction)
{
	switch(direction)
	{
		case ERD_NORTH:
			delete north;
			north = NULL;
			break;
		case ERD_EAST:
			delete east;
			east = NULL;
			break;
		case ERD_SOUTH:
			delete south;
			south = NULL;
			break;
		case ERD_WEST:
			delete west;
			west = NULL;
			break;
	}
}

void CRoom::draw_layer(const SRoomLayer& layer)
{
	using namespace irr;
	using namespace video;
	for(SRoomLayer::const_item_iterator it = layer.items.begin(); it != layer.items.end(); ++it)
	{
		video_driver->draw2DImage(
			layer.image,
			it->second.draw_location,
			it->second.sheet_location, // it doesn't matter that this has an x,y component, draw2DImage only reads the w,h components (I hope!)
			NULL,
			SColor(255,255,255,255),
			true);
	}
}


void CRoom::render(void)
{
	if(underlay != NULL)
		draw_layer(*underlay);
	
	for(std::vector<ISprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		(*it)->render();
	}
	
	if(overlay != NULL)
		draw_layer(*overlay);
}

void CRoom::add_sprite(ISprite* sprite)
{
	sprites.push_back(sprite);
}
