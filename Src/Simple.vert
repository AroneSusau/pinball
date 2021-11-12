#version 400

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexel;

uniform mat4 uProjection;
uniform mat4 uView;
uniform mat4 uModel;

uniform mat4 uLightSpaceMatrix;

uniform bool isCubeMap;

out VertexData {
    vec3 Position;
    vec3 Normal;
    vec2 Texel;
    vec4 FragPosLightSpace;
} vs_out;

void main()
{
    if (isCubeMap) 
    {
        vs_out.Position = aPosition;
        gl_Position = (uProjection * uView * vec4(aPosition, 1.0)).xyww;
    } 
    else 
    {
        vec3 N  = normalize(transpose(inverse(mat3(uModel))) * aNormal);
        vec4 mF = uModel * vec4(aPosition, 1.0);

        gl_Position = uProjection * uView * mF;    

        vs_out.Position = vec3(mF);
        vs_out.Normal   = N;
        vs_out.Texel    = aTexel;

        vs_out.FragPosLightSpace = uLightSpaceMatrix * vec4(vs_out.Position, 1.0);
    }
}
