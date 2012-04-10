/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

struct PS_OUTPUT
{
  float4 RGBColor : COLOR0;
};

sampler2D tex0;

PS_OUTPUT mainPS(in float2 TexCoord: TEXCOORD0, in float4 Position: POSITION, in float4 Diffuse: COLOR0) 
{ 
	PS_OUTPUT Output;

	float4 col = tex2D(tex0, TexCoord);
	
	Output.RGBColor = Diffuse * col;

	return Output;
}
