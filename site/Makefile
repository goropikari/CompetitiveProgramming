.PHONY: format
format:
	markdownlint-cli2 --fix ./content/**/*.md
	markdownlint-cli2 --fix ./content/*.md
	cbfmt -w ./content/**/*.md
	cbfmt -w ./content/*.md

.PHONY: lint
lint:
	markdownlint-cli2 ./content/**/*.md
	cbfmt -c ./content/**/*.md
