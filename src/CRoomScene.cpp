#include "CRoomScene.hpp"

using namespace berk;

void CRoomScene::load(void)
{
	using namespace irr;
	if(current_room == NULL) throw EE_INVALID_ROOM;
	video_driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	video_driver->getMaterial2D().AntiAliasing = irr::video::EAAM_FULL_BASIC;
}

void CRoomScene::unload(void)
{
	
}

void CRoomScene::render(void)
{
	if(current_room == NULL) throw EE_INVALID_ROOM;
	current_room->render();
}
