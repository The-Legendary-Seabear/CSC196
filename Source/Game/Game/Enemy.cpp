#include "Enemy.h"
#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Player.h"
#include "Rocket.h"
#include "GameData.h"
#include "Renderer/Model.h"


void Enemy::Update(float dt) {

    Actor* player = scene->GetActorByName("player");
    if (player) {
        viper::vec2 direction{ 0, 0 };
        direction = player->transform.position - transform.position;
        direction = direction.Normalized();
        transform.rotation = viper::math::radToDeg(direction.Angle());
    }


    viper::vec2 force = viper::vec2{ 1,0 }.Rotate(viper::math::degToRad(transform.rotation * speed));
    velocity += force * dt;

    transform.position.x = viper::math::wrap(transform.position.x, 0.0f, (float)viper::GetEngine().GetRenderer().GetWidth());
    transform.position.y = viper::math::wrap(transform.position.y, 0.0f, (float)viper::GetEngine().GetRenderer().GetHeight());


    fireTimer -= dt;
    if (fireTimer = 0) {
        fireTimer = fireTime;

        std::shared_ptr<viper::Model> model = std::make_shared <viper::Model>(GameData::points, viper::vec3{ 1.0f, 1.0f, 1.0f });
        //spawn rocket at player position and rotation
        viper::Transform transform{ this->transform.position, this->transform.rotation, 2.0f };
        auto rocket = std::make_unique<Rocket>(transform, model);

        rocket->speed = 500.0f;
        rocket->lifespan = 1.5f;
        rocket->tag = "enemy";
        rocket->name = "rocket";

        scene->AddActor(std::move(rocket));

        Actor::Update(dt);
    }
}

void Enemy::OnCollision(Actor* other) {
    if (tag != other->tag) {
        destroyed = true;
        scene->GetGame()->AddPoints(100);
    }
}
