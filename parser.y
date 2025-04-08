%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token HEX_NUM OCT_NUM DEC_NUM
%token NUMSIGN AT MINUS PLUS
%token LPAREN RPAREN
%token COMMA NEWLINE
%token COMMENT LABEL
%token DIRECTIVE REGISTER
%token INSTRUCTION BRANCH

%%

input:
     |input line
;

line: NEWLINE
    | expr NEWLINE
    | expr COMMENT
;

expr:
    | INSTRUCTION adressingS COMMA adressingD
    | INSTRUCTION adressingD
    | INSTRUCTION
    | LABEL expr
    | BRANCH LABEL
    | DIRECTIVE number
;

number:
    | HEX_NUM
    | OCT_NUM
    | DEC_NUM
;

adressingS: REGISTER
    | prereg REGISTER postreg
    | notreg
;

adressingD: REGISTER
    | prereg REGISTER postreg
;

notreg: NUMSIGN number
    | AT NUMSIGN number
;

prereg:
    | LPAREN
    | prelp LPAREN
    ;

prelp:
    | AT atarg
    | MINUS
    | number
;

atarg:
    | MINUS
    | number
;

postreg: RPAREN
    | RPAREN PLUS
    ;

%%

/* Секция C-кода */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();  // Запуск парсера
    return 0;
}
