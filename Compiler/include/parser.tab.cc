// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 38 "src/parser.yy"

  #include "mediator.hh"
  #include "validator.hh"
  #include "listmaker.hh"
    bool is_at;
    bool is_numsign;
    bool is_left;
    bool is_right;
    bool is_minus;
    const int DATA_SEGMENT = 01000;
    const int CODE_SEGMENT = 02000;

#line 59 "include/parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 151 "include/parser.tab.cc"

  /// Build a parser object.
  parser::parser (Mediator& m_yyarg, Validator& valid_yyarg, ListMaker& list_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      m (m_yyarg),
      valid (valid_yyarg),
      list (list_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.YY_MOVE_OR_COPY< Operand > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.YY_MOVE_OR_COPY< int16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.YY_MOVE_OR_COPY< int8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // "instruction"
      case symbol_kind::S_COMMENT: // "comment"
      case symbol_kind::S_NEWLINE: // "newline"
      case symbol_kind::S_BRANCH: // "branch"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_LABEL: // "label"
      case symbol_kind::S_PORT: // "port"
      case symbol_kind::S_EQU_DIRECTIVE: // "directive_EQU"
      case symbol_kind::S_BYTE_DIRECTIVE: // "directive_BYTE"
      case symbol_kind::S_WORD_DIRECTIVE: // "directive_WORD"
      case symbol_kind::S_DATA_S: // "data_seg"
      case symbol_kind::S_CODE_S: // "code_seg"
      case symbol_kind::S_CHAR_LITERAL: // "char_literal"
      case symbol_kind::S_AT: // "at"
      case symbol_kind::S_NUMSIGN: // "numsign"
      case symbol_kind::S_LPAREN: // "lparen"
      case symbol_kind::S_RPAREN: // "rparen"
      case symbol_kind::S_MINUS: // "minus"
      case symbol_kind::S_PLUS: // "plus"
      case symbol_kind::S_HEX_NUM: // "hexnum"
      case symbol_kind::S_OCT_NUM: // "octnum"
      case symbol_kind::S_MULT: // "mult"
      case symbol_kind::S_DIV: // "div"
      case symbol_kind::S_MOD: // "mod"
      case symbol_kind::S_LSHIFT: // "lshift"
      case symbol_kind::S_RSHIFT: // "rshift"
      case symbol_kind::S_BAND: // "band"
      case symbol_kind::S_BOR: // "bor"
      case symbol_kind::S_BXOR: // "bxor"
      case symbol_kind::S_ASCII_DIRECTIVE: // "ascii"
      case symbol_kind::S_ASCIIZ_DIRECTIVE: // "asciiz"
      case symbol_kind::S_STRING_LITERAL: // "string_literal"
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_postreg: // postreg
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.YY_MOVE_OR_COPY< std::vector<int16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.YY_MOVE_OR_COPY< std::vector<int8_t> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.move< Operand > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.move< int16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.move< int8_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // "instruction"
      case symbol_kind::S_COMMENT: // "comment"
      case symbol_kind::S_NEWLINE: // "newline"
      case symbol_kind::S_BRANCH: // "branch"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_LABEL: // "label"
      case symbol_kind::S_PORT: // "port"
      case symbol_kind::S_EQU_DIRECTIVE: // "directive_EQU"
      case symbol_kind::S_BYTE_DIRECTIVE: // "directive_BYTE"
      case symbol_kind::S_WORD_DIRECTIVE: // "directive_WORD"
      case symbol_kind::S_DATA_S: // "data_seg"
      case symbol_kind::S_CODE_S: // "code_seg"
      case symbol_kind::S_CHAR_LITERAL: // "char_literal"
      case symbol_kind::S_AT: // "at"
      case symbol_kind::S_NUMSIGN: // "numsign"
      case symbol_kind::S_LPAREN: // "lparen"
      case symbol_kind::S_RPAREN: // "rparen"
      case symbol_kind::S_MINUS: // "minus"
      case symbol_kind::S_PLUS: // "plus"
      case symbol_kind::S_HEX_NUM: // "hexnum"
      case symbol_kind::S_OCT_NUM: // "octnum"
      case symbol_kind::S_MULT: // "mult"
      case symbol_kind::S_DIV: // "div"
      case symbol_kind::S_MOD: // "mod"
      case symbol_kind::S_LSHIFT: // "lshift"
      case symbol_kind::S_RSHIFT: // "rshift"
      case symbol_kind::S_BAND: // "band"
      case symbol_kind::S_BOR: // "bor"
      case symbol_kind::S_BXOR: // "bxor"
      case symbol_kind::S_ASCII_DIRECTIVE: // "ascii"
      case symbol_kind::S_ASCIIZ_DIRECTIVE: // "asciiz"
      case symbol_kind::S_STRING_LITERAL: // "string_literal"
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_postreg: // postreg
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.move< std::vector<int16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.move< std::vector<int8_t> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.copy< Operand > (that.value);
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.copy< int16_t > (that.value);
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.copy< int8_t > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // "instruction"
      case symbol_kind::S_COMMENT: // "comment"
      case symbol_kind::S_NEWLINE: // "newline"
      case symbol_kind::S_BRANCH: // "branch"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_LABEL: // "label"
      case symbol_kind::S_PORT: // "port"
      case symbol_kind::S_EQU_DIRECTIVE: // "directive_EQU"
      case symbol_kind::S_BYTE_DIRECTIVE: // "directive_BYTE"
      case symbol_kind::S_WORD_DIRECTIVE: // "directive_WORD"
      case symbol_kind::S_DATA_S: // "data_seg"
      case symbol_kind::S_CODE_S: // "code_seg"
      case symbol_kind::S_CHAR_LITERAL: // "char_literal"
      case symbol_kind::S_AT: // "at"
      case symbol_kind::S_NUMSIGN: // "numsign"
      case symbol_kind::S_LPAREN: // "lparen"
      case symbol_kind::S_RPAREN: // "rparen"
      case symbol_kind::S_MINUS: // "minus"
      case symbol_kind::S_PLUS: // "plus"
      case symbol_kind::S_HEX_NUM: // "hexnum"
      case symbol_kind::S_OCT_NUM: // "octnum"
      case symbol_kind::S_MULT: // "mult"
      case symbol_kind::S_DIV: // "div"
      case symbol_kind::S_MOD: // "mod"
      case symbol_kind::S_LSHIFT: // "lshift"
      case symbol_kind::S_RSHIFT: // "rshift"
      case symbol_kind::S_BAND: // "band"
      case symbol_kind::S_BOR: // "bor"
      case symbol_kind::S_BXOR: // "bxor"
      case symbol_kind::S_ASCII_DIRECTIVE: // "ascii"
      case symbol_kind::S_ASCIIZ_DIRECTIVE: // "asciiz"
      case symbol_kind::S_STRING_LITERAL: // "string_literal"
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_postreg: // postreg
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.copy< std::vector<int16_t> > (that.value);
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.copy< std::vector<int8_t> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.move< Operand > (that.value);
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.move< int16_t > (that.value);
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.move< int8_t > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // "instruction"
      case symbol_kind::S_COMMENT: // "comment"
      case symbol_kind::S_NEWLINE: // "newline"
      case symbol_kind::S_BRANCH: // "branch"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_LABEL: // "label"
      case symbol_kind::S_PORT: // "port"
      case symbol_kind::S_EQU_DIRECTIVE: // "directive_EQU"
      case symbol_kind::S_BYTE_DIRECTIVE: // "directive_BYTE"
      case symbol_kind::S_WORD_DIRECTIVE: // "directive_WORD"
      case symbol_kind::S_DATA_S: // "data_seg"
      case symbol_kind::S_CODE_S: // "code_seg"
      case symbol_kind::S_CHAR_LITERAL: // "char_literal"
      case symbol_kind::S_AT: // "at"
      case symbol_kind::S_NUMSIGN: // "numsign"
      case symbol_kind::S_LPAREN: // "lparen"
      case symbol_kind::S_RPAREN: // "rparen"
      case symbol_kind::S_MINUS: // "minus"
      case symbol_kind::S_PLUS: // "plus"
      case symbol_kind::S_HEX_NUM: // "hexnum"
      case symbol_kind::S_OCT_NUM: // "octnum"
      case symbol_kind::S_MULT: // "mult"
      case symbol_kind::S_DIV: // "div"
      case symbol_kind::S_MOD: // "mod"
      case symbol_kind::S_LSHIFT: // "lshift"
      case symbol_kind::S_RSHIFT: // "rshift"
      case symbol_kind::S_BAND: // "band"
      case symbol_kind::S_BOR: // "bor"
      case symbol_kind::S_BXOR: // "bxor"
      case symbol_kind::S_ASCII_DIRECTIVE: // "ascii"
      case symbol_kind::S_ASCIIZ_DIRECTIVE: // "asciiz"
      case symbol_kind::S_STRING_LITERAL: // "string_literal"
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_postreg: // postreg
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.move< std::vector<int16_t> > (that.value);
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.move< std::vector<int8_t> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (m, valid, list));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        yylhs.value.emplace< Operand > ();
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        yylhs.value.emplace< int16_t > ();
        break;

      case symbol_kind::S_byte_value: // byte_value
        yylhs.value.emplace< int8_t > ();
        break;

      case symbol_kind::S_INSTRUCTION: // "instruction"
      case symbol_kind::S_COMMENT: // "comment"
      case symbol_kind::S_NEWLINE: // "newline"
      case symbol_kind::S_BRANCH: // "branch"
      case symbol_kind::S_REGISTER: // "register"
      case symbol_kind::S_LABEL: // "label"
      case symbol_kind::S_PORT: // "port"
      case symbol_kind::S_EQU_DIRECTIVE: // "directive_EQU"
      case symbol_kind::S_BYTE_DIRECTIVE: // "directive_BYTE"
      case symbol_kind::S_WORD_DIRECTIVE: // "directive_WORD"
      case symbol_kind::S_DATA_S: // "data_seg"
      case symbol_kind::S_CODE_S: // "code_seg"
      case symbol_kind::S_CHAR_LITERAL: // "char_literal"
      case symbol_kind::S_AT: // "at"
      case symbol_kind::S_NUMSIGN: // "numsign"
      case symbol_kind::S_LPAREN: // "lparen"
      case symbol_kind::S_RPAREN: // "rparen"
      case symbol_kind::S_MINUS: // "minus"
      case symbol_kind::S_PLUS: // "plus"
      case symbol_kind::S_HEX_NUM: // "hexnum"
      case symbol_kind::S_OCT_NUM: // "octnum"
      case symbol_kind::S_MULT: // "mult"
      case symbol_kind::S_DIV: // "div"
      case symbol_kind::S_MOD: // "mod"
      case symbol_kind::S_LSHIFT: // "lshift"
      case symbol_kind::S_RSHIFT: // "rshift"
      case symbol_kind::S_BAND: // "band"
      case symbol_kind::S_BOR: // "bor"
      case symbol_kind::S_BXOR: // "bxor"
      case symbol_kind::S_ASCII_DIRECTIVE: // "ascii"
      case symbol_kind::S_ASCIIZ_DIRECTIVE: // "asciiz"
      case symbol_kind::S_STRING_LITERAL: // "string_literal"
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_postreg: // postreg
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_word_expr: // word_expr
        yylhs.value.emplace< std::vector<int16_t> > ();
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        yylhs.value.emplace< std::vector<int8_t> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program1: input $end
#line 108 "src/parser.yy"
                      {
            list.print_symbol_table(m.program().get_symbol_table());
            if(m.create_listing)
                list.print_listing_to_file("listing.txt");
        }
#line 897 "include/parser.tab.cc"
    break;

  case 3: // input: %empty
#line 115 "src/parser.yy"
                {}
#line 903 "include/parser.tab.cc"
    break;

  case 4: // input: input line
#line 117 "src/parser.yy"
                   {}
#line 909 "include/parser.tab.cc"
    break;

  case 5: // line: expr "newline"
#line 120 "src/parser.yy"
                     {
            if (m.create_listing)
                list.add_to_listing(yystack_[1].value.as < std::string > (), m.program().getILC());
        }
#line 918 "include/parser.tab.cc"
    break;

  case 6: // line: expr "comment" "newline"
#line 125 "src/parser.yy"
                             { 
            if (m.create_listing)
                list.add_to_listing(yystack_[2].value.as < std::string > (), m.program().getILC(), yystack_[1].value.as < std::string > ());
        }
#line 927 "include/parser.tab.cc"
    break;

  case 7: // line: "comment" "newline"
#line 130 "src/parser.yy"
                        {
            if (m.create_listing)
                list.add_to_listing(yystack_[1].value.as < std::string > (), m.program().getILC());
        }
#line 936 "include/parser.tab.cc"
    break;

  case 8: // line: "newline"
#line 135 "src/parser.yy"
                {}
#line 942 "include/parser.tab.cc"
    break;

  case 9: // line: expr $end
#line 137 "src/parser.yy"
                   { 
            if(m.create_listing) 
                list.add_to_listing(yystack_[1].value.as < std::string > (), m.program().getILC());
        }
#line 951 "include/parser.tab.cc"
    break;

  case 10: // expr: "instruction" adressingS "," adressingD
#line 143 "src/parser.yy"
                                                {
            m.program().add_instruction(yystack_[3].value.as < std::string > (), {yystack_[2].value.as < Operand > (), yystack_[0].value.as < Operand > ()});
            yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < Operand > ().string_form + ", " + yystack_[0].value.as < Operand > ().string_form;
        }
#line 960 "include/parser.tab.cc"
    break;

  case 11: // expr: "instruction" adressingD
#line 148 "src/parser.yy"
                               { 
            m.program().add_instruction(yystack_[1].value.as < std::string > (), {yystack_[0].value.as < Operand > ()});
            yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < Operand > ().string_form;
        }
#line 969 "include/parser.tab.cc"
    break;

  case 12: // expr: "instruction"
#line 153 "src/parser.yy"
                    {
            m.program().add_instruction(yystack_[0].value.as < std::string > (), {});
            yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        }
#line 978 "include/parser.tab.cc"
    break;

  case 13: // expr: "label" expr
#line 158 "src/parser.yy"
                   {
            m.program().process_label(yystack_[1].value.as < std::string > (), false, 0);
            yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > ();
        }
#line 987 "include/parser.tab.cc"
    break;

  case 14: // expr: "branch" "label"
#line 163 "src/parser.yy"
                     {
            if(yystack_[1].value.as < std::string > () != "JMP"){
                m.program().add_instruction(yystack_[1].value.as < std::string > (), {Operand(0, RELATIVE, yystack_[1].value.as < std::string > (), 0, yystack_[0].value.as < std::string > ())});
            }
            else
                m.program().add_instruction(yystack_[1].value.as < std::string > (), {Operand(0, ABSOLUTE, yystack_[1].value.as < std::string > (), 0, yystack_[0].value.as < std::string > ())});
            m.program().process_label(yystack_[0].value.as < std::string > (), false, 0);
            yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > ();
        }
#line 1001 "include/parser.tab.cc"
    break;

  case 15: // expr: "branch" "decnum"
#line 173 "src/parser.yy"
                       {
            if(yystack_[1].value.as < std::string > () != "JMP")
                m.program().add_instruction(yystack_[1].value.as < std::string > (),{Operand(0,RELATIVE, yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > (), "numof")});
            else 
                m.program().add_instruction(yystack_[1].value.as < std::string > (),{Operand(0,ABSOLUTE, yystack_[1].value.as < std::string > (), yystack_[0].value.as < int > (), "numof")});
            yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + std::to_string(yystack_[0].value.as < int > ());
        }
#line 1013 "include/parser.tab.cc"
    break;

  case 16: // expr: "label" "directive_WORD" word_expr
#line 181 "src/parser.yy"
                                       {
            std::string listing = " ";
            m.program().process_label(yystack_[2].value.as < std::string > (), false, m.program().getILC());
            for (auto val : yystack_[0].value.as < std::vector<int16_t> > ()) {
                m.program().set_word_table(m.program().getILC(), val); 
                m.program().addILC(2);
                listing += std::to_string(val);
            }
            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + listing;
        }
#line 1028 "include/parser.tab.cc"
    break;

  case 17: // expr: "label" "directive_BYTE" byte_expr
#line 192 "src/parser.yy"
                                       {
            std::string listing = " ";
            m.program().process_label(yystack_[2].value.as < std::string > (), false, m.program().getILC());
            for (auto val : yystack_[0].value.as < std::vector<int8_t> > ()) {
                m.program().set_byte_table(m.program().getILC(), val);
                m.program().addILC(); 
                listing += std::to_string(val) + " ";
            }
            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ()+ " " + yystack_[1].value.as < std::string > () + listing;
        }
#line 1043 "include/parser.tab.cc"
    break;

  case 18: // expr: "label" "ascii" "string_literal"
#line 203 "src/parser.yy"
                                             {
            if (yystack_[0].value.as < std::string > ().size() >= 2) { 
                m.program().process_label(yystack_[2].value.as < std::string > (), true, m.program().getILC());
                for (size_t i = 1; i < yystack_[0].value.as < std::string > ().size() - 1; i++) {
                    char c = yystack_[0].value.as < std::string > ()[i];
                    m.program().set_byte_table(m.program().getILC(), static_cast<uint8_t>(c));
                    m.program().addILC();
                }
            } 
            else 
                m.program().process_label(yystack_[2].value.as < std::string > (), true,m.program().getILC());
            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > ();
        }
#line 1061 "include/parser.tab.cc"
    break;

  case 19: // expr: "label" "asciiz" "string_literal"
#line 217 "src/parser.yy"
                                              { 
            if (yystack_[0].value.as < std::string > ().size() >= 2) {  
                m.program().process_label(yystack_[2].value.as < std::string > ().substr(0, yystack_[2].value.as < std::string > ().size() - 1), true, m.program().getILC());
                for (size_t i = 1; i < yystack_[0].value.as < std::string > ().size() - 1; i++) {
                    char c = yystack_[0].value.as < std::string > ()[i];
                    m.program().set_byte_table(m.program().getILC(), static_cast<uint8_t>(c));
                    m.program().addILC();
                }
                m.program().set_byte_table(m.program().getILC(), 0);
                m.program().addILC();
            } else {
                m.program().process_label(yystack_[2].value.as < std::string > (), true,m.program().getILC());
                m.program().set_byte_table(m.program().getILC(),  0);
                m.program().addILC();
            }
            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > ();
        }
#line 1083 "include/parser.tab.cc"
    break;

  case 20: // expr: "label" "directive_EQU" equ_expr
#line 235 "src/parser.yy"
                                     {
            m.program().process_label(yystack_[2].value.as < std::string > ().substr(0, yystack_[2].value.as < std::string > ().size() - 1), true, yystack_[0].value.as < int16_t > ());
            yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + std::to_string(yystack_[0].value.as < int16_t > ()) ;
        }
#line 1092 "include/parser.tab.cc"
    break;

  case 21: // expr: "label"
#line 240 "src/parser.yy"
              {
            m.program().process_label(yystack_[0].value.as < std::string > (), false, 0);
            yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        }
#line 1101 "include/parser.tab.cc"
    break;

  case 22: // expr: "data_seg"
#line 245 "src/parser.yy"
               {
            m.program().setILC(DATA_SEGMENT);
            yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        }
#line 1110 "include/parser.tab.cc"
    break;

  case 23: // expr: "code_seg"
#line 250 "src/parser.yy"
               {
            m.program().setILC(CODE_SEGMENT);
            yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        }
#line 1119 "include/parser.tab.cc"
    break;

  case 24: // adressingS: "register"
#line 256 "src/parser.yy"
                 {
            yylhs.value.as < Operand > () = Operand(atoi(yystack_[0].value.as < std::string > ().substr(1).c_str()), REG, yystack_[0].value.as < std::string > ());
            valid.current_addressing_flags &= REG;
        }
#line 1128 "include/parser.tab.cc"
    break;

  case 25: // adressingS: prereg "register" postreg
#line 261 "src/parser.yy"
                                {
            std::string spec_signs = check_for_listing_flags(yystack_[2].value.as < int16_t > ());
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                yylhs.value.as < Operand > () = Operand(atoi(yystack_[1].value.as < std::string > ().substr(1).c_str()), adr_type, spec_signs + yystack_[1].value.as < std::string > () + " " +yystack_[0].value.as < std::string > (), yystack_[2].value.as < int16_t > ());
                valid.current_addressing_flags &= REG;
            }
        }
