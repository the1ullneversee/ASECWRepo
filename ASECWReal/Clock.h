#pragma once
#include <chrono>
#include <cmath>
#include <map>
#include <string>
#include <iterator>

#define chrono_type std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration>
#define chrono_type_duration std::chrono::duration<long long, std::micro>

class Clock {
public:
	Clock();
	~Clock();
	chrono_type Clock_start();
	chrono_type_duration Clock_end(chrono_type &phase_start, chrono_type &phase_end);

private:
	//chrono_type phaseStart;
	//chrono_type phaseEnd;
	//chrono_type_duration phaseElapsed;

};