#include "clock.h"

Clock::Clock(){}
Clock::~Clock(){}

chrono_type Clock::Clock_start() {
	
	return std::chrono::steady_clock::now();
	
}

chrono_type_duration Clock::Clock_end(chrono_type &phase_start, chrono_type &phase_end) {

	phase_end = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(phase_end - phase_start);
}