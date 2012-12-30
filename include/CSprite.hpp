#ifndef CSPRITE_HPP
#define CSPRITE_HPP

#include "ISprite.hpp"

namespace berk
{
	class CSprite : public ISprite
	{
	public:
		CSprite(irr::video::ITexture* image,irr::core::position2d<irr::s32> location) : ISprite(image,location) {}
		virtual void render(void);
	private:
	};
};

#endif
