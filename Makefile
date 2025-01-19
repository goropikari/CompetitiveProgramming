CXX := g++
CXXFLAGS := -g -O0 -Wall -std=gnu++23 -I .

ARTICLES := $(shell find site/ -type f -name "*.md")

build: $(OUTPUT)

$(OUTPUT): $(INPUT)
	g++ -g -O0 -Wall -std=gnu++23 -I . $(INPUT) -o $(OUTPUT)

test: build
	$(OUTPUT) < test.txt

.PHONY: template
template:
	tee {a..o}.cpp < template.cpp > /dev/null

format: $(ARTICLES)
	@echo $?
	@sed -i -e "s/。/. /g" $?
	@sed -i -e "s/、/, /g" $?
	@sed -i -e "s/[ \t]*$$//" $?

clean:
	$(shell find ./atcoder -type f -executable | xargs rm -f)

up:
	devcontainer up --workspace-folder=.

up-new:
	devcontainer up --workspace-folder=. --remove-existing-container

exec:
	devcontainer exec --workspace-folder=. bash
