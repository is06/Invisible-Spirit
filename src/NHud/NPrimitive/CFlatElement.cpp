/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CSettings.h"
#include "../../../include/NHud/NPrimitive/CFlatElement.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPrimitive {

f32 CFlatElement::FarValue = 0.1f;
f32 CFlatElement::Coeff = 4954.94f;
u16 CFlatElement::Indices[] = {2, 1, 3, 0, 1, 2};
core::matrix4 CFlatElement::Mat;

CFlatElement::CFlatElement(f32 x, f32 y, f32 w, f32 h, bool alphaBlending) : NCore::CHudEntity()
{
    AbsoluteTransformation = core::matrix4();
    AbsoluteTransformation.makeIdentity();

    Texture = NULL;
    Opacity = 1.0f;

    // Visible on start
    Visible = true;

    // Animation Texture
    AnimSpeed = core::vector2df(0.0f, 0.0f);

    // Dimensions, position
    Size = core::dimension2df(w, h);

    // Material
    Material.Lighting = false;
    Material.DiffuseColor.setAlpha((u8)(Opacity * 255.0f));

    if (alphaBlending) {
        // Alpha blending (alpha channel + alpha vertex)
        Material.MaterialType = video::EMT_ONETEXTURE_BLEND;
        Material.MaterialTypeParam = video::pack_textureBlendFunc(
            video::EBF_SRC_ALPHA,
            video::EBF_ONE_MINUS_SRC_ALPHA,
            video::EMFN_MODULATE_1X,
            video::EAS_TEXTURE | video::EAS_VERTEX_COLOR
        );
    } else {
        // Alpha vertex
        Material.MaterialType = video::EMT_TRANSPARENT_VERTEX_ALPHA;
    }

    // Texture filtering
    if (NEngine::NCore::CGame::getSettings()->getParamString("text", "texture_filter") == "anisotropic") {
        Material.setFlag(video::EMF_ANISOTROPIC_FILTER, true);
    } else if (NEngine::NCore::CGame::getSettings()->getParamString("text", "texture_filter") == "trilinear") {
        Material.setFlag(video::EMF_TRILINEAR_FILTER, true);
    } else if (NEngine::NCore::CGame::getSettings()->getParamString("text", "texture_filter") == "none") {
        Material.setFlag(video::EMF_BILINEAR_FILTER, false);
    }

    Material.setTexture(0, NULL);

    // Disable filtering clamp
    Material.TextureLayer[0].TextureWrapU = video::ETC_CLAMP_TO_EDGE;
    Material.TextureLayer[0].TextureWrapV = video::ETC_CLAMP_TO_EDGE;

    MinTextureOffset.X = 0.0f;
    MinTextureOffset.Y = 0.0f;
    MaxTextureOffset.X = 1.0f;
    MaxTextureOffset.Y = 1.0f;

    setPosition(x, y);

    Vertices[0] = video::S3DVertex(
        core::vector3df((w/2/Coeff*-1), (h/2/Coeff), FarValue), // Position
        core::vector3df(1.0f, 1.0f, 0.0f), // Normal
        Material.DiffuseColor, // Color
        core::vector2df(MinTextureOffset.X, MinTextureOffset.Y) // Texture coords
    );
    Vertices[1] = video::S3DVertex(
        core::vector3df((w/2/Coeff), (h/2/Coeff), FarValue), // Position
        core::vector3df(1.0f, 0.0f, 0.0f), // Normal
        Material.DiffuseColor, // Color
        core::vector2df(MaxTextureOffset.X, MinTextureOffset.Y) // Texture coords
    );
    Vertices[2] = video::S3DVertex(
        core::vector3df((w/2/Coeff*-1), (h/2/Coeff*-1), FarValue), // Position
        core::vector3df(0.0f, 1.0f, 1.0f), // Normal
        Material.DiffuseColor, // Color
        core::vector2df(MinTextureOffset.X, MaxTextureOffset.Y) // Texture coords
    );
    Vertices[3] = video::S3DVertex(
        core::vector3df((w/2/Coeff), (h/2/Coeff*-1), FarValue), // Position
        core::vector3df(0.0f, 1.0f, 1.0f), // Normal
        Material.DiffuseColor, // Color
        core::vector2df(MaxTextureOffset.X, MaxTextureOffset.Y) // Texture coords
    );
}

