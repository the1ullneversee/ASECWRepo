#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include "PerformanceTest.h"

int main(int argv, char* argc[]) {

	unsigned int vector_size = 100000;
	unsigned int test_iterations = 10000;
	int tests_torun = 4;
	int idx = 0;
	
	performance_test perf_test;
	
	chrono_type_duration phaseElapsed = perf_test.vector_insert(vector_size);
	std::cout << "Call(s) elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;

	
	float_vector phaseElapsedVect = perf_test.vector_erase(tests_torun, test_iterations);

	for (std::vector<float>::iterator it = phaseElapsedVect.begin(); it != phaseElapsedVect.end(); ++it) {
		std::cout << "Test case" << " " << idx << " elapsed time: " << *it << std::endl;
		idx++;
	}
	unsigned int n = 10000;
	unsigned int m = 7;
	int iterations = 15;
	
	
	for (int idx = 0; idx < iterations; idx++) {
		phaseElapsed = perf_test.joVectAbTest(n, m);
		std::cout << "Call(s) vect original elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		phaseElapsed = perf_test.joACBCAbTest(n, m);
		std::cout << "Call(s) ACBC original elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
	}

	n = 20000;
	m = 14;
	for (int idx = 0; idx < iterations; idx++) {
		phaseElapsed = perf_test.joVectAbTest(n, m);
		std::cout << "Call(s) vect double elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		phaseElapsed = perf_test.joACBCAbTest(n, m);
		std::cout << "Call(s) acbc double elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
	}
	
	n = 10000;
	m = 7;
	for (int idx = 0; idx < iterations; idx++) {
		//std::cout << " The M value is: " << m << std::endl;
		phaseElapsed = perf_test.joVectAbTest(n, m);
		std::cout << float(phaseElapsed.count() / 1E6) << std::endl;
		//std::cout << "Call(s) vect large M elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		phaseElapsed = perf_test.joACBCAbTest(n, m);
		std::cout << float(phaseElapsed.count() / 1E6) << std::endl;
		//std::cout << "Call(s) ACBC large M elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		m = m + m;
	}
	
	n = 10000;
	m = 30;
	for (int idx = 0; idx < iterations; idx++) {
		phaseElapsed = perf_test.joVectAbTest(n, m);
		std::cout << "Call(s) elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		std::cout << "The n and m values are: " << n << m << std::endl;
		phaseElapsed = perf_test.joACBCAbTest(n, m);
		std::cout << "Call(s) elapsed time : " << float(phaseElapsed.count() / 1E6) << std::endl;
		n = n + 100;
	}
	
	return 0;
}