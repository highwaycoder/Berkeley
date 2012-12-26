#include "CCutScene.hpp"
#ifdef DEBUG
#include <iostream>
#endif

using namespace berk;

void CCutScene::load(void)
{
	// remove this line when we want to implement it!
	finished = true;
	#ifdef DEBUG
	std::cout << "Loaded CutScene" << std::endl;
	#endif
}

void CCutScene::unload(void)
{
	#ifdef DEBUG
	std::cout << "Unloaded CutScene" << std::endl;
	#endif
}

void CCutScene::render(void)
{
	if(finished)
	{
		if (cutscene == ECS_LOGO)
			throw EE_LOGOS_FINISHED;
		else
			throw EE_CUTSCENE_FINISHED;
	}
}
