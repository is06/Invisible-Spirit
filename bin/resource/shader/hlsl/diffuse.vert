/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

float4x4 mWorldViewProj;
float4 vColor;

struct VS_OUTPUT
{
  float4 Position: POSITION0;
  float4 Diffuse: COLOR0;
  float2 TexCoord: TEXCOORD0;
};

VS_OUTPUT mainVS(in float4 vPosition: POSITION, in float2 texCoord: TEXCOORD0)
{
  VS_OUTPUT Output;

  Output.Position = mul(vPosition, mWorldViewProj);
  Output.Diffuse = vColor;
  Output.TexCoord = texCoord;

  return Output;
}
