.PHONY: all docs

PDF = Haugen_HansAlanWhitburn_Compulsory2.pdf

all: app $(PDF)

CC = g++
SOURCES = $(wildcard source/*.cpp)
CFLAGS = -g -Wall
OBJS = $(SOURCES:.cpp=.o)

app: $(OBJS)
	$(CC) $(OBJS) -o app

%o: %.cpp
	$(CC) $(CFLAGS) -c $*.cpp -o $@

$(PDF): README.md
	pandoc README.md -f markdown -t pdf -o $(PDF)

docs:
	doxygen docs
