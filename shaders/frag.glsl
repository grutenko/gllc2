#version 330 core

uniform int uFlags;

in vec4 vColor;
out vec4 FragColor;

void main() {
  vec4 c = vColor;
  if ((uFlags & 1) != 0) {
    ivec2 p = ivec2(gl_FragCoord.xy);
    if (((p.x + p.y) & 1) == 0) {
      discard;
    }
  }
  FragColor = c;
}