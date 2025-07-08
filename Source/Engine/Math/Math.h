#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace viper {
	namespace math {

	constexpr float pi = 3.1415926535897932384626433832795;
	constexpr float twoPi = 2 * pi;
	constexpr float halfPi = pi * 0.5f;

	constexpr float radToDeg(float rad) { return rad * (180/pi); }
	constexpr float degToRad(float deg) { return deg * (pi/180); }

	using std::min;
	using std::max;
	using std::clamp;
	using std::sqrt;
	using std::sqrtf;
	using std::sin;
	using std::sinf;
	using std::cos;
	using std::cosf;
	}

}
	//template <typename T>
	//T min(T a, T b) {
	//	return (a < b) ? a : b; //This is the ternary way for the code below
	//	/*
	//	if (a < b) return a;
	//	else return b;
	//	*/
	//}
