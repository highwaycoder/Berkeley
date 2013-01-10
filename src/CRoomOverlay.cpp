#include "CRoomOverlay.hpp"

using namespace berk;

void CRoomOverlay::render(void)
{
	video_driver->draw2DImage(
		image,
		irr::core::position2d<irr::s32>(0,0),
		image_size,
		NULL,
		irr::video::SColor(255,255,255,255),
		true);
}

void CRoomOverlay::set_image(irr::video::ITexture* img)
{
	image = img;
}

bool CRoomOverlay::is_valid(void)
{
	return (image != NULL);
}
