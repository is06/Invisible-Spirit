/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
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
