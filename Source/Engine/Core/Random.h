#pragma once
#include <cstdlib>

namespace viper {

	namespace random {
		/// <summary>
		/// Generates a random integer value.
		/// </summary>
		/// <returns>A pseudo-random integer value. </returns>
		inline int getRandomInt() { return rand(); }

		inline int getRandomInt(int max) { return rand() % max; }

		inline int getRandomInt(int min, int max) { return min + getRandomInt(max - min + 1); }

		inline float getRandomFloat() { return rand() / (float)RAND_MAX; }


}

}