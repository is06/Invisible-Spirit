/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/Gameplay/CMapSectionInterface.h"
#include "../../../include/3D/CLevelMesh.h"

namespace is06
{
namespace NEngine
{
namespace NGameplay
{

CMapSectionInterface::CMapSectionInterface()
{
  Level[0] = NULL;
  Level[1] = NULL;
}

void CMapSectionInterface::loadSection(const string& mapName, const string& sectionName, const core::vector3df& position)
{
  if (Level[0] != NULL) {
    swapLevelMeshes();
  }

  Level[0] = new N3D::CLevelMesh();
  Level[0]->loadMesh("resource/mesh/level/" + mapName + "/" + sectionName + ".obj");
  Level[0]->createNode(position);
  Level[0]->loadMeshCollision();

  unloadUnusedSection();
}

void CMapSectionInterface::unloadUnusedSection()
{
  if (Level[1]) {
    delete Level[1];
  }
}

bool CMapSectionInterface::hasSections()
{
  return (Level[0] != NULL);
}

void CMapSectionInterface::clearMeshCollision(u8 sectionIndex)
{
  Level[sectionIndex]->clearMeshCollision();
}

void CMapSectionInterface::swapLevelMeshes()
{
  N3D::CLevelMesh* tmp;
  tmp = Level[1];
  Level[1] = Level[0];
  Level[0] = tmp;
}

N3D::CLevelMesh* CMapSectionInterface::getSection(u8 index)
{
  return Level[index];
}

CMapSectionInterface::~CMapSectionInterface()
{
  if (Level[0]) delete Level[0];
  if (Level[1]) delete Level[1];
}

}
}
}
