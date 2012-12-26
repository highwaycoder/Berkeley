#include "berkeley.h"

using namespace berk;

int main(void)
{
	IEngine* engine = createEngine(berk::EGL_OPENGL);

	return engine->run();
}