#line 1142 "include/parser.tab.cc"
    break;

  case 26: // adressingS: notreg
#line 271 "src/parser.yy"
               {
            std::string spec_signs = check_for_listing_flags(yystack_[0].value.as < int16_t > ());
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                yylhs.value.as < Operand > () = Operand(-1, adr_type, spec_signs, yystack_[0].value.as < int16_t > ());    
                valid.current_addressing_flags &= REG;
            }
        }
#line 1156 "include/parser.tab.cc"
    break;

  case 27: // adressingS: "numsign" "label"
#line 281 "src/parser.yy"
                      {
                valid.current_addressing_flags |= HASH|NUM; 
                yylhs.value.as < Operand > () = Operand(m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].value, valid.determine_adressing_type(), 
                                          yystack_[1].value.as < std::string > () + " " +  yystack_[0].value.as < std::string > (), m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].value, yystack_[0].value.as < std::string > ()); 
        }
#line 1166 "include/parser.tab.cc"
    break;

  case 28: // adressingS: "port"
#line 287 "src/parser.yy"
             { yylhs.value.as < Operand > () = Operand(0,ABSOLUTE,yystack_[0].value.as < std::string > (),0,yystack_[0].value.as < std::string > ()); }
#line 1172 "include/parser.tab.cc"
    break;

  case 29: // adressingD: "register"
