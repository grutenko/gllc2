#version 330

/*
 * Copyright (C) 2026  Behdad Esfahbod
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */


/* Requires GLSL 3.30 or GLSL ES 3.00. */


/* Dilate a glyph vertex by half a pixel on screen.
 *
 * position:  object-space vertex position (modified in place)
 * texcoord:  em-space sample coordinates (modified in place)
 * normal:    object-space outward normal at this vertex
 * jac:       inverse of the 2x2 linear part of the em-to-object transform,
 *            stored row-major as (j00, j01, j10, j11).  Maps object-space
 *            displacements back to em-space for texcoord adjustment.
 *            For simple scaling with y-flip (the common case):
 *              em-to-object = [[s, 0], [0, -s]]
 *              jac = (1/s, 0, 0, -1/s)
 * m:         model-view-projection matrix
 * viewport:  viewport size in pixels
 */
void hb_gpu_dilate (inout vec2 position, inout vec2 texcoord,
		    vec2 normal, vec4 jac,
		    mat4 m, vec2 viewport)
{
  vec2 n = normalize (normal);

  vec4 clipPos = m * vec4 (position, 0.0, 1.0);
  vec4 clipN   = m * vec4 (n, 0.0, 0.0);

  float s = clipPos.w;
  float t = clipN.w;

  float u = (s * clipN.x - t * clipPos.x) * viewport.x;
  float v = (s * clipN.y - t * clipPos.y) * viewport.y;

  float s2 = s * s;
  float st = s * t;
  float uv = u * u + v * v;

  float denom = uv - st * st;
  float d = abs (denom) > 1.0 / 16777216.0
	  ? s2 * (st + sqrt (uv)) / denom
	  : 0.0;

  vec2 dPos = d * normal;
  position += dPos;
  texcoord += vec2 (dot (dPos, jac.xy), dot (dPos, jac.zw));
}


layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_normal;
layout(location = 2) in vec2 a_textureCoord;
layout(location = 3) in vec4 a_color;
layout(location = 4) in float a_thickness;
layout(location = 5) in float a_length;
layout(location = 6) in uint a_glyphLoc;

uniform int u_flags;
uniform mat4 u_modelViewProjection;
uniform vec2 u_viewportSize;
uniform float u_scale;
out vec4 v_color;
out float v_length;

float emPerPos = 2048.0f / 16.0f;

out vec2 v_texcoord;
flat out uint v_glyphLoc;

void main() {
        vec2 pos = a_pos;
        vec2 tex = a_textureCoord;
        vec4 jac = vec4 (emPerPos, 0.0, 0.0, -emPerPos);
        
  if ((u_flags & 8) != 0) {
        //hb_gpu_dilate (pos, tex, a_normal, jac, u_modelViewProjection, u_viewportSize);
  }
  vec4 p = u_modelViewProjection * vec4(pos, 0.0, 1.0);
  vec2 pixelToNdc = vec2(2.0) / u_viewportSize;
  vec2 n = a_normal;
  if (a_normal.x != 0.0 && a_normal.y != 0.0) {
    n = normalize(n);
  }
  vec2 offset = n * a_thickness * pixelToNdc;
  gl_Position = vec4(p.xy + offset * p.w, p.z, p.w);
  v_color = a_color;
  v_length = a_length;
  v_texcoord = tex;
  v_glyphLoc = a_glyphLoc;
}