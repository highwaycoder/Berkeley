/*
 * enums.hpp
 *
 *  Created on: Dec 26, 2012
 *      Author: chris
 */

#ifndef ENUMS_HPP
#define ENUMS_HPP

namespace berk
{
    enum EGraphicsLibrary
    {
        EGL_OPENGL,
        EGL_DIRECTX9,
        EGL_DIRECTX11
    };
    
    enum ECutScene
    {
      ECS_LOGO  
    };
    
    enum EException
    {
      EE_INVALID_SCENE,
      EE_LOGOS_FINISHED,
      EE_CUTSCENE_FINISHED,
      EE_INVALID_ROOM
    };
    
    enum ERoomDirection
    {
       ERD_NORTH,
       ERD_EAST,
       ERD_SOUTH,
       ERD_WEST 
    };
    
    enum EMenuButton
    {
        EMB_NEW_GAME,
    };
    
    enum ETileType
    {
        ETT_BLANK,
    };
}


#endif /* ENUMS_HPP_ */
