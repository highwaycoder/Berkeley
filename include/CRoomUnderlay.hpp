#ifndef CROOM_UNDERLAY_HPP
#define CROOM_UNDERLAY_HPP

#include "IRoomLayer.hpp"

namespace berk
{
	class CRoomUnderlay : public IRoomLayer
	{
	public:
		CRoomUnderlay(irr::video::IVideoDriver* vd) : video_driver(vd) {}
		void render(void);
		void set_image(irr::video::ITexture* img);
		bool is_valid(void);
	private:
		irr::video::ITexture* image;
		irr::video::IVideoDriver* video_driver;
		irr::core::rect<irr::s32> image_size;
	};
};

#endif
