/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

// This shader is from XEffect by Ahmed Hilali
// This is not the final shader program, the code is for study purpose only

void main()
{
  vec4 vInfo = gl_TexCoord[0];
  float depth = vInfo.z / vInfo.x;
  gl_FragColor = vec4(depth, depth * depth, 0.0, 0.0);
}