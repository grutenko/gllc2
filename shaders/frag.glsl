#version 330 core

uniform int uFlags;

in vec4 vColor;
in float vL;
out vec4 FragColor;

uniform float dashSize = 10.0;
uniform float gapSize  = 5.0;
uniform float uScale;
uniform vec4 uClearColor;

void main() {
  vec4 c = vColor;
  if ((uFlags & 1) != 0) {
    ivec2 p = ivec2(gl_FragCoord.xy);
    float size = 5.0;
    float thickness = 1.0;

    float d1 = mod(p.x + p.y, size);
    float d2 = mod(p.x - p.y, size);

    if (d1 < thickness || d2 < thickness) {
      //
    } else {
      c = uClearColor;
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