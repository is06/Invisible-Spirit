/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

uniform sampler2D blurSampler; 
const float blurSize = 1.0 / 512.0;
const float blurScale = 0.003;
 
void main(void)
{
  vec2 offsets[8] = vec2[](
    vec2(0, -4),
		vec2(0, -3),
		vec2(0, -2),
		vec2(0, -1),
		vec2(0, 1),
		vec2(0, 2),
		vec2(0, 3),
		vec2(0, 4)
  );

  vec4 sum = texture2D(blurSampler, gl_TexCoord[0].st + blurScale * vec2(0, 0));
  
  int i = 0;
  for (i = 0; i < 8; i++) {
    sum += texture2D(blurSampler, gl_TexCoord[0].st + blurScale * offsets[i]);
  } 
  
  gl_FragColor = sum / 9;
}
