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
  // Irrlicht errors
  EEC_CODE_01, // Irrlicht device not created
  EEC_CODE_02, // Video driver not created

  // Map errors
  EEC_CODE_10, // Unknown map id

  // Save files errors
  EEC_CODE_20, // Unable to open save file
  EEC_CODE_21, // Unable to write save file

  // Mesh and texture errors
  EEC_CODE_30, // Mesh file not found
  EEC_CODE_31, // Texture file not found

  // Scene errors
  EEC_CODE_45, // Scene requires a Level Mesh
  EEC_CODE_46, // Scene requires a Level Mesh Node
  EEC_CODE_47, // LevelMesh need a Newton Body

  // Effects errors
  EEC_CODE_50, // Vertex Shaders 1.1 not supported
  EEC_CODE_51, // Pixel Shaders 1.1 not supported
  EEC_CODE_52, // Render to target not supported
  EEC_CODE_53, // Non-square textures not supported
  EEC_CODE_54, // Non-power of two texture size not supported
  EEC_CODE_55, // GLSL not supported
  EEC_CODE_56, // HLSL not supported
  EEC_CODE_57, // Multi Render to Target not supported

  // Text errors
  EEC_CODE_60, // No local translation object for dialog interface


  EEC_CODE_COUNT
};

}
}

#endif
