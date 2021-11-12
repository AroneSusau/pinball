#pragma once

#include "Common.h"

#include "Ball.h"
#include "Cuboid.h"
#include "Peg.h"
#include "Bumper.h"

#include "ParticleEmitter.h"
#include "Timer.h"

#include "Light.h"

#include "CollisionDetector.h"

struct Collision
{
    glm::vec3 position;

    glm::vec3 normal;
    glm::vec3 tangent;
    glm::vec3 reflection;

    float lifetime = 3.0f;

    Collision(
        glm::vec3 position,
        glm::vec3 normal,
        glm::vec3 tangent,
        glm::vec3 reflection
    ) 
        : position(position)
        , normal(normal)
        , tangent(tangent)
        , reflection(reflection)
    {};

    void Update(float delta) 
    {
        lifetime -= delta;
    };

    bool IsDone()
    {
        return this->lifetime <= 0;
    };
};

class PhysicsEngine
{
public:

    static float Clamp(float dimension, float closest);

    static glm::vec3 Reflect(glm::vec3 direction, glm::vec3 normal);

    static glm::vec3 BoxNormals(glm::vec3 dimensions, glm::vec3 closest);

    static void ball2ball_collision(std::vector<Light*>& lights, std::vector<Collision*>& collisions, std::vector<ParticleEmitter*>& emitters, Ball* b1, Ball* b2, Timer* timer);
    static void ball2ball_reposition(Ball* b1, Ball* b2);

    static void ball2box_collision(std::vector<Collision*>& collisions, Ball* b1, Cuboid<AABBCollider>* c2);
    static void ball2box_reposition(Ball* b1, Cuboid<AABBCollider>* c2);

    static void ball2box_collision(Ball* b1, Cuboid<OBBCollider>* c2);
    static void ball2box_reposition(Ball* b1, Cuboid<OBBCollider>* c2);

    static void ball2peg_collision(Ball* b1, Peg* c2);
    static void ball2peg_reposition(Ball* b1, Peg* c2);

    static void ball2bumper_collision(Ball* b1, Bumper* c2);
    static void ball2bumper_reposition(Ball* b1, Bumper* c2);

    static void ball2wall_collision(Ball* ball, float dimension);

    static void DrawCollisions(std::vector<Collision*> &collisions, glm::mat4 projection, glm::mat4 view);

};