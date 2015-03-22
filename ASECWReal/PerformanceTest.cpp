#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include <list>
#include "PerformanceTest.h"
#include "joVect.cpp"
#include "joACBC.cpp"

typedef std::vector<unsigned int>::const_iterator vec_iterator;
typedef std::list<unsigned int>::const_iterator list_iterator; 
performance_test::performance_test() {

	int idx = 0;
}
performance_test::~performance_test() {}
chrono_type_duration performance_test::vector_insert(unsigned int vector_size) {

	// -- Vec insert -- //
	phaseStart = testClock.Clock_start();
	test_framework.insert_element(test_framework.vec_test, vector_size);
	return testClock.Clock_end(phaseStart, phaseEnd);
	
}
float_vector performance_test::vector_erase(int tests_torun, int test_iterations) {
	// -- Vec Delete Start -- //
	float_vector duration_vector;
	test_switch = 1;
	idx = 0;
	for (int index = 0; index <= tests_torun; index++) {
		std::cout << "Running Test Case: " << test_switch << std::endl;
		phaseStart = testClock.Clock_start();
		for (idx; idx <= test_iterations; idx++) {
			test_framework.delete_element(test_framework.vec_test, test_switch);
		}
		phaseElapsed = testClock.Clock_end(phaseStart, phaseEnd);
		duration_vector.push_back((phaseElapsed.count() / 1E6));
		test_switch++;
		idx = 0;
	}
	return duration_vector;
}

chrono_type_duration performance_test::joVectAbTest(unsigned int n, unsigned int m) {

	// -- Vec insert -- //
	phaseStart = testClock.Clock_start();
	joVect(n, m);
	return testClock.Clock_end(phaseStart, phaseEnd);

}

chrono_type_duration performance_test::joACBCAbTest(unsigned int n, unsigned int m) {

	// -- Vec insert -- //
	phaseStart = testClock.Clock_start();
	joACBC(n, m);
	return testClock.Clock_end(phaseStart, phaseEnd);

}