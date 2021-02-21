#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define N 1

#define MAXL 15

class Student {
	public:
	std::string name;
	std::string lastname;
	std::vector<unsigned int> nd;
	unsigned int egz;
	double grade;
	double median;

	void afterinit() {
		std::sort(nd.begin(), nd.end());
		unsigned int nd_sum = 0;
		for (unsigned int num : nd) {
			nd_sum += num;
		}
		grade = (double(nd_sum) / nd.size()) * 0.4l + double(egz) * 0.6l;
		median = double(nd[nd.size()/2]);
		if (!(nd.size() % 2)) median = (median + double(nd[nd.size()/2-1])) / 2;
	}

	void randomize() {
		srand(time(nullptr));
		nd.resize((unsigned int)rand() % 30);
		for (unsigned int &num : nd) {
			num = (unsigned int)rand() % 11;
		}
		egz = (unsigned int)rand() % 11;
		afterinit();
	}

	friend std::istream &operator>>(std::istream &in, Student &student) {
		if (!(in >> student.name)) return in;
		if (!(in >> student.lastname)) return in;
		if (std::max(student.name.size(), student.lastname.size()) > MAXL) {
			in.clear(std::ios_base::failbit);
			return in;
		}
		while (true) {
			unsigned int num;
			if (!(in >> num)) break;
			if (num > 10) {
				in.clear(std::ios_base::failbit);
				return in;
			}
			student.nd.push_back(num);
		}
		in.clear();
		if (student.nd.size() < 2) {
			in.clear(std::ios_base::failbit);
			return in;
		}
		student.egz = student.nd.back();
		student.nd.pop_back();
		student.afterinit();
		return in;
	}

	friend std::ostream &operator<<(std::ostream &out, const Student &student) {
		out << std::left << std::fixed << std::setprecision(2);
		std::cout << std::setw(MAXL+1) << student.name << std::setw(MAXL+1) << student.lastname;
		std::cout << std::setw(MAXL+1) << student.grade << std::setw(MAXL+1) << student.median;
		return out;
	}
};


int main() {
	Student student;
	if (!(std::cin >> student)) {
		std::cerr << "Netinkamas studentas\n"; 
		return 1;
	}
	std::cout << std::left;
	std::cout << std::setw(MAXL+1) << "Vardas" << std::setw(MAXL+1) << "Pavarde";
	std::cout << std::setw(MAXL+1) << "Egzaminas" << std::setw(MAXL+1) << "Median" << "\n";
	std::cout << student << "\n";

}
