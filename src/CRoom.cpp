#include "CRoom.hpp"

using namespace berk;

CRoom::CRoom(irr::io::IXMLReader* xml,irr::video::IVideoDriver* vd) : video_driver(vd)
{
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
						//! \todo
					}
					else if(node_name == L"overlay")
					{
						//! \todo
					}
				}
			}
		}
	}
}

void CRoom::add_room(ERoomDirection direction,IRoom* room)
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
	return rv;
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
			it->second.position,
			it->second.size,
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
