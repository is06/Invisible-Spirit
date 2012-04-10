/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

// This shader is from XEffect by Ahmed Hilali
// This is not the final shader program, the code is for study purpose only

uniform float MaxD;

void main()
{
  vec4 tPos = mWorldViewProj * gl_Vertex;
  gl_Position = tPos;
  gl_TexCoord[0] = vec4(MaxD, tPos.y, tPos.z, tPos.w);

  gl_TexCoord[1].xy = gl_MultiTexCoord0.xy;
}