#line 290 "src/parser.yy"
                 {
            yylhs.value.as < Operand > () = Operand(atoi(yystack_[0].value.as < std::string > ().substr(1).c_str()), REG, yystack_[0].value.as < std::string > ());
            valid.current_addressing_flags &= REG;
        }
#line 1181 "include/parser.tab.cc"
    break;

  case 30: // adressingD: prereg "register" postreg
#line 295 "src/parser.yy"
                                {
            std::string spec_signs = check_for_listing_flags(yystack_[2].value.as < int16_t > ());
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR; 
            else {
                yylhs.value.as < Operand > () = Operand(atoi(yystack_[1].value.as < std::string > ().substr(1).c_str()), adr_type, spec_signs + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > () , yystack_[2].value.as < int16_t > ());
                valid.current_addressing_flags &= REG;
            }
        }
#line 1195 "include/parser.tab.cc"
    break;

  case 31: // adressingD: notreg
#line 305 "src/parser.yy"
               {
            std::string spec_signs = check_for_listing_flags(yystack_[0].value.as < int16_t > ());  
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else {
                yylhs.value.as < Operand > () = Operand(-1, adr_type, spec_signs, yystack_[0].value.as < int16_t > ());    
                valid.current_addressing_flags &= REG;
            }
        }
#line 1209 "include/parser.tab.cc"
    break;

  case 32: // adressingD: "numsign" "label"
