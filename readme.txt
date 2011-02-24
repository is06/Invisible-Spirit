### Invisible Spirit - Code Source version 0.1-110123-1 ###

OpenGL est nécessaire pour compiler et exécuter Invisible Spirit.

Pour compiler le projet, deux méthodes :

1. Utiliser CMake

  Définir les variables suivantes dans CMakeCache.txt

    newton_include_dir:STATIC=/chemin/vers/include/newton
    newton_lib_dir:STATIC=/chemin/vers/lib/newton
    irrlicht_include_dir:STATIC=/chemin/vers/include/irrlicht
    irrlicht_lib_dir:STATIC=/chemin/vers/lib/irrlicht

  Exemple (Code::Blocks - MinGW, Windows)

    newton_include_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/include/newton
    newton_lib_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/lib/newton
    irrlicht_include_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/include/irrlicht
    irrlicht_lib_dir:STATIC=C:/Program Files/CodeBlocks/MinGW/lib/irrlicht

  Autre exemple (Linux)

    newton_include_dir:STATIC=/usr/include/newton/
    newton_lib_dir:STATIC=/usr/lib/newton/
    irrlicht_include_dir:STATIC=/usr/include/irrlicht/
    irrlicht_lib_dir:STATIC=/usr/lib/irrlicht/

2. Compiler manuellement.

  Les bibliothèques nécessaires sont :

  - Newton
  - Irrlicht

  Sous Linux :

  - Xxf86vm
  - GL

En cas de problème : http://www.is06.com/contact.php
