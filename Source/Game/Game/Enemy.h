#pragma once
#include "Game/Actor.h"

class Enemy : public viper::Actor {
public:
	Enemy() = default;
	Enemy(const viper::Transform transform, class std::shared_ptr<viper::Model> model) :
		Actor{ transform, model } {
	}

	void Update(float dt) override;

private:

};