#line 315 "src/parser.yy"
                      {
            valid.current_addressing_flags |= HASH|NUM;
            AddressingTypes adr_type = valid.determine_adressing_type();
            if (adr_type == ERROR) YYERROR;
            else yylhs.value.as < Operand > () = Operand(0, adr_type, yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (), 0, yystack_[0].value.as < std::string > ());
        }
#line 1220 "include/parser.tab.cc"
    break;

  case 33: // adressingD: "port"
#line 322 "src/parser.yy"
             { yylhs.value.as < Operand > () = Operand(0, ABSOLUTE, yystack_[0].value.as < std::string > (), 0, yystack_[0].value.as < std::string > ()); }
#line 1226 "include/parser.tab.cc"
    break;

  case 34: // notreg: "numsign" number
#line 326 "src/parser.yy"
                       { 
            valid.current_addressing_flags |= HASH|NUM; 
            yylhs.value.as < int16_t > () = yystack_[0].value.as < int16_t > ();
            is_numsign = true;
        }
#line 1236 "include/parser.tab.cc"
    break;

  case 35: // notreg: "at" "numsign" number
#line 332 "src/parser.yy"
                          { 
            valid.current_addressing_flags |= AT_F|HASH|NUM; 
            yylhs.value.as < int16_t > () = yystack_[0].value.as < int16_t > ();
            is_numsign = true;
            is_at = true;
        }
