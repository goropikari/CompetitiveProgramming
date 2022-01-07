CXX := g++
CXXFLAGS := -g -O2 -Wall -std=c++14 -I .

build: ex
test: ex
	./ex < test.txt

ptest:
	python3 ex.py < test.txt
