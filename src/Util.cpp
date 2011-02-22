/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * Affiche une matrice Irrlicht dans la console
 */
void _matrix_print(const core::matrix4& mat, const core::stringc& name) {
  cout << "matrix (";
  cout << name.c_str();
  cout << ") {" << endl;
  cout << "  " << mat.pointer()[0] << " ; ";
    cout << mat.pointer()[1] << " ; ";
    cout << mat.pointer()[2] << " ; ";
    cout << mat.pointer()[3] << " ; " << endl;
  cout << "  " << mat.pointer()[4] << " ; ";
    cout << mat.pointer()[5] << " ; ";
    cout << mat.pointer()[6] << " ; ";
    cout << mat.pointer()[7] << " ; " << endl;
  cout << "  " << mat.pointer()[8] << " ; ";
    cout << mat.pointer()[9] << " ; ";
    cout << mat.pointer()[10] << " ; ";
    cout << mat.pointer()[11] << " ; " << endl;
  cout << "  " << mat.pointer()[12] << " ; ";
    cout << mat.pointer()[13] << " ; ";
    cout << mat.pointer()[14] << " ; ";
    cout << mat.pointer()[15] << " ; " << endl;
  cout << "}" << endl;
}

/**
 * Affiche une matrice tableau dans la console
 */
void _matrix_print(const f32* mat, const core::stringc& name) {
  cout << "matrix (";
  cout << name.c_str();
  cout << ") [" << endl;
  cout << "  " << mat[0] << " ; ";
    cout << mat[1] << " ; ";
    cout << mat[2] << " ; ";
    cout << mat[3] << " ; " << endl;
  cout << "  " << mat[4] << " ; ";
    cout << mat[5] << " ; ";
    cout << mat[6] << " ; ";
    cout << mat[7] << " ; " << endl;
  cout << "  " << mat[8] << " ; ";
    cout << mat[9] << " ; ";
    cout << mat[10] << " ; ";
    cout << mat[11] << " ; " << endl;
  cout << "  " << mat[12] << " ; ";
    cout << mat[13] << " ; ";
    cout << mat[14] << " ; ";
    cout << mat[15] << " ; " << endl;
  cout << "]" << endl;
}

/**
 * Affiche un vecteur3D Irrlicht dans la console
 */
void _vector_print(const core::vector3df& vec, const core::stringc& name) {
  cout << "vector (";
  cout << name.c_str();
  cout << ") { ";
  cout << vec.X << " ; " << vec.Y << " ; " << vec.Z << " }" << endl;
}

/**
 * Affiche un vecteur3D tableau dans la console
 */
void _vector_print(const f32* vec, const core::stringc& name) {
  cout << "vector (";
  cout << name.c_str();
  cout << ") [ ";
  cout << vec[0] << " ; " << vec[1] << " ; " << vec[2] << " ]" << endl;
}

/**
 *
 */
void _vector_array_print(const f32* vecArray, u32 size, const core::stringc& name) {
  cout << "vertex array [" << endl;
  for(u32 i = 0; i < size; i+=3) {
    cout << "  vertex { " << vecArray[i] << " ; " << vecArray[i+1] << " ; " << vecArray[i+2] << " }" << endl;
  }
  cout << "]" << endl;
}

/**
 * Affiche un quaternion Irrlicht dans la console
 */
void _quaternion_print(const core::quaternion& q, const core::stringc& name) {
  cout << "quaternion (";
  cout << name.c_str();
  cout << ") { ";
  cout << q.X << " ; " << q.Y << " ; " << q.Z << " ; " << q.W << " }" << endl;
}

void _position_print(const scene::ISceneNode* node, const core::stringc& name) {
  cout << "position (";
  cout << name.c_str();
  cout << ") { ";
  cout << node->getPosition().X << " ; ";
  cout << node->getPosition().Y << " ; ";
  cout << node->getPosition().Z << " }" << endl;
}

void _rotation_print(const scene::ISceneNode* node, const core::stringc& name) {
  cout << "rotation (";
  cout << name.c_str();
  cout << ") { ";
  cout << node->getRotation().X << " ; ";
  cout << node->getRotation().Y << " ; ";
  cout << node->getRotation().Z << " }" << endl;
}

void _scale_print(const scene::ISceneNode* node, const core::stringc& name) {
  cout << "scale (";
  cout << name.c_str();
  cout << ") { ";
  cout << node->getScale().X << " ; ";
  cout << node->getScale().Y << " ; ";
  cout << node->getScale().Z << " }" << endl;
}