#line 1247 "include/parser.tab.cc"
    break;

  case 36: // equ_expr: number
#line 339 "src/parser.yy"
          { yylhs.value.as < int16_t > () = yystack_[0].value.as < int16_t > (); }
#line 1253 "include/parser.tab.cc"
    break;

  case 37: // equ_expr: "label"
#line 341 "src/parser.yy"
              {
            if (m.program().get_symbol_table().count(yystack_[0].value.as < std::string > ()) && m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].is_defined) 
                yylhs.value.as < int16_t > () = m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].value;
            else yylhs.value.as < int16_t > () = 0; 
        }
#line 1263 "include/parser.tab.cc"
    break;

  case 38: // equ_expr: equ_expr "plus" equ_expr
#line 347 "src/parser.yy"
                               { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () + yystack_[0].value.as < int16_t > (); }
#line 1269 "include/parser.tab.cc"
    break;

  case 39: // equ_expr: equ_expr "minus" equ_expr
#line 349 "src/parser.yy"
                                { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () - yystack_[0].value.as < int16_t > (); }
#line 1275 "include/parser.tab.cc"
    break;

  case 40: // equ_expr: equ_expr "mult" equ_expr
#line 351 "src/parser.yy"
                               { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () * yystack_[0].value.as < int16_t > (); }
#line 1281 "include/parser.tab.cc"
    break;

  case 41: // equ_expr: equ_expr "div" equ_expr
#line 353 "src/parser.yy"
                              {
            if (yystack_[0].value.as < int16_t > () != 0) 
                yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () / yystack_[0].value.as < int16_t > ();
            else {
                valid.display_error_message("Division by zero in equ expression");
                YYERROR;
            }
        }
#line 1294 "include/parser.tab.cc"
    break;

  case 42: // equ_expr: equ_expr "mod" equ_expr
#line 362 "src/parser.yy"
                              {
            if (yystack_[0].value.as < int16_t > () != 0)
                yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () % yystack_[0].value.as < int16_t > ();
            else {
                valid.display_error_message("Division by zero in equ expression");
                YYERROR;
            }
        }
#line 1307 "include/parser.tab.cc"
    break;

  case 43: // equ_expr: equ_expr "lshift" equ_expr
