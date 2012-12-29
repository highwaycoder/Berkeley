#ifndef CROOMSCENE_HPP
#define CROOMSCENE_HPP

#include "IScene.hpp"
#include "IRoom.hpp"
#include "ITile.hpp"
#include <vector>

namespace berk
{
	class CRoomScene : public IScene
	{
	public:
		CRoomScene(irr::IrrlichtDevice* d,IRoom* room = NULL) : IScene(d),current_room(room) {}
		virtual void load(void);
		virtual void unload(void);
		virtual void render(void);
	private:
		IRoom* current_room;
		irr::video::ITexture* underlay;
		std::vector<ITile*> tiles;
		irr::video::ITexture* overlay;
	};
};

#endif
