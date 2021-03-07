#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>

#include "student.hpp"

std::vector<Student> read_input(std::istream &in) {
	std::vector<Student> vec;
	{
		// find N
		// Vardas Pavarde N1 N2...N10 Egz. 
		std::string dummy;
		if (!(in >> dummy) || !(in >> dummy)) return vec;
		for (Student::N = 1;; ++Student::N) {
			if (!(in >> dummy)) return vec;
			if (dummy != "ND" + std::to_string(Student::N)) break;
		}
		if (Student::N <= 1) return vec;
		--Student::N;
	}
	while (true) {
		vec.emplace_back();
		if (!(in >> vec.back())) {
			vec.pop_back();
			break;
		}
	}
	return vec;
}

int main(int argc, char **argv) {
	std::vector<Student> students;
	if (argc >= 2) {
		std::ifstream fin(argv[1]);
		students = read_input(fin);
	}
	else students = read_input(std::cin);
	if (students.empty()) {
		std::cerr << "Failed to read students\n";
		return 1;
	}
	std::sort(students.begin(), students.end(), [](const Student &l, const Student &r) {
		if (l.name != r.name) return l.name < r.name;
		return l.lastname < r.lastname;
	});
	std::cout << std::left;
	std::cout << std::setw(MAXL+1) << "Vardas" << std::setw(MAXL+1) << "Pavarde";
	std::cout << std::setw(MAXL+1) << "Egzaminas" << std::setw(MAXL+1) << "Median" << "\n";
	for (const Student &student : students) {
		std::cout << student << "\n";
	}

}
