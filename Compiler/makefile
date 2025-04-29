CC=g++

CFLAGS= 

all: yacc build

yacc:
	bison parser.yy
	flex lexer.l

build:
	$(CC) $(CFLAGS) lex.yy.c parser.tab.cc driver.cc main.cc -o marasm

clean:
	rm -f parser.tab.cc parser.tab.hh location.hh lex.yy.c
