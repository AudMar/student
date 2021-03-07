#include <iomanip>
#include <algorithm>

#include "student.hpp"

void Student::afterinit() {
	std::sort(nd.begin(), nd.end());
	unsigned int nd_sum = 0;
	for (unsigned int num : nd) {
		nd_sum += num;
	}
	grade = (double(nd_sum) / nd.size()) * 0.4l + double(egz) * 0.6l;
	median = double(nd[nd.size()/2]);
	if (!(nd.size() % 2)) median = (median + double(nd[nd.size()/2-1])) / 2;
}

void Student::randomize() {
	srand(time(nullptr));
	nd.resize((unsigned int)rand() % 30);
	for (unsigned int &num : nd) {
		num = (unsigned int)rand() % 11;
	}
	egz = (unsigned int)rand() % 11;
	afterinit();
}

std::istream &operator>>(std::istream &in, Student &student) {
	if (!(in >> student.name)) return in;
	if (!(in >> student.lastname)) return in;
	if (std::max(student.name.size(), student.lastname.size()) > MAXL) {
		in.clear(std::ios_base::failbit);
		return in;
	}
	student.nd.resize(Student::N+1);
	for (unsigned int &num : student.nd) {
		if (!(in >> num) || num > 10) {
			in.clear(std::ios_base::failbit);
			return in;
		}
	}
	if (student.nd.size() < 2) {
		in.clear(std::ios_base::failbit);
		return in;
	}
	student.egz = student.nd.back();
	student.nd.pop_back();
	student.afterinit();
	return in;
}

std::ostream &operator<<(std::ostream &out, const Student &student) {
	out << std::left << std::fixed << std::setprecision(2);
	out << std::setw(MAXL+1) << student.name << std::setw(MAXL+1) << student.lastname;
	out << std::setw(MAXL+1) << student.grade << std::setw(MAXL+1) << student.median;
	return out;
}

std::size_t Student::N = 0;
