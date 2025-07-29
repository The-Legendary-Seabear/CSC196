#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "GameData.h"
#include "Math/Vector3.h"
#include "Rocket.h"
#include "Framework/Scene.h"
#include "Renderer/Model.h"

void Player::Update(float dt) {
    


    float rotate = 0;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate -= 1;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate += 1;

    transform.rotation += (rotate * rotationRate) * dt;

    //thrust
    float thrust = 0;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    viper::vec2 direction{ 1, 0 };
    viper::vec2 force = direction.Rotate(viper::math::degToRad(transform.rotation)) * thrust * speed;
	velocity += force * dt;

    transform.position.x = viper::math::wrap(transform.position.x, 0.0f, (float)viper::GetEngine().GetRenderer().GetWidth());
    transform.position.y = viper::math::wrap(transform.position.y, 0.0f, (float)viper::GetEngine().GetRenderer().GetHeight());

    //check fire key pressed
    fireTime -= dt;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE) && fireTimer <= 0) {
        fireTimer = fireTime;

        std::shared_ptr<viper::Model> model = std::make_shared <viper::Model>(GameData::points, viper::vec3{ 1.0f, 1.0f, 1.0f });
    //spawn rocket at player position and rotation
        viper::Transform transform{ this->transform.position, this->transform.rotation, 2.0f };
        auto rocket = std::make_unique<Rocket>(transform, model);

        rocket->speed = 5000.0f;
        rocket->lifespan = 1.5f;
        rocket->tag = "player";
        rocket->name = "rocket";

        scene->AddActor(std::move(rocket));
    }

    Actor::Update(dt);

   
}

void Player::OnCollision(Actor* other) {
    if (tag != other->tag) {
        destroyed = true;
    }
}
