%{ /* -*- C++ -*- */
#include <iostream>
#include <string>
#include <fstream>


# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> 
# include "driver.hh"
# include "parser.tab.hh"


void print_token(const std::string& type, const std::string& value = "");
%}



%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_DEC_NUM (const std::string &s, const yy::parser::location_type& loc);

%}


IDENTIFIER   [a-zA-Z][a-zA-Z0-9]*
LABEL        {IDENTIFIER}:? 
BRANCH       BR|BNE|BEQ|BPL|BMI|BVC|BVS|BCC|BCS|BGE|BLT|BGT|BLE|BHI|BLOS|BHIS|BLO|JMP
INSTRUCTION  MOV|ADD|SUB|MUL|DIV|ASH|ASHC|XOR|JSR|RTS|SOB|CLR|COM|INC|DEC|NEG|TST|ASR|ASL|ROR|ROL|SWAB|ADC|SBC|SXT|MARK|SPL|EMT|TRAP|BIC|BIS|BIT|HALT|WAIT|RTI|IOT|RESET|MFPS|MTPS
AT           \@  
NUMSIGN      \#
LPAREN       \( 
RPAREN       \)
MINUS        -
PLUS         \+
SIGN        [+-]
DIGIT       [0-9]
OCT_NUMBER   [0-7]+
HEX_NUM     0x[0-9A-Fa-f]
DEC_NUM     {SIGN}?{DIGIT}+
REGISTER    R{OCT_NUMBER}
LETTER      [a-zA-Z_]
DIRECTIVE   "."{LETTER}+
WHITESPACE   [ \t\r]
NEWLINE     \n\s*
COMMENT     ";"[^\n]*


%%

%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}


{INSTRUCTION} return yy::parser::make_INSTRUCTION (yytext, loc);
{BRANCH}      return yy::parser::make_BRANCH (yytext,loc);
{AT}          return yy::parser::make_AT (yytext,loc);
{NUMSIGN}     return yy::parser::make_NUMSIGN(yytext, loc) ;
{LPAREN}      return yy::parser::make_LPAREN(yytext, loc)  ;
{RPAREN}      return yy::parser::make_RPAREN(yytext, loc)  ;
{MINUS}       return yy::parser::make_MINUS (yytext, loc)  ; 
{PLUS}        return yy::parser::make_PLUS(yytext,loc) ; 
{COMMENT}     loc.lines (yyleng); loc.step (); return yy::parser::make_COMMENT (yytext,loc);
","           return yy::parser::make_COMMA (loc);
{NEWLINE}+    loc.lines (yyleng); loc.step (); return yy::parser::make_NEWLINE (yytext,loc);
{REGISTER}    return yy::parser::make_REGISTER(yytext, loc);
{HEX_NUM}+    return yy::parser::make_HEX_NUM(yytext,loc) ;   
0{OCT_NUMBER} return yy::parser::make_OCT_NUM(yytext,loc) ; 
{DEC_NUM}     return make_DEC_NUM (yytext, loc);
{LABEL}       return yy::parser::make_LABEL (yytext, loc);
{DIRECTIVE}   return yy::parser::make_DIRECTIVE (yytext, loc);
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
driver::scan_begin ()
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
driver::scan_end ()
{
  fclose (yyin);
}





