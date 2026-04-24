#version 330 core

uniform int uFlags;

in vec4 vColor;
in float vL;
uniform float uScale;
out vec4 FragColor;

uniform float dashSize = 10.0;
uniform float gapSize  = 5.0;

void main() {
  vec4 c = vColor;
  if ((uFlags & 1) != 0) {
    ivec2 p = ivec2(gl_FragCoord.xy);
    if (((p.x + p.y) & 1) == 0) {
      c.w = 0.0;
    }
  }
  if(((uFlags >> 1) & 1) != 0) {
    float pattern = dashSize + gapSize;
    float t = mod(vL / uScale, pattern);
    if (t > dashSize)
        c.w = 0.0;
  }
  FragColor = c;
}