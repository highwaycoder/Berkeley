#ifndef CENGINE_HPP
#define CENGINE_HPP

#include "IEngine.hpp"
#include "constants.h"
#include "IScene.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

namespace berk
{
    class CEngine : public IEngine
    {
        public:
            CEngine(const EGraphicsLibrary gl,unsigned int xr=BERK_DEFAULT_XRES,unsigned int yr=BERK_DEFAULT_YRES);
            virtual int run(void);
        protected:
        private:
        // private methods
            void init(void);
            void render(void);
            
        // private variables
            irr::video::IVideoDriver* irrlicht_driver;
            irr::scene::ISceneManager* irrlicht_scene_manager;
            IScene* current_scene;
            
            int error_status;
            const EGraphicsLibrary graphics_library;
            unsigned int xres,yres;
    };
};
#endif // CENGINE_HPP
