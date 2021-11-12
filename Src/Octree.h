#pragma once

#include "Common.h"

#include "PhysicsEngine.h"
#include "CollisionDetector.h"

#include "ParticleEmitter.h"
#include "Timer.h"

#include "Light.h"
#include "Ball.h"

#define DEFAULT_OCTREE_SIZE     glm::vec3(3000.0f)
#define DEFAULT_OCTREE_POSITION glm::vec3(0.0f)

#define OCT_MAX_CHILDREN 2
#define OCT_MIN_SIZE     100.0f * OCT_MAX_CHILDREN

enum class octree_child
{
	TOP_FRONT_LEFT,
	TOP_FRONT_RIGHT,
	TOP_BACK_LEFT,
	TOP_BACK_RIGHT,

	BOTTOM_FRONT_LEFT,
	BOTTOM_FRONT_RIGHT,
	BOTTOM_BACK_LEFT,
	BOTTOM_BACK_RIGHT,
};

class Octree {


public:	
	
	Octree(glm::vec3 position = DEFAULT_OCTREE_POSITION, glm::vec3 size = DEFAULT_OCTREE_SIZE)
		: Position(position)
		, Size(size)
		, Depth(0)
	{}

	Octree(Ball* ball, glm::vec3 position, glm::vec3 size, float depth)
		: Position(position)
		, Size(size)
		, Depth(depth + 1)
	{
		Insert(ball->transform->GetPosition(), glm::vec3(ball->collider->GetRadius()), ball);
	}
	
	~Octree() 
	{
		for (auto child : Children)
			delete child;
	}

	void Insert(glm::vec3 position, glm::vec3 size, Ball* ball)
	{
		bool collides = CollisionDetector::Simulate(Position, Size, position, size);
		bool isFull   = IsFull();
		bool expanded = HasExpanded();
		
		if (collides && !isFull || MinSizeReached(ball))
		{
			Data.push_back(ball);
		}
		else if (collides && isFull && !expanded)
		{
			Expand(ball);

			for (auto data : Data)
				for (auto child: Children)
					child->Insert(position, size, data);
		}
		else if (collides && isFull && expanded)
		{
			for (auto child : Children)
				child->Insert(position, size, ball);
		}
	}

	void Search(std::vector<Light*>& lights, std::vector<Collision*> &collisions, std::vector<ParticleEmitter*>& emitters, std::unordered_set<Ball*> &reference, Ball* ball, Timer* timer)
	{
		auto position = ball->transform->GetPosition();
		auto size	  = glm::vec3(ball->collider->GetRadius());		

		bool collides = CollisionDetector::Simulate(Position, Size, position, size);
		bool expanded = HasExpanded();

		if (collides && expanded)
		{
			for (auto child : Children)
				if (child->GetSize() > 0)
					child->Search(lights, collisions, emitters, reference, ball, timer);
		}
		else if (collides && !expanded)
		{
			for (auto data : Data)
			{
				if (ball != data && !reference.count(data))
				{
					reference.insert(data);
					Test(lights, collisions, emitters, ball, data, timer);
				}
			}
		}
	}

	void Test(std::vector<Light*>& lights, std::vector<Collision*> &collisions, std::vector<ParticleEmitter*>& emitters, Ball* b1, Ball* b2, Timer* timer)
	{
		if (CollisionDetector::Simulate(b1->collider, b2->collider))
		{
			PhysicsEngine::ball2ball_reposition(b1, b2);
			PhysicsEngine::ball2ball_collision(lights, collisions, emitters, b1, b2, timer);
		}
	}

