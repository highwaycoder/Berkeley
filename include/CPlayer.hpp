#ifndef CPLAYER_HPP
#define CPLAYER_HPP

#include "IPlayer.hpp"
#include "ISprite.hpp"
#include "constants.h"

namespace berk
{
	class CPlayer : public IPlayer
	{
	public:
		CPlayer(ISprite* s,IRoom* room,unsigned int p = BERK_PLAYER_START_POINTS) : IPlayer(room),points(p),sprite(s) {}
		virtual IRoom* get_location(void);
		virtual void render(void);
		virtual void add_points(SPlayerEvent event);
		virtual void remove_points(SPlayerEvent event);
	private:
		unsigned int points;
		ISprite* sprite;
	};
};

#endif
