/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_UTIL_H__
#define __IS06_UTIL_H__

using namespace irr;

void _matrix_print(const core::matrix4& mat, const core::stringc& name = "");
void _matrix_print(const f32* mat, const core::stringc& name = "");
void _vector_print(const core::vector3df& vec, const core::stringc& name = "");
void _vector_print(const f32* vec, const core::stringc& name = "");
void _vector_array_print(const f32* vecArray, u32 size, const core::stringc& name = "");
void _quaternion_print(const core::quaternion& q, const core::stringc& name = "");

void _position_print(const scene::ISceneNode* node, const core::stringc& name = "");
void _rotation_print(const scene::ISceneNode* node, const core::stringc& name = "");
void _scale_print(const scene::ISceneNode* node, const core::stringc& name = "");

#endif
