CXX := g++
CXXFLAGS := -g -O0 -Wall -std=gnu++17 -I .

ARTICLES = $(shell find doc/ -type f -name "*.md" -not -path "doc/node_modules/*")

.PHONY: test
test: $(ARGS)
	./$(ARGS) < test.txt

ptest:
	python3 ex.py < test.txt

.PHONY: template
template:
	tee {a..o}.cpp < template.cpp > /dev/null

format: $(ARTICLES)
	@echo $?
	@sed -i -e "s/。/. /g" $?
	@sed -i -e "s/、/, /g" $?
	@sed -i -e "s/[ \t]*$$//" $?
