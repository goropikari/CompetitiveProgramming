CXX := g++
CXXFLAGS := -g -O2 -Wall -std=c++14 -I .

build: ex
test: ex
	./ex < test.txt | tee real_out.txt

diff:
	diff -swBZ test_out.txt real_out.txt

ptest:
	python3 ex.py < test.txt
