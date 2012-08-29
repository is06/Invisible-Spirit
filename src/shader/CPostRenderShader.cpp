/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/shader/CPostRenderShader.h"

namespace is06
{
namespace nShader
{

CPostRenderShader::CPostRenderShader() : CHud2DElement(0, 0, nEngine::CGame::ScreenPos.Width, nEngine::CGame::ScreenPos.Height)
{
  Texture = 0;

  MinTextureOffset.X = 0.0f;
  MinTextureOffset.Y = 1.0f;
  MaxTextureOffset.X = 1.0f;
  MaxTextureOffset.Y = 0.0f;
}

void CPostRenderShader::render()
{

}

void CPostRenderShader::addEntityForEffect(n3D::CModelEntity* entity, EShaderEffect effect)
{

}

CPostRenderShader::~CPostRenderShader()
{

}

}
}
