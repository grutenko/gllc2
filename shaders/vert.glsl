#version 330 core

layout(location = 0) in vec2 aPos;      // p[2]
layout(location = 1) in vec2 aNormal;   // n[2], можно использовать для освещения
layout(location = 2) in vec2 aUV;       // uv[2], текстуры
layout(location = 3) in vec4 aColor;    // цвет

uniform mat4 uMVP;

out vec4 vColor;
out vec2 vUV;

void main()
{
    gl_Position = uMVP * vec4(aPos, 0.0, 1.0); // базовая 2D трансформация
    vColor = aColor;
    vUV = aUV;
}