#line 371 "src/parser.yy"
                                 { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () << yystack_[0].value.as < int16_t > (); }
#line 1313 "include/parser.tab.cc"
    break;

  case 44: // equ_expr: equ_expr "rshift" equ_expr
#line 373 "src/parser.yy"
                                 { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () >> yystack_[0].value.as < int16_t > (); }
#line 1319 "include/parser.tab.cc"
    break;

  case 45: // equ_expr: equ_expr "band" equ_expr
#line 375 "src/parser.yy"
                               { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () & yystack_[0].value.as < int16_t > (); }
#line 1325 "include/parser.tab.cc"
    break;

  case 46: // equ_expr: equ_expr "bor" equ_expr
#line 377 "src/parser.yy"
                              { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () | yystack_[0].value.as < int16_t > (); }
#line 1331 "include/parser.tab.cc"
    break;

  case 47: // equ_expr: equ_expr "bxor" equ_expr
#line 379 "src/parser.yy"
                               { yylhs.value.as < int16_t > () = yystack_[2].value.as < int16_t > () ^ yystack_[0].value.as < int16_t > (); }
#line 1337 "include/parser.tab.cc"
    break;

  case 48: // equ_expr: "minus" equ_expr
#line 381 "src/parser.yy"
                                    { yylhs.value.as < int16_t > () = -yystack_[0].value.as < int16_t > (); }
#line 1343 "include/parser.tab.cc"
    break;

  case 49: // equ_expr: "lparen" equ_expr "rparen"
#line 383 "src/parser.yy"
                               { yylhs.value.as < int16_t > () = yystack_[1].value.as < int16_t > (); }
#line 1349 "include/parser.tab.cc"
    break;

  case 50: // byte_expr: byte_value
#line 386 "src/parser.yy"
                   { yylhs.value.as < std::vector<int8_t> > () = {yystack_[0].value.as < int8_t > ()}; }
#line 1355 "include/parser.tab.cc"
    break;

  case 51: // byte_expr: byte_expr "," byte_value
#line 388 "src/parser.yy"
                                   { 
            yystack_[2].value.as < std::vector<int8_t> > ().push_back(yystack_[0].value.as < int8_t > ());
            yylhs.value.as < std::vector<int8_t> > () = yystack_[2].value.as < std::vector<int8_t> > ();
         }
#line 1364 "include/parser.tab.cc"
    break;

  case 52: // byte_value: number
#line 394 "src/parser.yy"
               {yylhs.value.as < int8_t > () = static_cast<uint8_t>(yystack_[0].value.as < int16_t > ()); }
#line 1370 "include/parser.tab.cc"
    break;

  case 53: // byte_value: "char_literal"
#line 396 "src/parser.yy"
                     { yylhs.value.as < int8_t > () = static_cast<uint8_t>(yystack_[0].value.as < std::string > ()[1]); }
#line 1376 "include/parser.tab.cc"
    break;

  case 54: // byte_value: "label"
#line 398 "src/parser.yy"
              {
            if (m.program().get_symbol_table().count(yystack_[0].value.as < std::string > ()) && m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].is_defined) 
                yylhs.value.as < int8_t > () = static_cast<uint8_t>(m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].value);
            else yylhs.value.as < int8_t > () = 0; 
        }
#line 1386 "include/parser.tab.cc"
    break;

  case 55: // word_expr: word_value
#line 404 "src/parser.yy"
                   { yylhs.value.as < std::vector<int16_t> > () = {yystack_[0].value.as < int16_t > ()};}
#line 1392 "include/parser.tab.cc"
    break;

  case 56: // word_expr: word_expr "," word_value
#line 406 "src/parser.yy"
                                   {
            yystack_[2].value.as < std::vector<int16_t> > ().push_back(yystack_[0].value.as < int16_t > ());
            yylhs.value.as < std::vector<int16_t> > () = yystack_[2].value.as < std::vector<int16_t> > ();
        }
#line 1401 "include/parser.tab.cc"
    break;

  case 57: // word_value: number
#line 412 "src/parser.yy"
        { yylhs.value.as < int16_t > () = yystack_[0].value.as < int16_t > (); }
#line 1407 "include/parser.tab.cc"
    break;

  case 58: // word_value: "label"
#line 414 "src/parser.yy"
              {
            if (m.program().get_symbol_table().count(yystack_[0].value.as < std::string > ()) && m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].is_defined) 
                yylhs.value.as < int16_t > () = static_cast<uint8_t>(m.program().get_symbol_table()[yystack_[0].value.as < std::string > ()].value);
             else yylhs.value.as < int16_t > () = 0;
        }
#line 1417 "include/parser.tab.cc"
    break;

  case 59: // number: "hexnum"
#line 420 "src/parser.yy"
                    { yylhs.value.as < int16_t > () = parse_hex(yystack_[0].value.as < std::string > ()); }
#line 1423 "include/parser.tab.cc"
    break;

  case 60: // number: "octnum"
#line 422 "src/parser.yy"
                    { yylhs.value.as < int16_t > () = parse_oct(yystack_[0].value.as < std::string > ()); }
#line 1429 "include/parser.tab.cc"
    break;

  case 61: // number: "decnum"
#line 424 "src/parser.yy"
                    { yylhs.value.as < int16_t > () = static_cast<int16_t>(yystack_[0].value.as < int > ()); }
#line 1435 "include/parser.tab.cc"
    break;

  case 62: // prereg: "lparen"
