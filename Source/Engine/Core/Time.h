#pragma once
#include <chrono>

namespace viper {
	class Time {

	private:
		using clock = std::chrono::high_resolution_clock;

	public:
		Time() {
			m_startTime = clock::now();
			m_frameTime = clock::now();
		}

		void Tick();
		void Reset() { m_startTime = clock::now(); }

		float GetTime() const { return m_time; }
		float GetDeltaTime() const { return m_deltaTime * m_timeScale; }

		void SetTimeScale(float scale) { m_timeScale = scale; }

	private:
		float m_time = 0;
		float m_deltaTime = 0;
		float m_timeScale = 1.0f;


		clock::time_point m_startTime;
		clock::time_point m_frameTime;

	};


}
