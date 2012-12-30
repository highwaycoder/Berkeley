#include "CPlayer.hpp"

using namespace berk;

void CPlayer::render(void)
{
	sprite->render();
}

void CPlayer::add_points(SPlayerEvent event)
{
	points += event.points_value;
}


void CPlayer::remove_points(SPlayerEvent event)
{
	if(points > event.points_value)
		points -= event.points_value;
	else
		points = 0;
}

IRoom* CPlayer::get_location(void)
{
	return room;
}