void CFlatElement::render()
{
    // Offset de texture
    Vertices[0].TCoords.X = MinTextureOffset.X;
    Vertices[0].TCoords.Y = MinTextureOffset.Y;
    Vertices[1].TCoords.X = MaxTextureOffset.X;
    Vertices[1].TCoords.Y = MinTextureOffset.Y;
    Vertices[2].TCoords.X = MinTextureOffset.X;
    Vertices[2].TCoords.Y = MaxTextureOffset.Y;
    Vertices[3].TCoords.X = MaxTextureOffset.X;
    Vertices[3].TCoords.Y = MaxTextureOffset.Y;

    // Animation UV
    if (AnimSpeed.X != 0.0f || AnimSpeed.Y != 0.0f) {
        Vertices[0].TCoords.X += AnimSpeed.X;
        Vertices[0].TCoords.Y += AnimSpeed.Y;
        Vertices[1].TCoords.X += AnimSpeed.X;
        Vertices[1].TCoords.Y += AnimSpeed.Y;
        Vertices[2].TCoords.X += AnimSpeed.X;
        Vertices[2].TCoords.Y += AnimSpeed.Y;
        Vertices[3].TCoords.X += AnimSpeed.X;
        Vertices[3].TCoords.Y += AnimSpeed.Y;
    }

    // Draws vertices of 2D element only if visible
    if (Visible) {
        // Texture of 2D element
        if (Texture) {
            Material.setTexture(0, Texture);
        }

        for (int i = 0; i <= 3; i++) {
            // Color
            Vertices[i].Color = Material.DiffuseColor;
            // Opacity
            Vertices[i].Color.setAlpha((u8)(Opacity * 255.0f));
        }

        // Rendering
        NEngine::NCore::CGame::getVideoDriver()->setMaterial(Material);
        NEngine::NCore::CGame::getVideoDriver()->setTransform(video::ETS_VIEW, AbsoluteTransformation);
        NEngine::NCore::CGame::getVideoDriver()->drawIndexedTriangleList(Vertices, 4, Indices, 2);
        NEngine::NCore::CGame::getVideoDriver()->setTransform(video::ETS_WORLD, Mat);
    }
}

void CFlatElement::setSize(f32 w, f32 h)
{
    Size.Width = w;
    Size.Height = h;
}

void CFlatElement::setPosition(f32 x, f32 y)
{
    AbsoluteTransformation.setTranslation(core::vector3df(x/Coeff, y/Coeff, 0.0f));
}

void CFlatElement::setRotation(f32 value)
{
    value *= -1;
    AbsoluteTransformation.setRotationDegrees(core::vector3df(0.0f, 0.0f, value));
}

void CFlatElement::setTextureOffset(const core::vector2df& min, const core::vector2df& max)
{
    MinTextureOffset = min;
    MaxTextureOffset = max;
}

void CFlatElement::addX(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        AbsoluteTransformation.getTranslation().X + (val/Coeff),
        AbsoluteTransformation.getTranslation().Y,
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.X += val;
}

void CFlatElement::subX(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        AbsoluteTransformation.getTranslation().X - (val/Coeff),
        AbsoluteTransformation.getTranslation().Y,
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.X -= val;
}

void CFlatElement::setX(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        (val/Coeff),
        AbsoluteTransformation.getTranslation().Y,
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.X = val;
}

void CFlatElement::addY(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        AbsoluteTransformation.getTranslation().X,
        AbsoluteTransformation.getTranslation().Y + (val/Coeff),
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.Y += val;
}

void CFlatElement::subY(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        AbsoluteTransformation.getTranslation().X,
        AbsoluteTransformation.getTranslation().Y - (val/Coeff),
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.Y -= val;
}

void CFlatElement::setY(f32 val)
{
    AbsoluteTransformation.setTranslation(core::vector3df(
        AbsoluteTransformation.getTranslation().X,
        (val/Coeff),
        AbsoluteTransformation.getTranslation().Z
    ));
    //Position.Y = val;
}

void CFlatElement::setWidth(f32 val)
{
    Size.Width = val;
}

void CFlatElement::setHeight(f32 val)
{
    Size.Height = val;
}

f32 CFlatElement::getX()
{
    return AbsoluteTransformation.getTranslation().X;
}

f32 CFlatElement::getY()
{
    return AbsoluteTransformation.getTranslation().Y;
}

f32 CFlatElement::getWidth()
{
    return Size.Width;
}

f32 CFlatElement::getHeight()
{
    return Size.Height;
}

void CFlatElement::startUVAnimation(f32 uSpeed, f32 vSpeed)
{
    AnimSpeed.X = uSpeed;
    AnimSpeed.Y = vSpeed;
}

void CFlatElement::stopUVAnimation()
{
    AnimSpeed.X = 0.0f;
    AnimSpeed.Y = 0.0f;
}

void CFlatElement::hide()
{
    Visible = false;
}

void CFlatElement::show()
{
    Visible = true;
}

void CFlatElement::setOpacity(f32 value)
{
    Opacity = value;
}

void CFlatElement::addOpacity(f32 value)
{
    Opacity += value;
}

void CFlatElement::subOpacity(f32 value)
{
    Opacity -= value;
}

f32 CFlatElement::getOpacity()
{
    return Opacity;
}

void CFlatElement::diffuse(video::SColor color)
{
    Opacity = color.getAlpha();
    Material.DiffuseColor = color;
}

CFlatElement::~CFlatElement()
{
    Texture = NULL;
}

}}}
