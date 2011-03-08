uniform sampler2D T0;

void main(void) {  
  vec2 offsets[12] = vec2[](
    vec2( -0.326212, -0.405805 ),
    vec2( -0.840144, -0.073580 ),
    vec2( -0.695914,  0.457137 ),
    vec2( -0.203345,  0.620716 ),
    vec2(  0.962340, -0.194983 ),
    vec2(  0.473434, -0.480026 ),
    vec2(  0.519456,  0.767022 ),
    vec2(  0.185461, -0.893124 ),
    vec2(  0.507431,  0.064425 ),
    vec2(  0.896420,  0.412458 ),
    vec2( -0.321940, -0.932615 ),
    vec2( -0.791559, -0.597705 )
  );

  const float BlurScale = 0.01;

  vec4 sum = texture2D(T0, gl_TexCoord[0].st);
  
  int i = 0;
  for( i = 0; i < 12; i++ ) {
    sum += texture2D(T0, gl_TexCoord[0].st + BlurScale * offsets[i] );
  } 
  
  gl_FragColor = sum / 10;
}
