%{ /* -*- C++ -*- */
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> 
# include "mediator.hh"
# include "parser.tab.hh"


void print_token(const std::string& type, const std::string& value = "");
%}



%option noyywrap nounput noinput batch debug

%{
  yy::parser::symbol_type
  make_DEC_NUM (const std::string &s, const yy::parser::location_type& loc);
%}


IDENTIFIER   [a-zA-Z_][a-zA-Z0-9_]*
BRANCH       (?i:br|bne|beq|bpl|bmi|bvc|bvs|bcc|bcs|bge|blt|bgt|ble|bhi|blos|bhis|blo|bpl|bnz|jmp)
INSTRUCTION  (?i:cmpb|cmp|mov|movb|add|sub|mul|div|ash|ashc|xor|jsr|rts|sob|clr|clrb|com|comb|inc|incb|dec|decb|neg|negb|tst|tstb|asr|asl|ror|rol|swab|adc|sbc|sxt|mark|spl|emt|trap|bic|bis|bit|halt|wait|rti|iot|reset|mfps|mtps|clc|clv|clz|cln|ccc|scc|sec|sez|sev|sen|bpt|rtt)
PORT         (?i:tps|tpb|tkb|tks)
PROCSTATEWRD (?i:psw)
PC           (?i:pc)
SP           (?i:sp)
EQU          EQU|=
BYTE         .BYTE
WORD         .WORD
DATA_S       .DATA
CODE_S       .CODE
CHAR_LITERAL \'([^\'\\]|\\.)\'
AT           \@  
NUMSIGN      \#
LPAREN       \( 
RPAREN       \)
MINUS        -
PLUS         \+
DIV          \\
MUL          "*"
MOD          "%"
LSHIFT       "<<"
RSHIFT       ">>"
BAND         "&"
BOR          "|"
BXOR         "^"
SIGN        [-+]
DIGIT       [0-9]
OCT_DIGIT   [0-7]
HEX_DIGIT   [0-9A-Fa-f]
HEX         0[xX]{HEX_DIGIT}+
OCT         0{OCT_DIGIT}+
DEC         {DIGIT}+
HEX_NUM     {SIGN}?{HEX}
OCT_NUM     {SIGN}?{OCT}
DEC_NUM     {SIGN}?{DEC}
NUMERIC_OFFSET .-{DEC_NUM}
REGISTER    R{OCT_DIGIT}
LETTER      [a-zA-Z_]
ASCII_DIRS  \.ASCII[Z]? 
STRING_LITERAL \"([^"\\\n]|\\([nrt0"\\]|x[0-9a-fA-F]{2}))*\"
DIRECTIVE   "."{LETTER}+
LABEL        {IDENTIFIER}:? 
WHITESPACE   [ \t\r]
NEWLINE     \n\s*
COMMENT     ";"[^\n]*


%%

%{
  yy::location& loc = m.location;
  loc.step ();
%}


{INSTRUCTION} {
    std::string token(yytext);
    std::transform(token.begin(), token.end(), token.begin(), ::toupper);
    return yy::parser::make_INSTRUCTION(token, loc);
  }
{BRANCH} {
    std::string token(yytext);
    std::transform(token.begin(), token.end(), token.begin(), ::toupper);
    return yy::parser::make_BRANCH(token, loc);
  }
{PORT} {
    std::string token(yytext);
    std::transform(token.begin(), token.end(), token.begin(), ::toupper);
    return yy::parser::make_PORT(token, loc);
  }
{PROCSTATEWRD} return yy::parser::make_OCT_NUM("0177770",loc);
{PC}          return yy::parser::make_REGISTER ("R7",loc);
{SP}          return yy::parser::make_REGISTER ("R6",loc);
{EQU}         return yy::parser::make_EQU_DIRECTIVE(yytext,loc);
{BYTE}        return yy::parser::make_BYTE_DIRECTIVE(yytext,loc);
{WORD}        return yy::parser::make_WORD_DIRECTIVE(yytext,loc);
{DATA_S}      return yy::parser::make_DATA_S(yytext,loc);
{CODE_S}      return yy::parser::make_CODE_S(yytext,loc);
{AT}          return yy::parser::make_AT (yytext,loc);
{NUMSIGN}     return yy::parser::make_NUMSIGN(yytext, loc) ;
{LPAREN}      return yy::parser::make_LPAREN(yytext, loc)  ;
{RPAREN}      return yy::parser::make_RPAREN(yytext, loc)  ;
{MINUS}       return yy::parser::make_MINUS (yytext, loc)  ; 
{PLUS}        return yy::parser::make_PLUS(yytext,loc) ; 
{DIV}         return yy::parser::make_DIV(yytext,loc);
{MUL}         return yy::parser::make_MULT(yytext,loc) ;
{MOD}         return yy::parser::make_MOD(yytext,loc) ;
{LSHIFT}      return yy::parser::make_LSHIFT(yytext,loc) ;
{RSHIFT}      return yy::parser::make_RSHIFT(yytext,loc) ;
{BAND}        return yy::parser::make_BAND(yytext,loc) ;
{BOR}         return yy::parser::make_BOR(yytext,loc) ;
{BXOR}        return yy::parser::make_BXOR(yytext,loc) ;
{CHAR_LITERAL} return yy::parser::make_CHAR_LITERAL(yytext,loc);
{COMMENT}     loc.lines (yyleng); loc.step (); return yy::parser::make_COMMENT (yytext,loc);
","           return yy::parser::make_COMMA (loc);
{NEWLINE}+    loc.lines (yyleng); loc.step (); return yy::parser::make_NEWLINE (yytext,loc);
{NUMERIC_OFFSET} return make_DEC_NUM(yytext+1,loc) ; 
{REGISTER}    return yy::parser::make_REGISTER(yytext, loc);
{HEX_NUM}    return yy::parser::make_HEX_NUM(yytext,loc) ;   
{OCT_NUM}     return yy::parser::make_OCT_NUM(yytext,loc) ; 
{DEC_NUM}     return make_DEC_NUM (yytext, loc);
{LABEL}       return yy::parser::make_LABEL (yytext, loc);
{ASCII_DIRS}  {if (yytext[6] == 'Z') {
                  return yy::parser::make_ASCIIZ_DIRECTIVE(yytext,loc);
               } else {
              return yy::parser::make_ASCII_DIRECTIVE(yytext,loc);
               }};
{STRING_LITERAL} return yy::parser::make_STRING_LITERAL(yytext,loc);
{DIRECTIVE}   return yy::parser::make_EQU_DIRECTIVE(yytext, loc);
{WHITESPACE}+ loc.step ();
.             {
                throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
              }

<<EOF>>       return yy::parser::make_YYEOF (loc);

%%

yy::parser::symbol_type
make_DEC_NUM (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  long n = strtol (s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
  return yy::parser::make_DEC_NUM ((int) n, loc);
}


void print_token(const std::string& type, const std::string& value) {
    if (value.empty()) {
        std::cout << "[" << type << "]" << std::endl;
    } else {
        std::cout << "[" << type << "] " << value << std::endl;
    }
}



void
Mediator::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
Mediator::scan_end ()
{
  fclose (yyin);
}
