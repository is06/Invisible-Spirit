/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_GAMEPLAY_MAP_SECTION_INTERFACE_H__
#define __IS06_ENGINE_GAMEPLAY_MAP_SECTION_INTERFACE_H__

#include "../../N3D/NPart/CMapPart.h"

namespace is06 { namespace NEngine { namespace NGameplay {

//! Map sections management interface (section: a room in a dungeon for example)
class CMapSectionInterface
{
public:
  CMapSectionInterface();
  ~CMapSectionInterface();

  void loadSection(const string& mapName, const string& sectionName, const core::vector3df& position);
  void unloadUnusedSection();
  bool hasSections();
  void clearMeshCollision(u8 sectionIndex);
  void swapLevelMeshes();

  N3D::NPart::CMapPart* getSection(u8 index);

private:
  N3D::NPart::CMapPart* Level[2];
};

}}}

#endif
