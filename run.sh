make main

echo "1000:" 1>&2
./generate.py 10 1000 0 10 | ./main
echo 1>&2

echo "10000:" 1>&2
./generate.py 10 10000 0 10 | ./main
echo 1>&2

echo "100000:" 1>&2
./generate.py 10 100000 0 10 | ./main
echo 1>&2

echo "1000000:" 1>&2
./generate.py 10 1000000 0 10 | ./main
echo 1>&2

echo "10000000:" 1>&2
./generate.py 10 10000000 0 10 | ./main
echo 1>&2
