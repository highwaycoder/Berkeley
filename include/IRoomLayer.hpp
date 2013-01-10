#ifndef IROOMLAYER_HPP
#define IROOMLAYER_HPP

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
	class IRoomLayer
	{
	public:
		virtual void render(void) = 0;
		/**
		 * \brief sets the 'image' of the layer
		 * \details for CRoomUnderlay and CRoomOverlay instances, this
		 * will set the image that is rendered during that layer's
		 * render() call.  For CRoomTileLayer instances, this will set
		 * the tileset used by the layer.
		 */
		virtual void set_image(irr::video::ITexture* img) = 0;
		virtual bool is_valid(void) = 0;
	protected:
	};
};

#endif
