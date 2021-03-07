



main: main.cpp student.o
	g++ student.o main.cpp -o main -std=c++17

student.o: student.hpp student.cpp
	g++ student.cpp -o student.o -c -std=c++17
