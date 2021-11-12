#include "Cuboid.h"
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>

template <> void Cuboid<OBBCollider>::UpdateState(Timer* clock)
{
    auto matrix = transform->GetMatrix();
    auto rotation = transform->GetRotationMatrix();

    collider->SetPosition(glm::vec3(matrix[3]));
    collider->SetRotation(rotation);
}

template <> void Cuboid<AABBCollider>::UpdateState(Timer* clock)
{
    collider->SetPosition(transform->GetPosition());
}

template <> void Cuboid<AABBCollider>::SetUV(std::vector<glm::vec2> uv)
{
    Cube* cube = (Cube*) model;

    cube->uv = uv;
}

template<class C>
void Cuboid<C>::SetParent(Cuboid<C>* parent)
{
    if (parent == this)
        return;

    Parent = parent;
    transform->SetParent(Parent->transform);
}

template <> void Cuboid<OBBCollider>::SetUV(std::vector<glm::vec2> uv)
{
    Cube* cube = (Cube*)model;

    cube->uv = uv;
}

template <> void Cuboid<OBBCollider>::SetParent(Cuboid<OBBCollider>* parent)
{
    if (parent == this)
        return;

    Parent = parent;
    transform->SetParent(Parent->transform);
}