	void Expand(Ball* ball)
	{
		glm::vec3 size  = Size / 2.0f;
		float dimension = size.x;

		Children.insert(Children.begin(),
		{
			new Octree(ball, GetChildPosition(dimension, octree_child::TOP_FRONT_LEFT),     size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::TOP_FRONT_RIGHT),    size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::TOP_BACK_LEFT),      size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::TOP_BACK_RIGHT),     size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::BOTTOM_FRONT_LEFT),  size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::BOTTOM_FRONT_RIGHT), size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::BOTTOM_BACK_LEFT),   size, Depth),
			new Octree(ball, GetChildPosition(dimension, octree_child::BOTTOM_BACK_RIGHT),  size, Depth),
		});
	}

	glm::vec3 GetChildPosition(float dimension, octree_child which)
	{
		glm::vec3 result = Position;

		switch (which)
		{
			case octree_child::TOP_FRONT_LEFT:
				result.x -= dimension;
				result.y += dimension;
				result.z += dimension;
				return result;
			case octree_child::TOP_FRONT_RIGHT:
				result.x += dimension;
				result.y += dimension;
				result.z += dimension;
				return result;
			case octree_child::TOP_BACK_LEFT:
				result.x -= dimension;
				result.y += dimension;
				result.z -= dimension;
				return result;
			case octree_child::TOP_BACK_RIGHT:
				result.x += dimension;
				result.y += dimension;
				result.z -= dimension;
				return result;

			case octree_child::BOTTOM_FRONT_LEFT:
				result.x -= dimension;
				result.y -= dimension;
				result.z += dimension;
				return result;
			case octree_child::BOTTOM_FRONT_RIGHT:
				result.x += dimension;
				result.y -= dimension;
				result.z += dimension;
				return result;
			case octree_child::BOTTOM_BACK_LEFT:
				result.x -= dimension;
				result.y -= dimension;
				result.z -= dimension;
				return result;
			case octree_child::BOTTOM_BACK_RIGHT:
				result.x += dimension;
				result.y -= dimension;
				result.z -= dimension;
				return result;
		};
	}

	int GetSize()
	{
		return Data.size();
	}

	bool MinSizeReached(Ball* ball)
	{
		return Size.x < OCT_MIN_SIZE;
	}

	bool IsFull()
	{
		return Data.size() >= OCT_MAX_CHILDREN;
	}

	bool HasExpanded()
	{
		return Children.size() > 0;
	}

	void Debug(glm::mat4 projection, glm::mat4 view)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(glm::value_ptr(projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view));

		glUseProgram(0);
		glDisable(GL_TEXTURE);

		glPushMatrix();

		glTranslatef(Position.x, Position.y, Position.z);
		glScalef(Size.x, Size.y, Size.z);

		if (Depth == 0)
		{
			glColor3f(0.0f, 0.0f, 1.0f);
		} 
		else if (Depth == 1)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else if (Depth == 2)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
		}
		else if (Depth > 2)
		{
			glColor3f(1.0f, 1.0f, Depth / 5.0f);
		}

		glBegin(GL_TRIANGLES);

		for (auto triangle : generic_cube)
		{
			glVertex3fv(glm::value_ptr(triangle));
		}

		glEnd();

		glPopMatrix();
		glEnable(GL_CULL_FACE);

		DataDebug(projection, view);

		for (auto child : Children)
			if (child->GetSize() > 0)
				child->Debug(projection, view);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	void DataDebug(glm::mat4 projection, glm::mat4 view)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(glm::value_ptr(projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view));

		glUseProgram(0);
		glDisable(GL_TEXTURE);


		for (auto data : Data)
		{
			glPushMatrix();

			auto position = data->transform->GetPosition();
			auto size     = data->collider->GetRadius();

			glTranslatef(position.x, position.y, position.z);
			glScalef(size, size, size);

			glColor3f(0.5f, 0.2f, 1.0f);

			glBegin(GL_TRIANGLES);

			for (auto triangle : generic_cube)
			{
				glVertex3fv(glm::value_ptr(triangle));
			}

			glEnd();

			glPopMatrix();
		}

		glEnable(GL_CULL_FACE);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

private:

	glm::vec3 Position;
	glm::vec3 Size;

	float Depth;

	std::vector<Ball*>   Data;
	std::vector<Octree*> Children;

};
