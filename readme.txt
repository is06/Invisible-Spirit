### Invisible Spirit - Code Source version 0.1-110123-1 ###

OpenGL est nécessaire pour compiler et exécuter Invisible Spirit.

Pour compiler le projet, deux méthodes :

1. Utiliser CMake

  Définir les variables suivantes dans CMakeCache.txt

    bullet_include_dir:STATIC=/chemin/vers/include/bullet
    bullet_lib_dir:STATIC=/chemin/vers/lib/bullet
    irrlicht_include_dir:STATIC=/chemin/vers/include/irrlicht
    irrlicht_lib_dir:STATIC=/chemin/vers/lib/irrlicht

  Exemple (Code::Blocks - MinGW, Windows)

    bullet_include_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/include/bullet
    bullet_lib_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/lib/bullet
    irrlicht_include_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/include/irrlicht
    irrlicht_lib_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/lib/irrlicht

  Autre exemple (Linux)

    bullet_include_dir:STATIC=/usr/include/bullet/
    bullet_lib_dir:STATIC=/usr/lib/bullet/
    irrlicht_include_dir:STATIC=/usr/include/irrlicht/
    irrlicht_lib_dir:STATIC=/usr/lib/irrlicht/

2. Compiler manuellement.

  Les bibliothèques nécessaires sont (l'ordre est important pour Bullet) :

  - libIrrlicht
  - libBulletDynamics
  - libBulletCollision
  - libLinearMath

  Sous Linux :

  - lXxf86vm
  - GL

En cas de problème : http://www.is06.com/contact.php
