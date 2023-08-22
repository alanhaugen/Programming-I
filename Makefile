.PHONY: all

all: hello alan.pdf

hello: main.cpp
	g++ main.cpp -o hello

alan.pdf: README.md
	pandoc README.md -f markdown -t pdf -o alan.pdf

