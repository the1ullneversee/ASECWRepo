#include "TestFramework.h"
#include "Clock.h"


#include <iostream>
#include <fstream>

TestFramework::TestFramework() {
	test_switch = 0;
}
TestFramework::~TestFramework() {}

void TestFramework::insert_element(std::vector<unsigned int> &vec_test, unsigned int vector_size) {
	unsigned int idx = 0;
	unsigned int max = vector_size;

	for (idx; idx <= max; idx++)
		vec_test.insert(vec_test.end(), idx);
}

void TestFramework::delete_element(std::vector<unsigned int> vec_test, int test_switch) {

	unsigned int half_size = vec_test.size() / 2;

	switch (test_switch) {
	case 1:
		vec_test.erase(vec_test.begin() + half_size);
		break;
	case 2:
		vec_test.erase(vec_test.begin(), vec_test.begin() + half_size);
		break;
	case 3:
		vec_test.erase(vec_test.begin() + half_size, vec_test.end());
		break;
	case 4:
		vec_test.erase(vec_test.begin() , vec_test.end());
		break;
	case 5:
		vec_test.erase(vec_test.begin(), vec_test.end());
		break;
	case 6:
		for (unsigned int idx = 0; idx <= vec_test.size(); idx++)
			vec_test.erase(vec_test.end() - 1);
		break;
	case 7:
		for (unsigned int idx = 0; idx <= vec_test.size(); idx++)
			vec_test.erase(vec_test.begin());
		break;
	}

}