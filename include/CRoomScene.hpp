#ifndef CROOMSCENE_HPP
#define CROOMSCENE_HPP

#include "IScene.hpp"
#include "IRoom.hpp"

namespace berk
{
	class CRoomScene : public IScene
	{
	public:
		CRoomScene(irr::IrrlichtDevice* d) : IScene(d) {}
		virtual void load(void);
		virtual void unload(void);
		virtual void render(void);
	private:
		IRoom* current_room;
	};
};

#endif
