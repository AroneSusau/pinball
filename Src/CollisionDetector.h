#pragma once

#include "Colliders.h"
#include "Common.h"

class CollisionDetector
{
public:

	//
	// UTILITY METHODS
	//

	static float MagnitudeSq(glm::vec3 v) {
		return powf(glm::length(v), 2);
	}

	static glm::vec3 GetMin(glm::vec3 position, glm::vec3 size) {
		glm::vec3 x1 = position + size.x;
		glm::vec3 x2 = position - size.x;

		glm::vec3 y1 = position + size.y;
		glm::vec3 y2 = position - size.y;

		glm::vec3 z1 = position + size.z;
		glm::vec3 z2 = position - size.z;

		return glm::vec3(fminf(x1.x, x2.x), fminf(y1.y, y2.y), fminf(z1.z, z2.z));
	}

	static glm::vec3 GetMax(glm::vec3 position, glm::vec3 size) {
		glm::vec3 x1 = position + size.x;
		glm::vec3 x2 = position - size.x;

		glm::vec3 y1 = position + size.y;
		glm::vec3 y2 = position - size.y;

		glm::vec3 z1 = position + size.z;
		glm::vec3 z2 = position - size.z;

		return glm::vec3(fmaxf(x1.x, x2.x), fmaxf(y1.y, y2.y), fmaxf(z1.z, z2.z));
	}
	
	static glm::vec3 ClosestPoint(AABBCollider* aabb, glm::vec3 point) {
		glm::vec3 result = point;
		glm::vec3 min = GetMin(aabb->Position, aabb->SizeVector3());
		glm::vec3 max = GetMax(aabb->Position, aabb->SizeVector3());

		result.x = (result.x < min.x) ? min.x : result.x;
		result.y = (result.y < min.y) ? min.y : result.y;
		result.z = (result.z < min.z) ? min.z : result.z;

		result.x = (result.x > max.x) ? max.x : result.x;
		result.y = (result.y > max.y) ? max.y : result.y;
		result.z = (result.z > max.z) ? max.z : result.z;

		return result;
	}

	static glm::vec3 ClosestPoint(OBBCollider* obb, glm::vec3 point) {
		glm::vec3 result = obb->Position;
		glm::vec3 dir = point - obb->Position;
		std::vector<float> sizeList = obb->SizeList();

		for (int i = 0; i < 3; ++i) {
			glm::vec3 axis(obb->Rotation[i][0], obb->Rotation[i][1], obb->Rotation[i][2]);

			float distance = glm::dot(dir, axis);

			if (distance > sizeList[i]) {
				distance = sizeList[i];
			}
			if (distance < -sizeList[i]) {
				distance = -sizeList[i];
			}

			result = result + (axis * distance);
		}

		return result;
	}

	//
	// SPHERE COLLISIONS
	//

	static bool Simulate(SphereCollider* a, SphereCollider* b)
	{	
		return abs(glm::length(a->GetPosition() - b->GetPosition())) < a->GetRadius() + b->GetRadius();
	}

	static bool Simulate(SphereCollider* a, AABBCollider* b)
	{
		glm::vec3 closestPoint = CollisionDetector::ClosestPoint(b, a->GetPosition());

		float distSq   = MagnitudeSq(a->GetPosition() - closestPoint);
		float radiusSq = a->GetRadius() * a->GetRadius();

		return distSq < radiusSq;
	}

	static bool Simulate(SphereCollider* a, OBBCollider* b)
	{
		glm::vec3 closestPoint = CollisionDetector::ClosestPoint(b, a->GetPosition());

		float distSq = MagnitudeSq(a->GetPosition() - closestPoint);
		float radiusSq = a->GetRadius() * a->GetRadius();
		
		return distSq < radiusSq;
	}

	//
	// AABB COLLISIONS
	//

	static bool Simulate(AABBCollider* a, SphereCollider* b)
	{
		return Simulate(b, a);
	}

	static bool Simulate(AABBCollider* a, AABBCollider* b)
	{
		glm::vec3 aMin = GetMin(a->Position, a->SizeVector3());
		glm::vec3 aMax = GetMax(a->Position, a->SizeVector3());

		glm::vec3 bMin = GetMin(b->Position, b->SizeVector3());
		glm::vec3 bMax = GetMax(b->Position, b->SizeVector3());

		return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
			   (aMin.y <= bMax.y && aMax.y >= bMin.y) &&
			   (aMin.z <= bMax.z && aMax.z >= bMin.z);
	}

	static bool Simulate(glm::vec3 aPos, glm::vec3 aSize, glm::vec3 bPos, glm::vec3 bSize)
	{
		glm::vec3 aMin = GetMin(aPos, aSize);
		glm::vec3 aMax = GetMax(aPos, aSize);

		glm::vec3 bMin = GetMin(bPos, bSize);
		glm::vec3 bMax = GetMax(bPos, bSize);

		return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
			   (aMin.y <= bMax.y && aMax.y >= bMin.y) &&
			   (aMin.z <= bMax.z && aMax.z >= bMin.z);
	}

	//
	// OBB Collisions
	//

	static bool Simulate(OBBCollider* a, SphereCollider* b)
	{
		return Simulate(b, a);
	}
};