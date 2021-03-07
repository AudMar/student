#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>

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

double get_time() {
	static auto last_time = std::chrono::system_clock::now();
	double ret = std::chrono::duration<double>(std::chrono::system_clock::now() - last_time).count();
	last_time = std::chrono::system_clock::now();
	return ret;
}

int main(int argc, char **argv) {
	std::vector<Student> students;
	get_time();
	std::cerr << std::fixed << std::setprecision(2);
	if (argc >= 2) {
		std::ifstream fin(argv[1]);
		students = read_input(fin);
	}
	else students = read_input(std::cin);
	if (students.empty()) {
		std::cerr << "Neisejo skaityti studentu\n";
		return 1;
	}
	std::cerr << "Laikas skaityt faila: " << get_time() << "\n";
	std::sort(students.begin(), students.end(), [](const Student &l, const Student &r) {
		if (l.name != r.name) return l.name < r.name;
		return l.lastname < r.lastname;
	});
	std::cerr << "Laikas std::sort: " << get_time() << "\n";
	std::ofstream low("low.txt");
	std::ofstream high("high.txt");
	low << std::left;
	low << std::setw(MAXL+1) << "Vardas" << std::setw(MAXL+1) << "Pavarde";
	low << std::setw(MAXL+1) << "Egzaminas" << std::setw(MAXL+1) << "Median" << "\n";
	high << std::left;
	high << std::setw(MAXL+1) << "Vardas" << std::setw(MAXL+1) << "Pavarde";
	high << std::setw(MAXL+1) << "Egzaminas" << std::setw(MAXL+1) << "Median" << "\n";
	for (const Student &student : students) {
		(student.grade < 5 ? low : high) << student << "\n";
	}
	low.close();
	high.close();
	std::cerr << "Laikas rasyti i failus: " << get_time() << "\n";
	return 0;
}
