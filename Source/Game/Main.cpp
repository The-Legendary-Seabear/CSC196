#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>

#define NAME "Alex"

// if you want to you can use using namespace viper;

int main() {

	//const float deg = viper::radToDeg(viper::pi);

	viper::math::min(5, 3);
	viper::math::clamp(2, 3, 5);

	std::cout << NAME << std::endl;
	std::cout << "Hello World!" << std::endl;
	std::cout << viper::math::pi << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << viper::random::getRandomFloat() << std::endl;
	}
}