#pragma once
#include <vector>
#include <list>

class TestFramework {
public:
	TestFramework();
	~TestFramework();


	void insert_element(std::vector<unsigned int> &vec_test, unsigned int vector_size);
	void delete_element(std::vector<unsigned int> vec_test, int test_switch);
	int test_switch;
	std::vector<unsigned int> vec_test;
	std::list<unsigned int> list_test;

private:

};