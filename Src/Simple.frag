#version 400

//***************************
//* * * DATA STRUCTURES * * *
//***************************

#define MAX_LIGHTS 100

struct Material {
    vec4 Ambient;
    vec4 Diffuse;
    vec4 Specular;
    float Shininess;
};

struct Light {
    vec4 Ambient;
    vec4 Diffuse;
    vec4 Specular;
    vec3 Position;
    vec3 Forward;

    float Constant;
    float Linear;
    float Quadratic;

    bool Active;
};

//********************
//* * * UNIFORMS * * *
//********************

uniform Material Colour;

uniform Light Directional;

uniform int   uLightCount;
uniform Light uLights[MAX_LIGHTS];

uniform vec3 uCameraForward;
uniform vec3 uCameraPosition;

uniform bool isCubeMap;

uniform bool  uReflection;
uniform float uReflectFactor;

uniform sampler2D uDiffuse;
uniform sampler2D uSpecular;
uniform sampler2D uShadows;

uniform samplerCube uCubeMap;

//**********************
//* * * SHADER I/O * * *
//**********************

in VertexData {
    vec3 Position;
    vec3 Normal;
    vec2 Texel;
    vec4 FragPosLightSpace;
} fs_in;

out vec4 FragColor;

//************************
//* * * SUB-ROUTINES * * *
//************************

subroutine Material SelectMaterial();

subroutine (SelectMaterial) Material FlatMaterial() {    
    return Colour;
}

subroutine (SelectMaterial) Material TexturedMaterial() {
    
    Material m;

    m.Diffuse   = texture(uDiffuse, fs_in.Texel);
    m.Ambient   = m.Diffuse;
    m.Specular  = texture(uSpecular, fs_in.Texel);
    m.Shininess = Colour.Shininess;
    
    return m;
}

subroutine uniform SelectMaterial uMaterial;

//****************************
//* * * SHADOW EQUATIONS * * *
//****************************

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(uShadows, projCoords.xy).r; 
    
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    
    // calculate bias (based on depth map resolution and slope)
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightDir = normalize(Directional.Position - fs_in.Position);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    
    // check whether current frag pos is in shadow
    float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;
    
    // PCF
    vec2 texelSize = 1.0 / textureSize(uShadows, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(uShadows, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }

    shadow /= 9.0;
    
    // keep the shadow at 0.0 when outside the far_plane region of the light's frustum.
    if(projCoords.z > 1.0)
        shadow = 0.0;
            
    return shadow;
}

//******************************
//* * * LIGHTING EQUATIONS * * *
//******************************

vec4 DirectionalLight(Light l, Material m, vec3 normal, vec3 position)
{
    // Ambient
    vec4 ambient = l.Ambient * m.Ambient;
  	
    // Diffuse
    vec3 L        = normalize(l.Position.xyz);
    float d       = max(dot(normal, L), 0.0);
    vec4 diffuse  =  l.Diffuse * m.Diffuse * d; 

    // Specular
    vec3 V        = normalize(uCameraPosition - position);

    // Blinn-Phong
    vec3 H        = normalize(L + V); 
    float s       = pow(max(dot(normal, H), 0.0), m.Shininess);
    vec4 specular = l.Specular * m.Specular * s;

    float shadow = ShadowCalculation(fs_in.FragPosLightSpace);                      
    vec4 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * m.Diffuse;

    return lighting;
}

vec4 PointLight(Light l, Material m, vec3 normal, vec3 position)
{
    // Ambient
    vec4 ambient = l.Ambient * m.Ambient;
  	
    // Diffuse
    vec3 L       = l.Position - fs_in.Position;
    float Ld     = length(L);
    float att    = min(1.0 / ((l.Constant) + (l.Linear * Ld) + ( l.Quadratic * Ld * Ld)), 1);
    
    L = normalize(L);

    float d      = max(dot(normal, L), 0.0);
    vec4 diffuse =  l.Diffuse * m.Diffuse * d; 

    // Specular
    vec3 V        = normalize(uCameraPosition - position);

    // Blinn-Phong
    vec3 H        = normalize(L + V); 
    float s       = pow(max(dot(normal, H), 0.0), m.Shininess);
    vec4 specular = l.Specular * m.Specular * s;
          
    vec4 lighting = att * (ambient + diffuse + specular);

    return lighting;
}

//******************************
//* * * LIGHTING EQUATIONS * * *
//******************************

vec4 EnvironmentReflection(vec3 position, vec3 normal)
{
    vec3 I = normalize(position -uCameraPosition);
    vec3 R = reflect(I, normalize(normal));
    return vec4(texture(uCubeMap, R).rgb, 1.0);
}

void main()
{
    Material m = uMaterial();

    if (isCubeMap)
    {
        FragColor = texture(uCubeMap, fs_in.Position);
    }
    else
    {
        FragColor = DirectionalLight(Directional, m, fs_in.Normal, fs_in.Position);

        for (int i = 0; i < uLightCount; i++) {
            if (uLights[i].Active)
            {
                FragColor += PointLight(uLights[i], m, fs_in.Normal, fs_in.Position);
            }
        }

        if (uReflection)
        {
            FragColor += EnvironmentReflection(fs_in.Position, fs_in.Normal) * uReflectFactor;
        }
    }
} 
