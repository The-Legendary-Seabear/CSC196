#pragma once
#include "Framework/Actor.h"

class Enemy : public viper::Actor {
public:
	float speed = 20.0f;

public:
	Enemy() = default;
	Enemy(const viper::Transform transform, class std::shared_ptr<viper::Model> model) :
		Actor{ transform, model } {
	}

	void Update(float dt) override;

private:

};