#line 428 "src/parser.yy"
               { 
            valid.current_addressing_flags |= LPAR; 
            is_left = true;
        }
#line 1444 "include/parser.tab.cc"
    break;

  case 63: // prereg: prelp "lparen"
#line 433 "src/parser.yy"
                     { 
            valid.current_addressing_flags |= LPAR;
            is_left = true;
        }
#line 1453 "include/parser.tab.cc"
    break;

  case 64: // postreg: "rparen"
#line 439 "src/parser.yy"
               { 
            valid.current_addressing_flags |= RPAR; 
            yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        }
#line 1462 "include/parser.tab.cc"
    break;

  case 65: // postreg: "rparen" "plus"
#line 444 "src/parser.yy"
                    { 
            valid.current_addressing_flags |= RPAR|PLS; 
            yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > ();
        }
#line 1471 "include/parser.tab.cc"
    break;

  case 66: // prelp: "at" "minus"
#line 450 "src/parser.yy"
                 {
            valid.current_addressing_flags |= AT_F|MIN; 
            is_at = true;
            is_minus = true;
        }
#line 1481 "include/parser.tab.cc"
    break;

  case 67: // prelp: "at" number
#line 456 "src/parser.yy"
                  {
            valid.current_addressing_flags |= AT_F|NUM;
            is_at = true; 
            yylhs.value.as < int16_t > () = yystack_[0].value.as < int16_t > ();   
        }
#line 1491 "include/parser.tab.cc"
    break;

  case 68: // prelp: "at"
#line 462 "src/parser.yy"
           { 
            valid.current_addressing_flags |= AT_F;
            is_at = true; 
        }
#line 1500 "include/parser.tab.cc"
    break;

  case 69: // prelp: "minus"
#line 467 "src/parser.yy"
              { 
            valid.current_addressing_flags |= MIN;
            is_minus = true;

        }
#line 1510 "include/parser.tab.cc"
    break;

  case 70: // prelp: number
#line 473 "src/parser.yy"
               {
            valid.current_addressing_flags |= NUM;
            yylhs.value.as < int16_t > () =yystack_[0].value.as < int16_t > ();
        }
#line 1519 "include/parser.tab.cc"
    break;


