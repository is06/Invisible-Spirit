/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

// This shader is from XEffect by Ahmed Hilali
// This is not the final shader program, the code is for study purpose only

struct VS_OUTPUT
{
  vec4 Position;
  vec4 ShadowMapSamplingPos;
  vec4 MVar;
};

uniform float MaxD, MAPRES;
uniform vec3 LightPos;
uniform mat4 mWorldViewProj;
uniform mat4 mWorldViewProj2;

VS_OUTPUT vertexMain(in vec3 Position)
{
  VS_OUTPUT OUT;

  OUT.Position = (mWorldViewProj * vec4(Position.x, Position.y, Position.z, 1.0));
  OUT.ShadowMapSamplingPos = (mWorldViewProj2 * vec4(Position.x, Position.y, Position.z, 1.0));

  vec3 lightDir = normalize(LightPos - Position);

  OUT.MVar.x = OUT.ShadowMapSamplingPos.z;
  OUT.MVar.y = dot(normalize(gl_Normal.xyz), lightDir);
  OUT.MVar.z = MaxD;
  OUT.MVar.w = 1.0 / MAPRES;

  return OUT;
}

void main()
{
  VS_OUTPUT vOut = vertexMain(gl_Vertex.xyz);

  gl_Position = vOut.Position;
  gl_TexCoord[0] = vOut.ShadowMapSamplingPos;
  gl_TexCoord[1] = vOut.MVar;
}