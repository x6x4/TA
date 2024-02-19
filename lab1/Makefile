
CC = g++

all: std flex


std: regularochka.o
	$(CC) $^ -o std_regex.out

flex: flex_cpp
	$(CC) lex.yy.cc -lfl -o flex.out

flex_cpp: pure_flex.flex
	flex++ $^

clean: 
	rm *.o *.out *.cc
