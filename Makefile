.PHONY: template
template:
	tee {a..o}.cpp < template.cpp > /dev/null

clean:
	$(shell find ./atcoder -type f -executable | xargs rm -f)

up:
	devcontainer up --workspace-folder=.

up-new:
	devcontainer up --workspace-folder=. --remove-existing-container

exec:
	devcontainer exec --workspace-folder=. bash
