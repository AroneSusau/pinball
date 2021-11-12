#include "Mesh.h"

Mesh::Mesh(Model* model, Material* material, Collider* collider, Timer* timer)
	: model(model)
	, material(material)
	, collider(collider)
	, body(new RigidBody(timer))
	, transform(new Transform())
{}

Mesh::Mesh(Model* model, TexturedMaterial* material, Collider* collider, Timer* timer)
	: model(model)
	, material(material)
	, collider(collider)
	, body(new RigidBody(timer))
	, transform(new Transform())
{}

Mesh::~Mesh()
{
	delete model;
	delete collider;
	delete body;
	delete transform;
}

void Mesh::Init()
{
	model->Init();
}

void Mesh::Done()
{}

void Mesh::Lock()
{
	locked = true;
}

void Mesh::Unlock()
{
	locked = false;
}

void Mesh::Render()
{
	Lock();
	glBindVertexArray(model->GetVAO());
	glDrawArrays(GL_TRIANGLES, 0, model->GetSize());
	Unlock();
}

void Mesh::Draw(Shader* shader)
{
	ApplyModel(shader);
	ApplyMaterial(shader);
	Render();
}

void Mesh::ApplyModel(Shader* shader)
{
	shader->setMat4("uModel", transform->GetMatrix());
}

void Mesh::ApplyMaterial(Shader* shader)
{
	material->Apply(shader);
}
