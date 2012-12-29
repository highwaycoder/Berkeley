#ifndef CROOMSCENE_HPP
#define CROOMSCENE_HPP

#include "IScene.hpp"
#include "IRoom.hpp"
#include "ITile.hpp"
#include "structs.hpp"
#include <vector>
#include <map>

namespace berk
{
	class CRoomScene : public IScene
	{
	public:
		CRoomScene(irr::IrrlichtDevice* d,IRoom* room = NULL) : 
			IScene(d),
			current_room(room),
			underlay(NULL),
			video_driver(d->getVideoDriver())
			{}
		virtual void load(void);
		virtual void unload(void);
		virtual void render(void);
	private:
		IRoom* current_room;

		SRoomLayer* underlay;
		std::vector<ITile*> tiles;
		SRoomLayer* overlay;
		
		irr::video::IVideoDriver* video_driver;
	};
};

#endif
