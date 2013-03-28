/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_RESOURCE_RESOURCE_MANAGER_H__
#define __IS06_ENGINE_RESOURCE_RESOURCE_MANAGER_H__

using namespace irr;
using namespace std;

namespace is06 { namespace NEngine { namespace NResource {

class CResourceManager
{
public:
  CResourceManager();
  ~CResourceManager();

  scene::IMesh* loadMesh(const string& path);
  video::ITexture* loadTexture(const string& path);
};

}}}

#endif
