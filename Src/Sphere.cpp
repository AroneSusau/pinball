#include "Sphere.h"

Sphere::Sphere(float radius, float sectors, float stacks)
	: radius(radius)
	, sectors(sectors)
	, stacks(stacks)
{}

void Sphere::Generate()
{
    float x, y, z, xy;
    float nx, ny, nz, lengthInv = 1.0f / radius;
    float u, vt;

    float sectorStep = 2.0f * M_PI / sectors;
    float stackStep = M_PI / stacks;
    float sectorAngle, stackAngle;

    std::vector<int> indices;
    std::vector<glm::vec3> v;
    std::vector<glm::vec3> n;
    std::vector<glm::vec2> t;

    for (int i = 0; i <= stacks; ++i)
    {
        stackAngle = M_PI / 2.0f - i * stackStep;
        xy = radius * cosf(stackAngle);
        z = radius * sinf(stackAngle);

        for (int j = 0; j <= sectors; ++j)
        {
            sectorAngle = j * sectorStep;

            x = xy * cosf(sectorAngle);
            y = xy * sinf(sectorAngle);
           
            u = (float) j / sectors;
            vt = (float) i / stacks;

            v.push_back(glm::vec3(x, y, z));
            n.push_back(glm::normalize(glm::vec3(x, y, z)));
            t.push_back(glm::vec2(u, vt));
        }
    }

    int k1, k2;
    for (int i = 0; i < stacks; ++i)
    {
        k1 = i * (stacks + 1);
        k2 = k1 + stacks + 1; 

        for (int j = 0; j < sectors; ++j, ++k1, ++k2)
        {

            if (i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            if (i != (stacks - 1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    for (int i : indices)
    {
        vertices.push_back(v[i]);
        normals.push_back(n[i]);
        texels.push_back(t[i]);
    }
}
