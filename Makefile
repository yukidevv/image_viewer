.DEFAULT_GOAL := help

.PHONY: build
build: ## build
	gcc main.c -o out `pkg-config --cflags --libs gtk+-3.0`

.PHONY: help
help: ## help
	grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'

.PHONY: clean
clean: ## clean
	rm out
