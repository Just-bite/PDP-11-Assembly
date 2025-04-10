%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
MOV|ADD|SUB|MUL|DIV|ASH|ASHC|XOR|JSR|RTS|SOB|CLR|COM|INC|DEC|NEG|TST|ASR|ASL|ROR|ROL|SWAB|ADC|SBC|SXT|MARK|SPL|EMT|TRAP|BIC|BIS|BIT|HALT|WAIT|RTI|IOT|RESET|MFPS|MTPS return INSTRUCTION;
BR|BNE|BEQ|BPL|BMI|BVC|BVS|BCC|BCS|BGE|BLT|BGT|BLE|BHI|BLOS|BHIS|BLO|JMP return BRANCH;
\@                    return AT
\#                    return NUMSIGN;
\(                    return LPAREN;
\)                    return RPAREN;
-                     return MINUS;
\+                    return PLUS;
;[^\n]*               return COMMENT;
,                     return COMMA;
\n\s*                 return NEWLINE;
R[0-7]                return REGISTER;
0x[0-9A-Fa-f]+      { return HEX_NUM; }     /* Шестнадцатеричные */
0[0-7]+             { return OCT_NUM; }      /* Восьмеричные */
[0-9]+              { return DEC_NUM; }      /* Десятичные */
[a-zA-Z][a-zA-Z0-9]*:?  return LABEL;
\.[A-Za-z][A-Za-z0-9]*  return DIRECTIVE;
[ \t\r]+
%%
