#ifndef __OPACITY_SHADER_CALLBACK_H__
#define __OPACITY_SHADER_CALLBACK_H__

using namespace irr;

class OpacityShaderCallback : public video::IShaderConstantSetCallBack {
  public:
    const video::SMaterial* usedMaterial;
    virtual void OnSetMaterial(const video::SMaterial& material) {
      usedMaterial = &material;
    }
    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData) {
      f32 vColor[4] = {
        usedMaterial->DiffuseColor.getRed() / 255.0f,
        usedMaterial->DiffuseColor.getGreen() / 255.0f,
        usedMaterial->DiffuseColor.getBlue() / 255.0f,
        usedMaterial->DiffuseColor.getAlpha() / 255.0f
      };
      services->setVertexShaderConstant("vColor", vColor, 4);
    }
};

#endif
