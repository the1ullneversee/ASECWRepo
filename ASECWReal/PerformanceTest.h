#pragma once
#include "TestFramework.h"
#include "Clock.h"


#define float_vector std::vector<float>

class performance_test {

public:
	performance_test();
	~performance_test();
	chrono_type_duration vector_insert(unsigned int vector_size);
	float_vector vector_erase(int tests_torun, int test_iterations);
	chrono_type_duration joVectAbTest(unsigned int n, unsigned int m);
	chrono_type_duration joACBCAbTest(unsigned int n, unsigned int m);
	//list all the functions
private:
	//vectors and shit
	Clock testClock;
	TestFramework test_framework;
	unsigned int vector_size;
	unsigned int test_size;
	int idx;
	int test_switch;
	chrono_type phaseStart;
	chrono_type phaseEnd;
	chrono_type_duration phaseElapsed;
};