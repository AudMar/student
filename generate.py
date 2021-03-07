#!/usr/bin/python3
import sys
import random
import time

MAXL = 15

def read_params():
	global outf, min_grade, max_grade, grade_size, student_size
	argv = sys.argv
	grade_size = int(argv[1])
	student_size = int(argv[2])
	min_grade = int(argv[3])
	max_grade = int(argv[4])
	if max_grade < min_grade:
		raise ValueError("min grade should be less than max grade") 
	if min_grade < 0 or max_grade > 10:
		raise ValueError("min/max grade should be in range [0, 10]")
	if grade_size < 1 or student_size < 1:
		raise ValueError("invalid size")
	if len(argv) < 6:
		outf = sys.stdout
	else:
		outf = open(sys.argv[5], "w")


def main():
	t = time.time()
	try:
		read_params()
	except:
		print(f"Usage: {sys.argv[0]} [grade_size] [student_size] [min_grade] [max_grade] ?[output_file]", file=sys.stderr)
		return 1
	
	pad = lambda x : x.ljust(MAXL)
	data = ["".join(map(pad, ["Vardas", "Pavarde"] + [f"ND{i+1}" for i in range(grade_size)] + ["Egz."]))]
	data += ["".join(map(pad, [f"Vardas{i}", f"Pavarde{i}"] + [str(random.randrange(min_grade, max_grade+1))
		for _ in range(grade_size+1)])) for i in range(student_size)]
	outf.write("\n".join(data) + "\n")
	total_time = str(time.time() - t)
	print(f"Laikas generuoti: {total_time[:total_time.find('.')+3]}", file = sys.stderr)
	return 0

if __name__ == "__main__":
	exit(main())


