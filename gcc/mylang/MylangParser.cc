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



// First part of user prologue.
#line 1 "mylang.yy"

#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "tree.h"
#include "gimple-expr.h"
#include "c-family/c-common.h"
#include "diagnostic.h"
#include "opts.h"
#include "fold-const.h"
#include "gimplify.h"
#include "stor-layout.h"
#include "debug.h"
#include "convert.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "common/common-target.h"
#include "tree-iterator.h"
#include "cgraph.h"
#include "context.h"
#include "tree-dump.h"
#include "MylangScanner.h"

std::map<std::string, int> sym;

#line 72 "MylangParser.cc"


#include "MylangParser.h"




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

#line 38 "mylang.yy"
namespace mylang {
#line 151 "MylangParser.cc"

  /// Build a parser object.
  MylangParser::MylangParser (yyscan_t scanner_yyarg, tree  &myroot_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      myroot (myroot_yyarg)
  {}

  MylangParser::~MylangParser ()
  {}

  MylangParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  MylangParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expr: // expr
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  MylangParser::symbol_kind_type
  MylangParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  MylangParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  MylangParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  MylangParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  MylangParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  MylangParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  MylangParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  MylangParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  MylangParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  MylangParser::symbol_kind_type
  MylangParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  MylangParser::symbol_kind_type
  MylangParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  MylangParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  MylangParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  MylangParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  MylangParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  MylangParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  MylangParser::symbol_kind_type
  MylangParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  MylangParser::stack_symbol_type::stack_symbol_type ()
  {}

  MylangParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  MylangParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  MylangParser::stack_symbol_type&
  MylangParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  MylangParser::stack_symbol_type&
  MylangParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expr: // expr
        value.move< int > (that.value);
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  MylangParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  MylangParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  MylangParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  MylangParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  MylangParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  MylangParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  MylangParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  MylangParser::debug_level_type
  MylangParser::debug_level () const
  {
    return yydebug_;
  }

  void
  MylangParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  MylangParser::state_type
  MylangParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  MylangParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  MylangParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  MylangParser::operator() ()
  {
    return parse ();
  }

  int
  MylangParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
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
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
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
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 12: // statement: INT_TYPE ID SEMICOLON
#line 95 "mylang.yy"
                                 { sym[yystack_[1].value.as < std::string > ()] = 0; }
#line 697 "MylangParser.cc"
    break;

  case 13: // statement: ID ASSIGN expr SEMICOLON
#line 96 "mylang.yy"
                                    { sym[yystack_[3].value.as < std::string > ()] = yystack_[1].value.as < int > (); }
#line 703 "MylangParser.cc"
    break;

  case 18: // statement: WRITE ID SEMICOLON
#line 101 "mylang.yy"
                              {std::cout <<sym[yystack_[1].value.as < std::string > ()] <<"\n";}
#line 709 "MylangParser.cc"
    break;

  case 19: // expr: ID
#line 104 "mylang.yy"
         { yylhs.value.as < int > () = sym[yystack_[0].value.as < std::string > ()]; }
#line 715 "MylangParser.cc"
    break;

  case 20: // expr: INTLITERAL
#line 105 "mylang.yy"
                 { yylhs.value.as < int > () = strtoll(yystack_[0].value.as < std::string > ().c_str(), nullptr, 10);}
#line 721 "MylangParser.cc"
    break;

  case 21: // expr: expr ADD expr
#line 106 "mylang.yy"
                    { yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > (); }
#line 727 "MylangParser.cc"
    break;

  case 22: // expr: expr SUB expr
#line 107 "mylang.yy"
                    { yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > (); }
#line 733 "MylangParser.cc"
    break;

  case 23: // expr: expr MUL expr
#line 108 "mylang.yy"
                    { yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > (); }
#line 739 "MylangParser.cc"
    break;

  case 24: // expr: expr DIV expr
#line 109 "mylang.yy"
                    { yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > (); }
#line 745 "MylangParser.cc"
    break;

  case 25: // expr: expr LESS_THAN expr
#line 110 "mylang.yy"
                          { yylhs.value.as < int > () = yystack_[2].value.as < int > () < yystack_[0].value.as < int > (); }
#line 751 "MylangParser.cc"
    break;

  case 26: // expr: expr GREATER_THAN expr
#line 111 "mylang.yy"
                             { yylhs.value.as < int > () = yystack_[2].value.as < int > () > yystack_[0].value.as < int > (); }
#line 757 "MylangParser.cc"
    break;

  case 27: // expr: expr LESS_THAN_EQUAL expr
#line 112 "mylang.yy"
                                { yylhs.value.as < int > () = yystack_[2].value.as < int > () <= yystack_[0].value.as < int > (); }
#line 763 "MylangParser.cc"
    break;

  case 28: // expr: expr GREATER_THAN_EQUAL expr
#line 113 "mylang.yy"
                                   { yylhs.value.as < int > () = yystack_[2].value.as < int > () >= yystack_[0].value.as < int > (); }
#line 769 "MylangParser.cc"
    break;

  case 29: // expr: expr EQUAL expr
#line 114 "mylang.yy"
                      { yylhs.value.as < int > () = yystack_[2].value.as < int > () == yystack_[0].value.as < int > (); }
#line 775 "MylangParser.cc"
    break;

  case 30: // expr: expr NOT_EQUAL expr
#line 115 "mylang.yy"
                          { yylhs.value.as < int > () = yystack_[2].value.as < int > () != yystack_[0].value.as < int > (); }
#line 781 "MylangParser.cc"
    break;

  case 31: // expr: expr LOGICAL_AND expr
#line 116 "mylang.yy"
                            { yylhs.value.as < int > () = yystack_[2].value.as < int > () && yystack_[0].value.as < int > (); }
#line 787 "MylangParser.cc"
    break;

  case 32: // expr: expr LOGICAL_OR expr
#line 117 "mylang.yy"
                           { yylhs.value.as < int > () = yystack_[2].value.as < int > () || yystack_[0].value.as < int > (); }
#line 793 "MylangParser.cc"
    break;

  case 33: // expr: LOGICAL_NOT expr
#line 118 "mylang.yy"
                       { yylhs.value.as < int > () = !yystack_[0].value.as < int > (); }
#line 799 "MylangParser.cc"
    break;

  case 34: // expr: LPAREN expr RPAREN
#line 119 "mylang.yy"
                         { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 805 "MylangParser.cc"
    break;


#line 809 "MylangParser.cc"

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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


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

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
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
  MylangParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  MylangParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char MylangParser::yypact_ninf_ = -63;

  const signed char MylangParser::yytable_ninf_ = -1;

  const short
  MylangParser::yypact_[] =
  {
       4,    -4,     5,   -63,     3,   -63,   -63,    20,    23,    49,
     -63,    11,    48,   -63,   -63,    64,    -3,   -63,   -63,    56,
      67,    69,    70,    18,    18,   -63,    18,    68,   -63,    33,
      18,    72,    18,    18,   -63,    52,    71,   147,    74,    18,
      18,    18,    18,   -63,    18,    18,    18,    18,    18,    18,
      18,    18,    90,   -63,   109,   128,   -63,   -63,   -63,    -5,
      -5,   -63,   -63,    39,    39,    39,    39,   190,   190,   173,
     166,   -63,    73,    86,    11,    11,    87,    88,    83,   -63,
      91,    11,    89,   -63
  };

  const signed char
  MylangParser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     3,     5,     0,     0,
       6,     0,     0,     9,     4,     0,     0,     7,    20,    19,
       0,     0,     0,     0,     0,     8,     0,     0,    10,     0,
       0,     0,     0,     0,    19,     0,     0,    33,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,    17,    34,    18,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    13,     0,     0,     0,     0,     0,     0,    14,    16,
       0,     0,     0,    15
  };

  const signed char
  MylangParser::yypgoto_[] =
  {
     -63,   -63,   122,   -63,   -62,   -63,   -63,    -8
  };

  const signed char
  MylangParser::yydefgoto_[] =
  {
       0,     2,     3,     9,    14,    16,    28,    29
  };

  const signed char
  MylangParser::yytable_[] =
  {
      18,     4,    19,    20,    21,     5,    22,    23,    41,    42,
       1,     1,    76,    77,    24,    35,    36,    25,    37,    82,
       7,    18,    52,    34,    54,    55,     8,    26,    10,    27,
      13,    59,    60,    61,    62,    24,    63,    64,    65,    66,
      67,    68,    69,    70,    39,    40,    41,    42,    26,    43,
      39,    40,    41,    42,    15,    44,    45,    46,    47,    48,
      49,    50,    51,    39,    40,    41,    42,    11,    56,    17,
      12,    30,    31,    38,    44,    45,    46,    47,    48,    49,
      50,    51,    39,    40,    41,    42,    32,    33,    53,    57,
      58,    80,    74,    44,    45,    46,    47,    48,    49,    50,
      51,    39,    40,    41,    42,    75,    71,    78,    79,    83,
      81,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      39,    40,    41,    42,     6,     0,     0,    72,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    39,
      40,    41,    42,     0,     0,     0,    73,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    39,    40,    41,
      42,     0,     0,     0,    39,    40,    41,    42,    44,    45,
      46,    47,    48,    49,    50,    44,    45,    46,    47,    48,
      49,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    46,    47
  };

  const signed char
  MylangParser::yycheck_[] =
  {
       3,     5,     5,     6,     7,     0,     9,    10,    13,    14,
       6,     6,    74,    75,    17,    23,    24,    20,    26,    81,
      17,     3,    30,     5,    32,    33,     6,    30,     5,    32,
      19,    39,    40,    41,    42,    17,    44,    45,    46,    47,
      48,    49,    50,    51,    11,    12,    13,    14,    30,    16,
      11,    12,    13,    14,     6,    22,    23,    24,    25,    26,
      27,    28,    29,    11,    12,    13,    14,    18,    16,     5,
      21,    15,     5,     5,    22,    23,    24,    25,    26,    27,
      28,    29,    11,    12,    13,    14,    17,    17,    16,    18,
      16,     8,    19,    22,    23,    24,    25,    26,    27,    28,
      29,    11,    12,    13,    14,    19,    16,    20,    20,    20,
      19,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      11,    12,    13,    14,     2,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    -1,    -1,    -1,    11,    12,    13,    14,    22,    23,
      24,    25,    26,    27,    28,    22,    23,    24,    25,    26,
      27,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25
  };

  const signed char
  MylangParser::yystos_[] =
  {
       0,     6,    35,    36,     5,     0,    36,    17,     6,    37,
       5,    18,    21,    19,    38,     6,    39,     5,     3,     5,
       6,     7,     9,    10,    17,    20,    30,    32,    40,    41,
      15,     5,    17,    17,     5,    41,    41,    41,     5,    11,
      12,    13,    14,    16,    22,    23,    24,    25,    26,    27,
      28,    29,    41,    16,    41,    41,    16,    18,    16,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    16,    18,    18,    19,    19,    38,    38,    20,    20,
       8,    19,    38,    20
  };

  const signed char
  MylangParser::yyr1_[] =
  {
       0,    34,    35,    35,    36,    37,    37,    37,    38,    39,
      39,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41
  };

  const signed char
  MylangParser::yyr2_[] =
  {
       0,     2,     1,     2,     6,     0,     2,     4,     3,     0,
       2,     2,     3,     4,     7,    11,     7,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const MylangParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTLITERAL",
  "FLOATLITERAL", "ID", "INT_TYPE", "IF", "ELSE", "WHILE", "RETURN", "ADD",
  "SUB", "MUL", "DIV", "ASSIGN", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "COMMA", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL",
  "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "LOGICAL_AND", "LOGICAL_OR",
  "LOGICAL_NOT", "READ", "WRITE", "UNARY_OP", "$accept", "program",
  "function", "args", "block", "statement_list", "statement", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  MylangParser::yyrline_[] =
  {
       0,    78,    78,    79,    81,    83,    84,    85,    88,    90,
      91,    94,    95,    96,    97,    98,    99,   100,   101,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119
  };

  void
  MylangParser::yy_stack_print_ () const
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
  MylangParser::yy_reduce_print_ (int yyrule) const
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

  MylangParser::symbol_kind_type
  MylangParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    // Last valid token kind.
    const int code_max = 288;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 38 "mylang.yy"
} // mylang
#line 1235 "MylangParser.cc"

#line 122 "mylang.yy"

 
void mylang::MylangParser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
