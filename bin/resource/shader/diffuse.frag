uniform sampler2D T0;

void main(void) {
  vec4 col = texture2D(T0, gl_TexCoord[0].st);
  gl_FragColor = col * gl_Color;
}