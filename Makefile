.PHONY: template
template:
	tee {a..o}.cpp < template.cpp > /dev/null

clean:
	$(shell find ./atcoder -type f -executable | xargs rm -f)

.PHONY: up
up:
	devcontainer up --workspace-folder=.

.PHONY: up-new
up-new:
	devcontainer up --workspace-folder=. --remove-existing-container

.PHONY: stop
stop:
	docker stop competitive_programming

.PHONY: exec
exec:
	devcontainer exec --workspace-folder=. bash

.PHONY: docker
docker:
	docker build -t jupyter -f docker/Dockerfile-jupyter .
	docker run --rm -it -p 8888:8888 jupyter
