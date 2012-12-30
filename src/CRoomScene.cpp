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

void CRoomScene::draw_layer(const SRoomLayer& layer)
{
	using namespace irr;
	using namespace video;
	for(SRoomLayer::const_item_iterator it = layer.items.begin(); it != layer.items.end(); ++it)
	{
		video_driver->draw2DImage(
			layer.image,
			it->first,
			it->second,
			NULL,
			SColor(255,255,255,255),
			true);
	}
}

void CRoomScene::render(void)
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
