#ifndef ISCENE_HPP
#define ISCENE_HPP

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class IScene
	{
	public:
		IScene(irr::IrrlichtDevice* d) : irrlicht_device(d) {}
		virtual void load(void) = 0;
		virtual void unload(void) = 0;
		virtual void render(void) = 0;
	protected:
		irr::IrrlichtDevice* irrlicht_device;
	private:
	};
};

#endif
