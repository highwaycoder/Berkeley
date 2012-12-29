#include "CRoomScene.hpp"

using namespace berk;

void CRoomScene::load(void)
{
	using namespace irr;
	if(current_room == NULL)
	{
		throw EE_INVALID_ROOM;
	}
	video_driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	video_driver->getMaterial2D().AntiAliasing = irr::video::EAAM_FULL_BASIC;
}

void CRoomScene::unload(void)
{
	
}

void CRoomScene::render(void)
{
	using namespace irr;
	using namespace video;
	if(underlay != NULL)
	{
		video_driver->draw2DImage(
			underlay->image,
			underlay->items.begin()->first,
			underlay->items.begin()->second,
			NULL,
			SColor(255,255,255,255),
			true);
	}
	
	for(std::vector<ITile*>::iterator it = tiles.begin(); it != tiles.end(); ++it)
	{
		(*it)->render();
	}
	
	if(overlay != NULL)
	{
		for(SRoomLayer::item_iterator it = overlay->items.begin(); it != overlay->items.end(); ++it)
		{
			video_driver->draw2DImage(
				overlay->image,
				it->first,
				it->second,
				NULL,
				SColor(255,255,255,255),
				true);
		}
	}
}
