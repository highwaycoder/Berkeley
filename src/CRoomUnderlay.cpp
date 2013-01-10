#include "CRoomUnderlay.hpp"

using namespace berk;

void CRoomUnderlay::render(void)
{
	video_driver->draw2DImage(
		image,
		irr::core::position2d<irr::s32>(0,0),
		image_size,
		NULL,
		irr::video::SColor(255,255,255,255),
		true);
}

void CRoomUnderlay::set_image(irr::video::ITexture* img)
{
	image = img;
}

bool CRoomUnderlay::is_valid(void)
{
	return (image != NULL);
}

