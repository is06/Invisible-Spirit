/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ERROR_CODE_H__
#define __IS06_ERROR_CODE_H__

namespace is06
{
namespace nDebug
{

//! Error code enumeration
enum EErrorCode
{
  // Map errors
  ERRCODE_10, // Unknown map id

  // Save files errors
  ERRCODE_20, // Unable to open save file
  ERRCODE_21, // Unable to write save file

  // Mesh and texture errors
  ERRCODE_30, // Mesh file not found
  ERRCODE_31, // Texture file not found

  // Scene errors
  ERRCODE_45, // Scene requires a Level Mesh
  ERRCODE_46, // Scene requires a Level Mesh Node
  ERRCODE_47, // LevelMesh need a Newton Body

  // Effets errors
  ERRCODE_50, // Vertex Shaders 1.1 not supported
  ERRCODE_51, // Pixel Shaders 1.1 not supported
  ERRCODE_52, // Render to target not supported
  ERRCODE_53, // Non-square textures not supported
  ERRCODE_54, // Non-power of two texture size not supported
  ERRCODE_55, // GLSL not supported
  ERRCODE_56, // Multi Render to Target not supported

  // Text errors
  ERRCODE_60, // No local translation object for dialog interface


  ERRCODE_COUNT
};

}
}

#endif
