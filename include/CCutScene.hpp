#ifndef CCUTSCENE_HPP
#define CCUTSCENE_HPP

#include "enums.hpp"
#include "IScene.hpp"

namespace berk
{
	class CCutScene : public IScene
	{
	public:
		CCutScene(irr::IrrlichtDevice* d, ECutScene cs) : IScene(d),cutscene(cs),finished(false) {}
		virtual void load(void);
		virtual void unload(void);
		virtual void render(void);
	private:
		irr::IrrlichtDevice* irrlicht_device;
		ECutScene cutscene;
		bool finished;
	};
};

#endif
