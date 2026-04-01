#version 330 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aNormal;
layout(location = 2) in vec2 aUV;
layout(location = 3) in vec4 aColor;
layout(location = 4) in uint aThickness;

uniform mat4 uMVP;
uniform vec2 uViewportSize;
out vec4 vColor;
out vec2 vUV;

void main()
{
    vec4 p = uMVP * vec4(aPos, 0.0, 1.0);
    vec2 pixelToNdc = vec2(1.0) / uViewportSize;
    vec2 n = normalize(aNormal);
    n.y = -n.y;
    vec2 offset = n * float(aThickness) * pixelToNdc;
    gl_Position = vec4(p.xy + offset * p.w, p.z, p.w);
    vColor = aColor;
    vUV = aUV;
}