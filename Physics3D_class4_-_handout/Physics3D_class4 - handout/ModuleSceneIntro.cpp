#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	ball1.radius = 3.0f;
	ball2.radius = 3.0f;

	ball1.SetPos(0.0f, 10.0f,0.0f);
	ball2.SetPos(12.0f, 10.0f, 0.0f);


	b1 = App->physics->AddBody(ball1);
	b2 = App->physics->AddBody(ball2);
	
	vec3 a1(3.0f, 5.0f, 0.0f);
	vec3 a2(9.0f, 5.0f, 0.0f);
	// TODO 2: Chain few N spheres together to form a snake
	App->physics->Point2PointConstraint(*b1,*b2, a1, a2);
	// TODO 4: Chain few N spheres together to form a a bike's sphere
	// Be sure to put the right axis
	

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	
	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake[i]->GetTransform(&(s_snake[i].transform));
		s_snake[i].Render();
	}

	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake2[i]->GetTransform(&(s_snake2[i].transform));
		s_snake2[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

