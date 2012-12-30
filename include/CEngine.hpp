#ifndef CENGINE_HPP
#define CENGINE_HPP

#include "IEngine.hpp"
#include "constants.h"
#include "IScene.hpp"
#include "IPlayer.hpp"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrlicht.h>
#pragma GCC diagnostic pop

#include <map>

namespace berk
{
    class CEngine : public IEngine
    {
        public:
            CEngine(const EGraphicsLibrary gl=EGL_OPENGL,unsigned int xr=BERK_DEFAULT_XRES,unsigned int yr=BERK_DEFAULT_YRES);
            ~CEngine(void);
            int run(void);
            void new_game(void);
        protected:
        private:
        // private methods
            void init(void);
            void render(void);
            ISprite* load_sprite(const std::string& image_file,irr::core::position2d<irr::s32> sprite_loc);
            IRoom* load_room(const std::string& room_file);
            irr::video::ITexture* load_image(const std::string& file);
            
        // private variables
            irr::video::IVideoDriver* irrlicht_driver;
            irr::scene::ISceneManager* irrlicht_scene_manager;
            IScene* current_scene;
            irr::IEventReceiver* event_receiver;
            
            int error_status;
            const EGraphicsLibrary graphics_library;
            unsigned int xres,yres;
            
            IPlayer* player;
            
            std::map<std::string,irr::video::ITexture*> loaded_images;
    };
};
#endif // CENGINE_HPP
