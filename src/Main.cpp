#include "berkeley.h"

using namespace berk;

int main(void)
{
	IEngine* engine = createEngine(berk::EGL_OPENGL);
	int rv = 0;
	try {
		rv = engine->run();
	} catch (EException e) {
		std::string reason;
		switch(e)
		{
			case EE_INVALID_ROOM:
				reason = "invalid room";
				break;
			case EE_INVALID_SCENE:
				reason = "invalid scene";
				break;
			case EE_CUTSCENE_FINISHED:
				reason = "cutscene finished without a new scene being loaded";
				break;
			case EE_LOGOS_FINISHED:
				reason = "logo screen finished without a new scene being loaded";
				break;
		}
		engine->shutdown(reason);
	}
	return rv;
}