#line 1523 "include/parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", ",", "instruction", "comment",
  "newline", "branch", "register", "label", "port", "directive_EQU",
  "directive_BYTE", "directive_WORD", "data_seg", "code_seg",
  "char_literal", "at", "numsign", "lparen", "rparen", "minus", "plus",
  "hexnum", "octnum", "mult", "div", "mod", "lshift", "rshift", "band",
  "bor", "bxor", "ascii", "asciiz", "string_literal", "decnum", "UMINUS",
  "$accept", "program1", "input", "line", "expr", "adressingS",
  "adressingD", "notreg", "equ_expr", "byte_expr", "byte_value",
  "word_expr", "word_value", "number", "prereg", "postreg", "prelp", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -36;

  const signed char parser::yytable_ninf_ = -29;

  const short
  parser::yypact_[] =
  {
     -36,     4,   116,   -36,   -36,    16,     3,   -36,    18,    54,
     -36,   -36,   -36,    73,    10,    19,    90,    -4,   -36,   -36,
     -36,   -36,   -36,    20,   -36,    22,   -36,    13,    12,   -36,
     -36,   -36,    53,    -6,    81,    21,    24,   -36,   -36,    32,
     -36,   -22,   -36,   -36,    50,   -36,    76,    35,   -36,   -36,
      53,    53,   119,   -36,   -36,   -36,    57,   -36,   -36,   -36,
      67,   -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,    83,
     -36,   -36,    49,    58,    68,   107,   -36,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    -6,    81,   -36,
      35,   -36,   -36,   127,   127,   132,   132,   132,   -24,   -24,
     -36,   -36,   -36,   -36,   -36,   -36
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     0,     1,     2,    12,     0,     8,     0,    21,
      22,    23,     4,     0,    29,    33,    68,     0,    62,    69,
      59,    60,    61,     0,    11,    31,    70,     0,     0,     7,
      14,    15,     0,     0,     0,     0,     0,    13,     9,     0,
       5,     0,    66,    67,    32,    34,     0,     0,    63,    37,
       0,     0,    20,    36,    54,    53,    17,    50,    52,    58,
      16,    55,    57,    18,    19,     6,    35,    29,    33,     0,
      10,    31,     0,    64,    30,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    65,    49,    39,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    51,    56,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -36,   -36,   -36,   -36,    66,   -36,    39,    45,   -35,   -36,
       9,   -36,    -7,    -5,    52,    11,   -36
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    12,    13,    23,    24,    25,    52,    56,
      57,    60,    61,    53,    27,    74,    28
  };

  const signed char
  parser::yytable_[] =
  {
      26,    20,    21,    54,     3,    44,    84,    85,    86,    29,
      55,    43,    45,   -24,    22,    75,    76,    20,    21,    20,
      21,    47,   -28,    46,    14,   -26,    15,    30,    58,    62,
      22,    48,    22,    16,    17,    18,    66,    19,    65,    20,
      21,    26,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    22,   -27,    31,    73,    63,    90,     5,    64,
      87,     8,    49,     9,    45,    32,    33,    34,    10,    11,
      88,   -25,    50,    38,    51,    37,    20,    21,    39,    40,
      91,   104,    58,    62,    67,    70,    68,    35,    36,    22,
      59,    71,    89,    16,    69,    18,   103,    19,    72,    20,
      21,   105,     0,     0,    20,    21,    20,    21,    41,     0,
       0,    42,    22,    20,    21,     0,     4,    22,     0,    22,
       5,     6,     7,     8,     0,     9,    22,    92,    77,    78,
      10,    11,    79,    80,    81,    82,    83,    84,    85,    86,
      77,    78,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    79,    80,    81,    82,    83,    84,    85,    86,
      82,    83,    84,    85,    86
  };

  const signed char
  parser::yycheck_[] =
  {
       5,    23,    24,     9,     0,     9,    30,    31,    32,     6,
      16,    16,    17,     3,    36,    50,    51,    23,    24,    23,
      24,     8,     3,     3,     8,     3,    10,     9,    33,    34,
      36,    19,    36,    17,    18,    19,    41,    21,     6,    23,
      24,    46,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    36,     3,    36,    20,    35,     8,     4,    35,
       3,     7,     9,     9,    69,    11,    12,    13,    14,    15,
       3,     3,    19,     0,    21,     9,    23,    24,     5,     6,
      22,    88,    87,    88,     8,    46,    10,    33,    34,    36,
       9,    46,     9,    17,    18,    19,    87,    21,    46,    23,
      24,    90,    -1,    -1,    23,    24,    23,    24,    18,    -1,
      -1,    21,    36,    23,    24,    -1,     0,    36,    -1,    36,
       4,     5,     6,     7,    -1,     9,    36,    20,    21,    22,
      14,    15,    25,    26,    27,    28,    29,    30,    31,    32,
      21,    22,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    25,    26,    27,    28,    29,    30,    31,    32,
      28,    29,    30,    31,    32
  };

  const signed char
  parser::yystos_[] =
  {
       0,    39,    40,     0,     0,     4,     5,     6,     7,     9,
      14,    15,    41,    42,     8,    10,    17,    18,    19,    21,
      23,    24,    36,    43,    44,    45,    51,    52,    54,     6,
       9,    36,    11,    12,    13,    33,    34,    42,     0,     5,
       6,    18,    21,    51,     9,    51,     3,     8,    19,     9,
      19,    21,    46,    51,     9,    16,    47,    48,    51,     9,
      49,    50,    51,    35,    35,     6,    51,     8,    10,    18,
      44,    45,    52,    20,    53,    46,    46,    21,    22,    25,
      26,    27,    28,    29,    30,    31,    32,     3,     3,     9,
       8,    22,    20,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    48,    50,    53
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     2,     3,     2,     1,     2,
       4,     2,     1,     2,     2,     2,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       3,     1,     2,     1,     2,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     2,     1,     1,
       1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   108,   108,   115,   117,   120,   125,   130,   135,   137,
     143,   148,   153,   158,   163,   173,   181,   192,   203,   217,
     235,   240,   245,   250,   256,   261,   271,   281,   287,   290,
     295,   305,   315,   322,   326,   332,   339,   341,   347,   349,
     351,   353,   362,   371,   373,   375,   377,   379,   381,   383,
     386,   388,   394,   396,   398,   404,   406,   412,   414,   420,
     422,   424,   428,   433,   439,   444,   450,   456,   462,   467,
     473
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2166 "include/parser.tab.cc"

#line 478 "src/parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}

int16_t parse_oct(const std::string& s) {
    size_t start = 0;
    bool negative = false;
    if (s.empty()) {
        throw std::invalid_argument("Empty octal string");
    }
    
    if (s[0] == '-') {
        negative = true;
        start = 1;
    } else if (s[0] == '+') {
        start = 1;
    }
    
    for (size_t i = start; i < s.size(); ++i) {
        char c = s[i];
        if (c < '0' || c > '7') 
            throw std::invalid_argument("Invalid octal digit: " + std::string(1, c));
        
    }
    
    long val = strtol(s.c_str(), nullptr, 8);
    if (val > INT16_MAX || val < INT16_MIN) 
        throw std::out_of_range("Octal number out of int16_t range");
    

    return static_cast<int16_t>(val);
}

int16_t parse_hex(const std::string& s) {
    size_t start = 0;
    bool negative = false;
    if (s.size() < 3) {
        throw std::invalid_argument("Hex number too short");
    }

    if (s[0] == '-') {
        negative = true;
        start = 1;
    } else if (s[0] == '+') {
        start = 1;
    }
    
    if (s[start] != '0' || (s[start+1] != 'x' && s[start+1] != 'X')) {
        throw std::invalid_argument("Hex number must start with 0x or 0X");
    }
    
    if (s.size() == start + 2) {
        throw std::invalid_argument("Empty hex number");
    }
    
    for (size_t i = start + 2; i < s.size(); ++i) {
        char c = s[i];
        if (!isxdigit(c)) 
            throw std::invalid_argument("Invalid hex digit: " + std::string(1, c));
    }
    
    long val = strtol(s.c_str(), nullptr, 16);
    if (val > INT16_MAX || val < INT16_MIN) 
        throw std::out_of_range("Hex number out of int16_t range");
    

    return static_cast<int16_t>(val);
}

std::string check_for_listing_flags(int16_t number) {
    std::string spec_signs = " ";
    if(is_at)
        spec_signs += "@";
    if(is_numsign)
        spec_signs += "#";
    if(is_minus)
        spec_signs += "-";
    if(number)
        spec_signs += std::to_string(number);
    if(is_left)
        spec_signs += "(";
    is_at = is_numsign = is_minus = is_left =  false;
    
    return spec_signs;
}
