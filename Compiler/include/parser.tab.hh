// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file include/parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_INCLUDE_PARSER_TAB_HH_INCLUDED
# define YY_YY_INCLUDE_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 11 "src/parser.yy"

    #include <cctype>
    #include <iomanip>
    #include <fstream>
    #include "structure.hh"
    class Mediator;
    class Validator;
    class ListMaker;
  
    int16_t parse_oct(const std::string&);
    int16_t parse_hex(const std::string&);
    std::string check_for_listing_flags(int16_t);



#line 65 "include/parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 205 "include/parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // adressingS
      // adressingD
      char dummy1[sizeof (Operand)];

      // "decnum"
      char dummy2[sizeof (int)];

      // notreg
      // equ_expr
      // word_value
      // number
      // prereg
      // prelp
      char dummy3[sizeof (int16_t)];

      // byte_value
      char dummy4[sizeof (int8_t)];

      // "instruction"
      // "comment"
      // "newline"
      // "branch"
      // "register"
      // "label"
      // "port"
      // "directive_EQU"
      // "directive_BYTE"
      // "directive_WORD"
      // "data_seg"
      // "code_seg"
      // "char_literal"
      // "at"
      // "numsign"
      // "lparen"
      // "rparen"
      // "minus"
      // "plus"
      // "hexnum"
      // "octnum"
      // "mult"
      // "div"
      // "mod"
      // "lshift"
      // "rshift"
      // "band"
      // "bor"
      // "bxor"
      // "ascii"
      // "asciiz"
      // "string_literal"
      // expr
      // postreg
      char dummy5[sizeof (std::string)];

      // word_expr
      char dummy6[sizeof (std::vector<int16_t>)];

      // byte_expr
      char dummy7[sizeof (std::vector<int8_t>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_YYEOF = 0,                 // "end of file"
    TOK_YYerror = 1,               // error
    TOK_YYUNDEF = 2,               // "invalid token"
    TOK_COMMA = 3,                 // ","
    TOK_INSTRUCTION = 4,           // "instruction"
    TOK_COMMENT = 5,               // "comment"
    TOK_NEWLINE = 6,               // "newline"
    TOK_BRANCH = 7,                // "branch"
    TOK_REGISTER = 8,              // "register"
    TOK_LABEL = 9,                 // "label"
    TOK_PORT = 10,                 // "port"
    TOK_EQU_DIRECTIVE = 11,        // "directive_EQU"
    TOK_BYTE_DIRECTIVE = 12,       // "directive_BYTE"
    TOK_WORD_DIRECTIVE = 13,       // "directive_WORD"
    TOK_DATA_S = 14,               // "data_seg"
    TOK_CODE_S = 15,               // "code_seg"
    TOK_CHAR_LITERAL = 16,         // "char_literal"
    TOK_AT = 17,                   // "at"
    TOK_NUMSIGN = 18,              // "numsign"
    TOK_LPAREN = 19,               // "lparen"
    TOK_RPAREN = 20,               // "rparen"
    TOK_MINUS = 21,                // "minus"
    TOK_PLUS = 22,                 // "plus"
    TOK_HEX_NUM = 23,              // "hexnum"
    TOK_OCT_NUM = 24,              // "octnum"
    TOK_MULT = 25,                 // "mult"
    TOK_DIV = 26,                  // "div"
    TOK_MOD = 27,                  // "mod"
    TOK_LSHIFT = 28,               // "lshift"
    TOK_RSHIFT = 29,               // "rshift"
    TOK_BAND = 30,                 // "band"
    TOK_BOR = 31,                  // "bor"
    TOK_BXOR = 32,                 // "bxor"
    TOK_ASCII_DIRECTIVE = 33,      // "ascii"
    TOK_ASCIIZ_DIRECTIVE = 34,     // "asciiz"
    TOK_STRING_LITERAL = 35,       // "string_literal"
    TOK_DEC_NUM = 36,              // "decnum"
    TOK_UMINUS = 37                // UMINUS
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 38, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_COMMA = 3,                             // ","
        S_INSTRUCTION = 4,                       // "instruction"
        S_COMMENT = 5,                           // "comment"
        S_NEWLINE = 6,                           // "newline"
        S_BRANCH = 7,                            // "branch"
        S_REGISTER = 8,                          // "register"
        S_LABEL = 9,                             // "label"
        S_PORT = 10,                             // "port"
        S_EQU_DIRECTIVE = 11,                    // "directive_EQU"
        S_BYTE_DIRECTIVE = 12,                   // "directive_BYTE"
        S_WORD_DIRECTIVE = 13,                   // "directive_WORD"
        S_DATA_S = 14,                           // "data_seg"
        S_CODE_S = 15,                           // "code_seg"
        S_CHAR_LITERAL = 16,                     // "char_literal"
        S_AT = 17,                               // "at"
        S_NUMSIGN = 18,                          // "numsign"
        S_LPAREN = 19,                           // "lparen"
        S_RPAREN = 20,                           // "rparen"
        S_MINUS = 21,                            // "minus"
        S_PLUS = 22,                             // "plus"
        S_HEX_NUM = 23,                          // "hexnum"
        S_OCT_NUM = 24,                          // "octnum"
        S_MULT = 25,                             // "mult"
        S_DIV = 26,                              // "div"
        S_MOD = 27,                              // "mod"
        S_LSHIFT = 28,                           // "lshift"
        S_RSHIFT = 29,                           // "rshift"
        S_BAND = 30,                             // "band"
        S_BOR = 31,                              // "bor"
        S_BXOR = 32,                             // "bxor"
        S_ASCII_DIRECTIVE = 33,                  // "ascii"
        S_ASCIIZ_DIRECTIVE = 34,                 // "asciiz"
        S_STRING_LITERAL = 35,                   // "string_literal"
        S_DEC_NUM = 36,                          // "decnum"
        S_UMINUS = 37,                           // UMINUS
        S_YYACCEPT = 38,                         // $accept
        S_program1 = 39,                         // program1
        S_input = 40,                            // input
        S_line = 41,                             // line
        S_expr = 42,                             // expr
        S_adressingS = 43,                       // adressingS
        S_adressingD = 44,                       // adressingD
        S_notreg = 45,                           // notreg
        S_equ_expr = 46,                         // equ_expr
        S_byte_expr = 47,                        // byte_expr
        S_byte_value = 48,                       // byte_value
        S_word_expr = 49,                        // word_expr
        S_word_value = 50,                       // word_value
        S_number = 51,                           // number
        S_prereg = 52,                           // prereg
        S_postreg = 53,                          // postreg
        S_prelp = 54                             // prelp
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.move< Operand > (std::move (that.value));
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.move< int16_t > (std::move (that.value));
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.move< int8_t > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.move< std::vector<int16_t> > (std::move (that.value));
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.move< std::vector<int8_t> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Operand&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Operand& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int16_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int16_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int8_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int8_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<int16_t>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<int16_t>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<int8_t>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<int8_t>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.template destroy< Operand > ();
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.template destroy< int > ();
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.template destroy< int16_t > ();
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.template destroy< int8_t > ();
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
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.template destroy< std::vector<int16_t> > ();
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.template destroy< std::vector<int8_t> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_YYEOF
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_COMMA)
                   || tok == token::TOK_UMINUS);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_DEC_NUM);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_INSTRUCTION <= tok && tok <= token::TOK_STRING_LITERAL));
