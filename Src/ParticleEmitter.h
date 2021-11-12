#pragma once

#include "Timer.h"
#include "Common.h"

#include "Particle.h"
#include "Shader.h"

class ParticleEmitter
{
public:

	ParticleEmitter(
		glm::vec3 position, 
		glm::vec3 velocity_min, 
		glm::vec3 velocity_max, 
		
		Material* color,

		float lifetime, 

		float spawnWait, 
		float spawnAmount, 
		float spawnLifetime,

		Timer* timer,
		bool singleUse = false
	);

	void Tick();
	void Generate();

	void UpdateTimers();
	void UpdateParticles();

	void Render(Shader* shader);

	bool IsDone();

	std::vector<Particle*> particles;

	Timer* timer;

	glm::vec3 position;

	glm::vec3 velocity_min;
	glm::vec3 velocity_max;

	Material* color;

	float lifetime;

	float spawnTick;
	float spawnWait;
	float spawnAmount;
	float spawnLifetime;

	int intervals;

	bool isGenerating;
	bool singleUse;
};