.PHONY: all docs clean run

PDF = Haugen_HansAlanWhitburn_Compulsory3.pdf

all: app $(PDF)

FLEX  ?= flex
BISON ?= bison

CC     = g++
CFLAGS = -g -Wall

#PARSERS  = $(wildcard source/*.yacc)
#SCANNERS = $(wildcard source/*.lex)

SOURCES = $(wildcard source/*.cpp)
GENERATED_SOURCES = $(PARSERS:.y=.tab.cpp) $(SCANNERS:.lex=.cpp) 
SOURCES += $(GENERATED_SOURCES)
OBJS = $(SOURCES:.cpp=.o)

source/principia.cpp: source/calc.o

app: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o app

%o: %cpp
	$(CC) $(CFLAGS) -c $*cpp -o $@

%.tab.cpp: %.y
	$(BISON) -o $*.tab.cpp -d $<

%.cpp: %.lex 
	$(FLEX) --header-file=$*.h -o $*.cpp $*.lex

clean:
	rm $(OBJS) app

run: app
	./app

$(PDF): README.md figures
	pandoc README.md -f markdown -t pdf -o $(PDF)

docs:
	doxygen doc