#endif
      }
    };

    /// Build a parser object.
    parser (Mediator& m_yyarg, Validator& valid_yyarg, ListMaker& list_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::TOK_YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::TOK_YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSTRUCTION (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INSTRUCTION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INSTRUCTION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INSTRUCTION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_COMMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_COMMENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NEWLINE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NEWLINE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BRANCH (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BRANCH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BRANCH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BRANCH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REGISTER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_REGISTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REGISTER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_REGISTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LABEL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LABEL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LABEL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LABEL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PORT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQU_DIRECTIVE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EQU_DIRECTIVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQU_DIRECTIVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EQU_DIRECTIVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYTE_DIRECTIVE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BYTE_DIRECTIVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BYTE_DIRECTIVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BYTE_DIRECTIVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORD_DIRECTIVE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_WORD_DIRECTIVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WORD_DIRECTIVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_WORD_DIRECTIVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DATA_S (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DATA_S, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DATA_S (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DATA_S, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CODE_S (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CODE_S, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CODE_S (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CODE_S, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHAR_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHAR_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_AT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_AT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMSIGN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NUMSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NUMSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEX_NUM (std::string v, location_type l)
      {
        return symbol_type (token::TOK_HEX_NUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEX_NUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_HEX_NUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OCT_NUM (std::string v, location_type l)
      {
        return symbol_type (token::TOK_OCT_NUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OCT_NUM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_OCT_NUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSHIFT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSHIFT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSHIFT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RSHIFT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSHIFT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RSHIFT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BAND (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BAND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BXOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BXOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BXOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BXOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASCII_DIRECTIVE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ASCII_DIRECTIVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASCII_DIRECTIVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ASCII_DIRECTIVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASCIIZ_DIRECTIVE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ASCIIZ_DIRECTIVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASCIIZ_DIRECTIVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ASCIIZ_DIRECTIVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEC_NUM (int v, location_type l)
      {
        return symbol_type (token::TOK_DEC_NUM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEC_NUM (const int& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEC_NUM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::TOK_UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::TOK_UMINUS, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;



    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 164,     ///< Last index in yytable_.
      yynnts_ = 17,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    Mediator& m;
    Validator& valid;
    ListMaker& list;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.copy< Operand > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.copy< int16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.copy< int8_t > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.copy< std::vector<int16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.copy< std::vector<int8_t> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_adressingS: // adressingS
      case symbol_kind::S_adressingD: // adressingD
        value.move< Operand > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DEC_NUM: // "decnum"
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_notreg: // notreg
      case symbol_kind::S_equ_expr: // equ_expr
      case symbol_kind::S_word_value: // word_value
      case symbol_kind::S_number: // number
      case symbol_kind::S_prereg: // prereg
      case symbol_kind::S_prelp: // prelp
        value.move< int16_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_byte_value: // byte_value
        value.move< int8_t > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_word_expr: // word_expr
        value.move< std::vector<int16_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_byte_expr: // byte_expr
        value.move< std::vector<int8_t> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2306 "include/parser.tab.hh"




#endif // !YY_YY_INCLUDE_PARSER_TAB_HH_INCLUDED
