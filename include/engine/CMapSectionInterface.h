/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_SECTION_INTERFACE_H__
#define __IS06_MAP_SECTION_INTERFACE_H__

namespace is06
{
namespace nEngine
{

//! Map sections management interface (section: a room in a dungeon for example)
class CMapSectionInterface
{
  public:
    CMapSectionInterface();
    ~CMapSectionInterface();

    void loadSection(const string& mapName, const string& sectionName, const core::vector3df& position);
    void unloadUnusedSection();
    void clearMeshCollision(u8 sectionIndex);
    void swapLevelMeshes();

    n3D::CLevelMesh* getSection(u8 index);

  private:
    n3D::CLevelMesh* Level[2];
};

}
}

#endif
