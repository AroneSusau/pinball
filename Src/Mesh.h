#pragma once

#include "Common.h"
#include "Geometry.h"

#include "Collider.h"
#include "Material.h"
#include "RigidBody.h"
#include "Shader.h"
#include "Timer.h"
#include "Transform.h"

class Mesh
{
public:
	
	Mesh(Model* model, Material* material, Collider* collider, Timer* timer);
	Mesh(Model* model, TexturedMaterial* material, Collider* collider, Timer* timer);
	~Mesh();

	void Init();
	void Done();

	void Render();
	void Draw(Shader* shader);

	void Lock();
	void Unlock();

	void ApplyModel(Shader* shader);
	void ApplyMaterial(Shader* shader);

	Model* model;
	Material* material;

	Collider* collider;
	RigidBody* body;
	Transform* transform;

	bool locked;
};