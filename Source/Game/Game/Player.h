#pragma once

#include "Game/Actor.h"

class Player : public viper::Actor {
public:
	Player() = default;
	Player(const viper::Transform transform, class std::shared_ptr<viper::Model> model) :
		Actor{ transform, model } {}
		
	void Update(float dt) override;

private:

};
