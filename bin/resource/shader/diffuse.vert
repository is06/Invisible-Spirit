uniform vec4 vColor;

void main(void) {
  gl_FrontColor = vColor;
  gl_Position = ftransform();
  gl_TexCoord[0] = gl_MultiTexCoord0;
}