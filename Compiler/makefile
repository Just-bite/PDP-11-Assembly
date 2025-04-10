CC = g++
CFLAGS = -std=c++17 -Wall

all: assembler

assembler: lex.yy.cc parser.tab.cc Main.cpp
	$(CC) $(CFLAGS) -o $@ $^

lex.yy.cc: lexer.l
	flex -o lex.yy.cc lexer.l  # Явно указываем выходной файл

parser.tab.cc parser.tab.h: parser.y
	bison -d parser.y --output=parser.tab.cc  # Генерируем .cc вместо .c

clean:
	rm -f assembler lex.yy.cc parser.tab.* *.output *.bin *.txt

test: assembler
	./assembler < test.asm