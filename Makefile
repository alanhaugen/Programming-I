.PHONY: all

all: app alan.pdf

CC = g++
SOURCES = $(wildcard *.cpp)
CFLAGS = -g -Wall
OBJS = $(SOURCES:.cpp=.o)

app: $(OBJS)
	$(CC) $(OBJS) -o app

%o: %.cpp
	$(CC) $(CFLAGS) -c $*.cpp -o $@

alan.pdf: README.md
	pandoc README.md -f markdown -t pdf -o alan.pdf

