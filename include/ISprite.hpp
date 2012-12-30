#ifndef ISPRITE_HPP
#define ISPRITE_HPP

#include "enums.hpp"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class ISprite
	{
	public:
		ISprite(irr::video::ITexture* i,irr::core::position2d<irr::s32> l) : image(i),location(l) {}
		virtual void render(void) = 0;
	protected:
		irr::video::ITexture* image;
		irr::core::position2d<irr::s32> location;
	};
};

#endif
