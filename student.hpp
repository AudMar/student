#pragma once

#include <vector>
#include <iostream>

#define MAXL 15 

class Student {
	public:
	static std::size_t N;
	std::string name;
	std::string lastname;
	std::vector<unsigned int> nd;
	unsigned int egz;
	double grade;
	double median;

	void afterinit();
	void randomize();
	friend std::istream &operator>>(std::istream &in, Student &student);
	friend std::ostream &operator<<(std::ostream &out, const Student &student);
};

