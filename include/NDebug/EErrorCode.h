/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DEBUG_ERROR_CODE_H__
#define __IS06_DEBUG_ERROR_CODE_H__

namespace is06 { namespace NDebug {

//! Error code enumeration
enum EErrorCode
{
    // Irrlicht errors
    ERROR_CODE_01, // Irrlicht device not created
    ERROR_CODE_02, // Video driver not created

    // Map errors
    ERROR_CODE_10, // Unknown map id

    // Save files errors
    ERROR_CODE_20, // Unable to open save file
    ERROR_CODE_21, // Unable to write save file

    // Mesh and texture errors
    ERROR_CODE_30, // Mesh file not found
    ERROR_CODE_31, // Texture file not found

    // Scene errors
    ERROR_CODE_45, // Scene requires a Level Mesh
    ERROR_CODE_46, // Scene requires a Level Mesh Node
    ERROR_CODE_47, // LevelMesh need a Newton Body

    // Effects errors
    ERROR_CODE_50, // Vertex Shaders 1.1 not supported
    ERROR_CODE_51, // Pixel Shaders 1.1 not supported
    ERROR_CODE_52, // Render to target not supported
    ERROR_CODE_53, // Non-square textures not supported
    ERROR_CODE_54, // Non-power of two texture size not supported
    ERROR_CODE_55, // GLSL not supported
    ERROR_CODE_56, // HLSL not supported
    ERROR_CODE_57, // Multi Render to Target not supported

    // Text errors
    ERROR_CODE_60, // No local translation object for dialog interface


    ERROR_CODE_COUNT
};

}}

#endif
