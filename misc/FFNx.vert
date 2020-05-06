$input a_position, a_color0, a_texcoord0
$output v_color0, v_texcoord0

#include <bgfx/bgfx_shader.sh>

uniform mat4 d3dViewport;
uniform mat4 d3dProjection;

uniform vec4 VSFlags;
#define isTLVertex VSFlags.x > 0.0
#define blendMode VSFlags.y
#define isFBTexture VSFlags.z > 0.0

void main()
{
	vec4 pos = a_position;
    vec4 color = a_color0;
    vec2 coords = a_texcoord0;

    color.rgba = color.bgra;

    if (isTLVertex)
    {
        pos.w = 1.0 / pos.w;
        pos.xyz *= pos.w;
        pos = mul(u_proj, pos);
    }
    else
    {
        pos = mul(d3dViewport, pos);
        pos = mul(d3dProjection, pos);
        pos = mul(u_modelView, pos);

        if (color.a > 0.5) color.a = 0.5;
    }

    if (blendMode == 4.0) color.a = 1.0;
    else if (blendMode == 3.0) color.a = 0.25;

    if (isFBTexture) coords.t = 1.0 - coords.t;

    gl_Position = pos;
    v_color0 = color;
    v_texcoord0 = coords;
}

