CXX := g++
CXXFLAGS := -g -O2 -Wall -std=gnu++17 -I .

ARTICLES = $(shell find doc/ -type f -name "*.md" -not -path "doc/node_modules/*")

build: ex
test: ex
	./ex < test.txt

diff:
	./ex < test.txt | tee test_actual_output.txt
	diff -swBZ test_expected_output.txt test_actual_output.txt

ptest:
	python3 ex.py < test.txt

docfmt: $(ARTICLES)
	@echo $?
	@sed -i -e "s/。/. /g" $?
	@sed -i -e "s/、/, /g" $?
	@sed -i -e "s/[ \t]*$$//" $?
