
PROJ = example

headers = $(PROJ)/header.h $(PROJ)/declare.h $(PROJ)/define.c $(PROJ)/footer.c
additional-deps = Makefile  $(shell ls *.py)

CFLAGS = # -O3
TFLAGS =

# clang is faster. TCC is the fastest that I know of
CC = gcc

CPP = g++

compilersrcs = $(shell find src -name \*.cc)
compilerojbs = ${compilersrcs:.cc=.comp.o}

testsrcs = $(shell find src -name \*.cc)
testobjs = ${testsrcs:.cc=.test.o} $(filter-out src/main%, $(compilerojbs))

test.exe: $(testobjs)
	$(CPP) -o $@ $^

compiler.exe: $(compilerojbs)
	$(CPP) -o $@ $^

%.comp.o : %.cc
	$(CPP) -o $@ -c $<

%.test.o : %.cc
	$(CPP) -o $@ -c $< -Isrc
