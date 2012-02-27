/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

uniform vec4 vColor;

void main(void) {
  gl_FrontColor = vColor;
  gl_Position = ftransform();
  gl_TexCoord[0] = gl_MultiTexCoord0;
}