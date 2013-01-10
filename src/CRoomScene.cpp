#include "CRoomScene.hpp"
#ifdef DEBUG
#include <iostream>
#endif

using namespace berk;

void CRoomScene::load(void)
{
	using namespace irr;
	if(current_room == NULL) throw EE_INVALID_ROOM;
	video_driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	video_driver->getMaterial2D().AntiAliasing = irr::video::EAAM_FULL_BASIC;
	#ifdef DEBUG
	std::cout << "Loaded RoomScene: " << irr::core::stringc(current_room->get_name()).c_str();
	#endif
}

void CRoomScene::unload(void)
{
	
}

void CRoomScene::render(void)
{
	// this should be impossible, but in the interests of coding defensively we'll leave in the NULL check - we can't guarantee people don't call ->render() before ->load()
	if(current_room == NULL) throw EE_INVALID_ROOM;
	current_room->render();
}
