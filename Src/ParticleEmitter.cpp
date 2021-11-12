#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(
	glm::vec3 position,
	glm::vec3 velocity_min,
	glm::vec3 velocity_max,
	Material* color,
	float lifetime,
	float spawnWait,
	float spawnAmount,
	float spawnLifetime,
	Timer* timer,
	bool singleUse)
	: position(position)
	, lifetime(lifetime)
	, spawnTick(0)
	, spawnWait(spawnWait)
	, spawnAmount(spawnAmount)
	, spawnLifetime(spawnLifetime)
	, velocity_min(velocity_min)
	, velocity_max(velocity_max)
	, color(color)
	, isGenerating(false)
	, timer(timer)
	, singleUse(singleUse)
	, intervals(0)
{}

void ParticleEmitter::Tick()
{
	UpdateTimers();
	UpdateParticles();
}

void ParticleEmitter::UpdateTimers()
{
	lifetime -= timer->delta;
	spawnTick -= timer->delta;

	isGenerating = (lifetime > 0) && (!singleUse || (singleUse && intervals < 1));

	if (isGenerating && spawnTick <= 0)
	{
		for (int i = 0; i < spawnAmount; ++i)
		{
			Generate();
		}

		spawnTick = spawnWait;
		intervals++;
	}
}

void ParticleEmitter::UpdateParticles()
{
	for (int i = 0; i < particles.size(); ++i)
	{
		auto particle = particles.at(i);
		particle->Tick();

		if (particle->IsDone())
		{
			delete particle;
			particles.erase(particles.begin() + i);
		}
	}
}

void ParticleEmitter::Render(Shader* shader)
{
	glDisable(GL_CULL_FACE);

	for (auto particle : particles)
	{
		particle->Draw(shader);
	}

	glEnable(GL_CULL_FACE);
}

void ParticleEmitter::Generate()
{
	float interval_x = (rand() % 100) / 100.0f;
	float interval_y = (rand() % 100) / 100.0f;
	float interval_z = (rand() % 100) / 100.0f;

	float interval_s = (rand() % 100) / 100.0f;

	float vx = Lerp(velocity_min.x, velocity_max.x, interval_x);
	float vy = Lerp(velocity_min.y, velocity_max.y, interval_y);
	float vz = Lerp(velocity_min.z, velocity_max.z, interval_z);

	float size = Lerp(3, 10, interval_s);

	Particle* particle = new Particle(color, spawnLifetime, position, glm::vec3(vx, vy, vz), timer);

	particle->Init();
	particle->transform->Translate(position);
	particle->transform->Scale(glm::vec3(size));

	particle->transform->Yaw(vx);
	particle->transform->Pitch(vy);
	particle->transform->Roll(vz);

	particles.push_back(particle);
}

bool ParticleEmitter::IsDone()
{
	return !isGenerating && lifetime <= 0 && particles.size() == 0;
}