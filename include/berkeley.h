#ifndef BERKELEY_H_INCLUDED
#define BERKELEY_H_INCLUDED

#include "constants.h"
#include "enums.hpp"
#include "IEngine.hpp"
#include "CEngine.hpp"
#include "IScene.hpp"

static berk::IEngine* createEngine(berk::EGraphicsLibrary graphics_library) { return new berk::CEngine(graphics_library); }

#endif // BERKELEY_H_INCLUDED
