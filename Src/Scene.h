#pragma once

#include "Common.h"
#include "Colliders.h"
#include "Geometry.h"

#include "Camera.h"
#include "CollisionDetector.h"
#include "CommonTextures.h"
#include "CubeMap.h"
#include "Timer.h"
#include "Material.h"
#include "Mesh.h"
#include "Light.h"
#include "Texture.h"
#include "PhysicsEngine.h"
#include "Setup.h"

#include "Octree.h"

#include "OmniBuffer.h"

#include "Ball.h"
#include "Cuboid.h"
#include "Peg.h"
#include "Bumper.h"

#include "ParticleEmitter.h"

enum class Hidden_Buffer
{
	SHADOW_BUFFER,
	BLOOM_BUFFER,
	DEFAULT_BUFFER,
};

class Scene
{
public:
	Scene(const char* root, float width, float height, Timer* timer);
	~Scene();

	void Tick();

	void Init();
	void InitUniforms();
	void InitFrame(float width, float height, unsigned int buffer);

	void InitShadows();

	void Done();

	void Render(Shader* shader);

	void RenderDefaultBuffer();
	void RenderShadowBuffer();

	void UpdateState(Timer* clock);
	void UpdateLights();
	void UpdatePaddles();
	void UpdateEmitters();
	void UpdateBumpers();

	void BallsCollisions(Ball* ball);
	void StaticCollisions(Ball* ball);

	void GenerateVolatileTree();

	void ValidateBalls(Ball* ball, int index);

	void Debug();

	void KeyPress(SDL_Event e);
	void KeyDown(SDL_Event e);
	void KeyUp(SDL_Event e);

	void UpdateCollisions(Timer* clock);
	void UpdateLaunch();

	std::string BufferToString();
	std::string ActiveToString(bool param);

	Shader* shader;
	Shader* depthShader;

	CommonTextures textures;

	Camera* camera;
	Timer* timer;

	std::vector<Ball*> balls;
	std::vector<Cuboid<OBBCollider>*> cuboids;
	
	std::vector<Peg*> pegs;
	std::vector<Bumper*> bumpers;

	std::vector<Collision*> collisions;
	std::vector<ParticleEmitter*> emitters;

	CubeMap* cubemap;

	Octree* volatile_tree;

	Light* directional;

	std::vector<Light*> lights;

	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	unsigned int depthMapFBO;
	unsigned int depthMap;

	float width;
	float height;

	float launchPower   = 0.0f;

	bool running        = true;
	
	bool displayHud     = false;

	bool collisionDebug = false;
	bool colliderDebug  = false;
	bool volatileDebug  = false;
	bool lightDebug     = false;
	bool velocityDebug  = false;

	bool slowmo         = false;
	bool bruteforce     = false;

	float LeftPaddleYaw  = 0.0f;
	float RightPaddleYaw = 0.0f;

	bool LeftPaddleSwing = false;
	bool RightPaddleSwing = false;

	Hidden_Buffer framebuffer = Hidden_Buffer::DEFAULT_BUFFER;
};