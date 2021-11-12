#include "Setup.h"

void Setup::Init(Timer* timer, std::vector<Ball*>& balls, std::vector<Cuboid<OBBCollider>*>& cuboids, std::vector<Peg*>& pegs, std::vector<Bumper*>& bumpers, std::vector<Light*>& lights)
{

	// * * * * * * * * * * * * * * // 
	// * * * * * CUBOIDS * * * * * //
	// * * * * * * * * * * * * * * //

	glm::vec3    scale;
	glm::vec3    position;
	glm::vec3    rotation;
	uv_list      uv;
	OBBCollider* collider;

	// * * * * * Floor * * * * * //

	scale = glm::vec3(1500.0f, 50.0f, 2000.0f);
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f, 20.0f, 0.0f);

	uv = { glm::vec2(1, 1), glm::vec2(1, 1), glm::vec2(2, 4) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Wood, collider);

	// * * * * * Right Wall * * * * * //

	scale = glm::vec3(50.0f, 150.0f, 2000.0f);
	position = glm::vec3(-1450.0f, -200.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.5, 3.2) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Left Lower Wall * * * * * //

	scale = glm::vec3(50.0f, 150.0f, 950.0f);
	position = glm::vec3(1450.0f, -200.0f, 1050.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.25), glm::vec2(10, 0.5), glm::vec2(0.5, 3) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Left Centre Wall * * * * * //

	scale = glm::vec3(50.0f, 75.0f, 100.0f);
	position = glm::vec3(1450.0f, -125.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.25), glm::vec2(10, 0.5), glm::vec2(0.5, 3) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Left Upper Wall * * * * * //

	scale = glm::vec3(50.0f, 150.0f, 950.0f);
	position = glm::vec3(1450.0f, -200.0f, -1050.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.25), glm::vec2(10, 0.5), glm::vec2(0.5, 3) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Top Wall * * * * * //

	scale = glm::vec3(1400.0f, 150.0f, 50.0f);
	position = glm::vec3(0.0f, -200.0f, -1950.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(6, 0.5), glm::vec2(0.5, 0.5), glm::vec2(3, 0.5) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Bottom Left Wall * * * * * //

	scale = glm::vec3(450.0f, 150.0f, 50.0f);
	position = glm::vec3(950.0f, -200.0f, 1950.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(6, 0.5), glm::vec2(0.5, 0.5), glm::vec2(3, 0.5) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Bottom Right Wall * * * * * //

	scale = glm::vec3(500.0f, 150.0f, 50.0f);
	position = glm::vec3(-900.0f, -200.0f, 1950.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(6, 0.5), glm::vec2(0.5, 0.5), glm::vec2(3, 0.5) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Bottom Left Guard * * * * * //

	scale = glm::vec3(500.0f, 140.0f, 50.0f);
	position = glm::vec3(1000.0f, -200.0f, 1550.0f);
	rotation = glm::vec3(20.0f, 0.0f, 0.0f);

	uv = { glm::vec2(6, 0.5), glm::vec2(0.5, 0.5), glm::vec2(3, 0.5) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Bottom Right Guard * * * * * //

	scale = glm::vec3(300.0f, 140.0f, 50.0f);
	position = glm::vec3(-800.0f, -200.0f, 1620.0f);
	rotation = glm::vec3(-20.0f, 0.0f, 0.0f);

	uv = { glm::vec2(6, 0.5), glm::vec2(0.5, 0.5), glm::vec2(3, 0.5) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Lane Divider * * * * * //

	scale = glm::vec3(50.0f, 150.0f, 1550.0f);
	position = glm::vec3(-1050.0f, -200.0f, 350.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.5, 3.2) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Left Lane Guard * * * * * //

	scale = glm::vec3(250.0f, 130.0f, 50.0f);
	position = glm::vec3(-1250.0f, -170.0f, -1800.0f);
	rotation = glm::vec3(45.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.1, 0.25) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Right Lane Guard * * * * * //

	scale = glm::vec3(250.0f, 130.0f, 50.0f);
	position = glm::vec3(1250.0f, -170.0f, -1800.0f);
	rotation = glm::vec3(-45.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.1, 0.25) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Bricks1, collider);

	// * * * * * Loop Parent * * * * * //

	scale = glm::vec3(1.0f);
	position = glm::vec3(700.0f, -1400.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, -90.0f);

	uv = { glm::vec2(1), glm::vec2(1), glm::vec2(1) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Marble, collider);

	Cuboid<OBBCollider>* loopParent = cuboids.back();

	// * * * * * Left Flipper Parent * * * * * //

	scale = glm::vec3(10.0f);
	position = glm::vec3(500.0f, -200.0f, 1745.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.1, 0.25) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Empty, collider);

	Cuboid<OBBCollider>* leftFlipperParent = cuboids.back();

	// * * * * * Right Flipper Parent * * * * * //

	scale = glm::vec3(10.0f);
	position = glm::vec3(-500.0f, -200.0f, 1745.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(0.25, 0.5), glm::vec2(10, 0.5), glm::vec2(0.1, 0.25) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Empty, collider);

	Cuboid<OBBCollider>* rightFlipperParent = cuboids.back();

	// * * * * * Append Parent * * * * * //

	for (auto cuboid : cuboids)
	{
		Timer* timer = new Timer();
		cuboid->SetParent(cuboids.at(0));
		cuboid->UpdateState(timer);
		delete timer;
	}

	// * * * * * Floor Loop * * * * * //

	float radius = 1350.0f;

	for (float i = 0; i < 90.0f; i += 3)
	{
		scale = glm::vec3(3.0f, 50.0f, 100.0f);
		position = glm::vec3(cosf(glm::radians(i)) * radius, -sinf(glm::radians(i)) * radius, 0.0f);
		rotation = glm::vec3(0.0f, 0.0f, -i);

		uv = { glm::vec2(1), glm::vec2(1), glm::vec2(1) };

		collider = new OBBCollider(position, scale);

		Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Marble, collider);

		cuboids.back()->SetParent(loopParent);
		cuboids.back()->UpdateState(timer);
	}

	// * * * * * Left Flipper * * * * * //

	scale = glm::vec3(200.0f, 145.0f, 50.0f);
	position = glm::vec3(200.0f, 0.0, 0.0);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(1, 1), glm::vec2(1, 1), glm::vec2(1, 1) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Marble, collider, 2.0);

	cuboids.back()->SetParent(leftFlipperParent);
	cuboids.back()->UpdateState(timer);

	// * * * * * Right Flipper * * * * * //

	scale = glm::vec3(200.0f, 145.0f, 50.0f);
	position = glm::vec3(-200.0f, 0.0, 0.0);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);

	uv = { glm::vec2(1, 1), glm::vec2(1, 1), glm::vec2(1, 1) };

	collider = new OBBCollider(position, scale);

	Setup::PushCuboid(timer, cuboids, scale, position, rotation, uv, CommonTextures::Marble, collider, 2.0);

	cuboids.back()->SetParent(rightFlipperParent);
	cuboids.back()->UpdateState(timer);

	// * * * * * * * * * * * * * // 
	// * * * * * LIGHTS  * * * * //
	// * * * * * * * * * * * * * //

	Light* light;
	View* view;

	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;

	glm::vec3 empty = glm::vec3(0.0);

	int       number;
	float     constant;
	float     linear;
	float     quadratic;

	// * * * * * Top Lane Light * * * * * //

	ambient = glm::vec4(0.2, 0.0, 0.0, 1.0);
	diffuse = glm::vec4(1.0, 0.0, 0.0, 1.0);
	specular = glm::vec4(1.0, 0.0, 0.0, 1.0);

	position = glm::vec3(-1250, -500, -1000);
	view = new View(position, empty, empty);

	number = 0;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	lights.push_back(light);

	// * * * * * Middle Lane Light * * * * * //

	ambient = glm::vec4(0.2, 0.0, 0.0, 1.0);
	diffuse = glm::vec4(1.0, 0.0, 0.0, 1.0);
	specular = glm::vec4(1.0, 0.0, 0.0, 1.0);

	position = glm::vec3(-1250, -500, 0);
	view = new View(position, empty, empty);

	number = 1;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	lights.push_back(light);

	// * * * * * Bottom Lane Light * * * * * //

	ambient = glm::vec4(0.2, 0.0, 0.0, 1.0);
	diffuse = glm::vec4(1.0, 0.0, 0.0, 1.0);
	specular = glm::vec4(1.0, 0.0, 0.0, 1.0);

	position = glm::vec3(-1250, -500, 1000);
	view = new View(position, empty, empty);

	number = 2;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	lights.push_back(light);

	// * * * * * Loop Light * * * * * //

	ambient = glm::vec4(0.0, 0.0, 0.2, 1.0);
	diffuse = glm::vec4(0.0, 0.0, 1.0, 1.0);
	specular = glm::vec4(0.0, 0.0, 1.0, 1.0);

	position = glm::vec4(500, -150, 0, 1.0f);
	view = new View(position, empty, empty);

	number = 3;
	constant = 0.0;
	linear = 0.005;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	lights.push_back(light);

	// * * * * * * * * * * * * // 
	// * * * * * PEGS  * * * * //
	// * * * * * * * * * * * * //

	Peg* peg;

	float magnetism;

	// * * * * * Top Middle Triangle * * * * * //

	magnetism = -75.0f;
	position = glm::vec3(0.0f, -200.0f, -400.0f);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(50.0f, 50.0f, 150.0f));

	ambient = glm::vec4(0.2, 0.2, 0.2, 1.0);
	diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0);
	specular = glm::vec4(1.0, 1.0, 1.0, 1.0);

	view = new View(position - glm::vec3(0, 150.0f, 0), empty, empty);

	number = 4;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	peg = new Peg(magnetism, CommonTextures::Dark_Marble, collider, cuboids.at(0)->transform, light, timer);

	peg->Init();
	peg->transform->Pitch(-90.0f);
	peg->transform->Translate(position);
	peg->transform->Scale(glm::vec3(50.0f, 50.0f, 150.0f));
	peg->Deactivate();

	collider->SetPosition(glm::vec3(peg->transform->GetMatrix()[3]));
	collider->SetRotation(peg->transform->GetRotationMatrix());

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	pegs.push_back(peg);
	lights.push_back(light);

	// * * * * * Top Left Triangle * * * * * //

	magnetism = 205.0f;
	position = glm::vec3(-500.0f, -200.0f, -900.0f);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(50.0f, 50.0f, 150.0f));

	ambient = glm::vec4(0.2, 0.2, 0.2, 1.0);
	diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0);
	specular = glm::vec4(1.0, 1.0, 1.0, 1.0);

	view = new View(position - glm::vec3(0, 150.0f, 0), empty, empty);

	number = 5;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	peg = new Peg(magnetism, CommonTextures::Metal, collider, cuboids.at(0)->transform, light, timer);

	peg->Init();
	peg->transform->Pitch(-90.0f);
	peg->transform->Translate(position);
	peg->transform->Scale(glm::vec3(50.0f, 50.0f, 150.0f));
	peg->Deactivate();

	collider->SetPosition(glm::vec3(peg->transform->GetMatrix()[3]));
	collider->SetRotation(peg->transform->GetRotationMatrix());

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	pegs.push_back(peg);
	lights.push_back(light);

	// * * * * * Top Right Triangle * * * * * //

	magnetism = 45.0f;
	position = glm::vec3(500.0f, -200.0f, -900.0f);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(50.0f, 50.0f, 150.0f));

	ambient = glm::vec4(0.2, 0.2, 0.2, 1.0);
	diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0);
	specular = glm::vec4(1.0, 1.0, 1.0, 1.0);

	view = new View(position - glm::vec3(0, 150.0f, 0), empty, empty);

	number = 6;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	peg = new Peg(magnetism, CommonTextures::Metal, collider, cuboids.at(0)->transform, light, timer);

	peg->Init();
	peg->transform->Pitch(-90.0f);
	peg->transform->Translate(position);
	peg->transform->Scale(glm::vec3(50.0f, 50.0f, 150.0f));
	peg->Deactivate();

	collider->SetPosition(glm::vec3(peg->transform->GetMatrix()[3]));
	collider->SetRotation(peg->transform->GetRotationMatrix());

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	pegs.push_back(peg);
	lights.push_back(light);

	// * * * * * Left Peg * * * * * //

	magnetism = -50.0f;
	position = glm::vec3(900.0f, -200.0f, 700.0f);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(50.0f, 50.0f, 150.0f));

	ambient = glm::vec4(0.2, 0.2, 0.2, 1.0);
	diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0);
	specular = glm::vec4(1.0, 1.0, 1.0, 1.0);

	view = new View(position - glm::vec3(0, 150.0f, 0), empty, empty);

	number = 7;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	peg = new Peg(magnetism, CommonTextures::Dark_Marble, collider, cuboids.at(0)->transform, light, timer);

	peg->Init();
	peg->transform->Pitch(-90.0f);
	peg->transform->Translate(position);
	peg->transform->Scale(glm::vec3(50.0f, 50.0f, 150.0f));
	peg->Deactivate();

	collider->SetPosition(glm::vec3(peg->transform->GetMatrix()[3]));
	collider->SetRotation(peg->transform->GetRotationMatrix());

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	pegs.push_back(peg);
	lights.push_back(light);

	// * * * * * Right Peg * * * * * //

	magnetism = -50.0f;
	position = glm::vec3(-700.0f, -200.0f, 700.0f);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(50.0f, 50.0f, 150.0f));

	ambient = glm::vec4(0.2, 0.2, 0.2, 1.0);
	diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0);
	specular = glm::vec4(1.0, 1.0, 1.0, 1.0);

	view = new View(position - glm::vec3(0, 150.0f, 0), empty, empty);

	number = 8;
	constant = 0.0;
	linear = 0.001;
	quadratic = 0.00001;

	light = new Light(ambient, diffuse, specular, view, number, constant, linear, quadratic);

	peg = new Peg(magnetism, CommonTextures::Dark_Marble, collider, cuboids.at(0)->transform, light, timer);

	peg->Init();
	peg->transform->Pitch(-90.0f);
	peg->transform->Translate(position);
	peg->transform->Scale(glm::vec3(50.0f, 50.0f, 150.0f));
	peg->Deactivate();

	collider->SetPosition(glm::vec3(peg->transform->GetMatrix()[3]));
	collider->SetRotation(peg->transform->GetRotationMatrix());

	light->SetParent(cuboids.at(0)->transform);
	light->UpdatePosition();

	pegs.push_back(peg);
	lights.push_back(light);

	// * * * * * * * * * * * * * // 
	// * * * * * BUMPERS * * * * //
	// * * * * * * * * * * * * * //

	Bumper* bumper;

	glm::vec3 start;
	glm::vec3 end;

	// * * * * * Top Bumper * * * * * //

	position = glm::vec3(0, -150, 300);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(100.0f, 100.0f, 200.0f));

	start = position - glm::vec3(0, 0, 300);
	end = position + glm::vec3(0, 0, 500);

	bumper = new Bumper(1.5f, 1, start, end, CommonTextures::Marble, collider, cuboids.at(0)->transform, timer);

	bumper->Init();
	bumper->transform->Pitch(90.0f);
	bumper->transform->Translate(position);
	bumper->transform->Scale(glm::vec3(100.0f, 100.0f, 200.0f));

	collider->SetPosition(glm::vec3(bumper->transform->GetMatrix()[3]));
	collider->SetRotation(bumper->transform->GetRotationMatrix());

	bumpers.push_back(bumper);

	// * * * * * Bottom Bumper * * * * * //

	position = glm::vec3(0, -150, 1050);
	collider = new OBBCollider(glm::vec3(0), glm::vec3(100.0f, 100.0f, 200.0f));

	start = position - glm::vec3(700, 0, 0);
	end = position + glm::vec3(900, 0, 0);

	bumper = new Bumper(1.5f, -1, start, end, CommonTextures::Marble, collider, cuboids.at(0)->transform, timer);

	bumper->Init();
	bumper->transform->Pitch(90.0f);
	bumper->transform->Translate(position);
	bumper->transform->Scale(glm::vec3(100.0f, 100.0f, 200.0f));

	collider->SetPosition(glm::vec3(bumper->transform->GetMatrix()[3]));
	collider->SetRotation(bumper->transform->GetRotationMatrix());

	bumpers.push_back(bumper);

}