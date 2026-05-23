#version 330 core

uniform int uFlags;

in vec4 vColor;
in float vL;
out vec4 FragColor;

uniform float dashSize = 5.0;
uniform float gapSize  = 2.0;
uniform float uScale;
uniform vec4 uClearColor;

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
        c = uClearColor;
  }
  FragColor = c;
}