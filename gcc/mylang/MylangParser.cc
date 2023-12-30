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
#include "GenericFunction.h"
#include "GeneratorUtils.h"
#include "GenericBlock.h"
#include "GenericStatementList.h"
#include "MyIO.h"

std::map<std::string, tree> sym;
GenericFunction* currentFunction = NULL;
tree* bind_expr;
GenericStatementList* current_stmt_list = NULL;

#line 80 "MylangParser.cc"


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

#line 46 "mylang.yy"
namespace mylang {
#line 159 "MylangParser.cc"

  /// Build a parser object.
  MylangParser::MylangParser (yyscan_t scanner_yyarg, tree  &mainfunc_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      mainfunc (mainfunc_yyarg)
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
      case symbol_kind::S_block: // block
        value.copy< GenericBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.copy< GenericStatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.copy< std::vector<tree> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.copy< tree > (YY_MOVE (that.value));
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
      case symbol_kind::S_block: // block
        value.move< GenericBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< GenericStatementList* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<tree> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.move< tree > (YY_MOVE (s.value));
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
      case symbol_kind::S_block: // block
        value.YY_MOVE_OR_COPY< GenericBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.YY_MOVE_OR_COPY< GenericStatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<tree> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< tree > (YY_MOVE (that.value));
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
      case symbol_kind::S_block: // block
        value.move< GenericBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< GenericStatementList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<tree> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.move< tree > (YY_MOVE (that.value));
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
      case symbol_kind::S_block: // block
        value.copy< GenericBlock* > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.copy< GenericStatementList* > (that.value);
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.copy< std::vector<tree> > (that.value);
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.copy< tree > (that.value);
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
      case symbol_kind::S_block: // block
        value.move< GenericBlock* > (that.value);
        break;

      case symbol_kind::S_statement_list: // statement_list
        value.move< GenericStatementList* > (that.value);
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_args: // args
        value.move< std::vector<tree> > (that.value);
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        value.move< tree > (that.value);
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
      case symbol_kind::S_block: // block
        yylhs.value.emplace< GenericBlock* > ();
        break;

      case symbol_kind::S_statement_list: // statement_list
        yylhs.value.emplace< GenericStatementList* > ();
        break;

      case symbol_kind::S_INTLITERAL: // INTLITERAL
      case symbol_kind::S_FLOATLITERAL: // FLOATLITERAL
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<tree> > ();
        break;

      case symbol_kind::S_datatype: // datatype
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< tree > ();
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
  case 2: // program: function
#line 93 "mylang.yy"
                            {
                                std::cout << "Matched function" <<std::endl;
                                //std::vector<GenericFunction*> functionList;
                                //functionList.push_back($1);
                                //mainfunc = functionList[1]->getFuncGenericTree();
                            }
#line 808 "MylangParser.cc"
    break;

  case 3: // program: program function
#line 99 "mylang.yy"
                            {
                                std::cout << "Matched program function" <<std::endl;
                            }
#line 816 "MylangParser.cc"
    break;

  case 4: // function: func_decl block
#line 103 "mylang.yy"
                           {
                                std::cout << "Matched func_decl block" <<std::endl;
                                currentFunction->addBlock(yystack_[0].value.as < GenericBlock* > ()->getBlockTree(),yystack_[0].value.as < GenericBlock* > ()->getBlockBindExpr());                    
                                mainfunc = currentFunction->getFuncGenericTree();
                            }
#line 826 "MylangParser.cc"
    break;

  case 5: // func_decl: datatype ID LPAREN args RPAREN
#line 110 "mylang.yy"
                                           {
                                                    std::cout << "Matched INT_TYPE ID LPAREN args RPAREN" <<std::endl;
                                                    currentFunction = new GenericFunction(yystack_[4].value.as < tree > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<tree> > ());
                                                }
#line 835 "MylangParser.cc"
    break;

  case 6: // datatype: INT_TYPE
#line 116 "mylang.yy"
                    {yylhs.value.as < tree > () = integer_type_node;}
#line 841 "MylangParser.cc"
    break;

  case 7: // datatype: FLOAT_TYPE
#line 117 "mylang.yy"
                        {yylhs.value.as < tree > () = float_type_node;}
#line 847 "MylangParser.cc"
    break;

  case 8: // datatype: BOOLEAN_TYPE
#line 118 "mylang.yy"
                         {yylhs.value.as < tree > () = boolean_type_node;}
#line 853 "MylangParser.cc"
    break;

  case 9: // args: %empty
#line 121 "mylang.yy"
                        {
                            std::cout << "Matched Empty args" << std::endl;
                            yylhs.value.as < std::vector<tree> > ().clear();
                        }
#line 862 "MylangParser.cc"
    break;

  case 10: // args: datatype ID
#line 125 "mylang.yy"
                        {
                            std::cout << "Matched INT_TYPE ID" << std::endl;
                            yylhs.value.as < std::vector<tree> > ().push_back(yystack_[1].value.as < tree > ());
                        }
#line 871 "MylangParser.cc"
    break;

  case 11: // args: args COMMA datatype ID
#line 129 "mylang.yy"
                                    {
                                        std::cout << "Matched args COMMA INT_TYPE ID" << std::endl;
                                        yylhs.value.as < std::vector<tree> > ().push_back(yystack_[1].value.as < tree > ());
                                    }
#line 880 "MylangParser.cc"
    break;

  case 12: // block: LBRACE statement_list RBRACE
#line 135 "mylang.yy"
                                        {
                                            std::cout << "Matched LBRACE statement_list RBRACE" << std::endl;
                                            yylhs.value.as < GenericBlock* > () = new GenericBlock(yystack_[1].value.as < GenericStatementList* > ()->getStmtList());
                                        }
#line 889 "MylangParser.cc"
    break;

  case 13: // statement_list: %empty
#line 140 "mylang.yy"
                            {
                                std::cout << "Matched Empty statement_list" << std::endl;
                                yylhs.value.as < GenericStatementList* > () = new GenericStatementList();
                                                            }
#line 898 "MylangParser.cc"
    break;

  case 14: // statement_list: statement_list statement
#line 144 "mylang.yy"
                                    {
                                        std::cout << "Matched statement_list statement" << std::endl;
                                        yystack_[1].value.as < GenericStatementList* > ()->addStatement(yystack_[0].value.as < tree > ());
                                        yylhs.value.as < GenericStatementList* > ()=yystack_[1].value.as < GenericStatementList* > ();
                                                                            }
#line 908 "MylangParser.cc"
    break;

  case 15: // statement: expr SEMICOLON
#line 151 "mylang.yy"
           { yylhs.value.as < tree > () = yystack_[1].value.as < tree > (); }
#line 914 "MylangParser.cc"
    break;

  case 16: // statement: datatype ID SEMICOLON
#line 152 "mylang.yy"
                                    { 
                                        std::cout << "Matched INT_TYPE ID SEMICOLON" << std::endl;
                                        tree varDecl = GeneratorUtils::generateVariableDeclaration("$2", yystack_[2].value.as < tree > ());
                                        sym[yystack_[1].value.as < std::string > ()] = varDecl;
                                        yylhs.value.as < tree > () = GeneratorUtils::generateDeclareExpr(sym[yystack_[1].value.as < std::string > ()]);
                                    }
#line 925 "MylangParser.cc"
    break;

  case 17: // statement: ID ASSIGN expr SEMICOLON
#line 158 "mylang.yy"
                                    { 
                                        std::cout << "Matched ID ASSIGN expr SEMICOLON" << std::endl;
                                        yylhs.value.as < tree > () = GeneratorUtils::generateAssignmentTree(sym[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < tree > ());
                                    }
#line 934 "MylangParser.cc"
    break;

  case 18: // statement: RETURN expr SEMICOLON
#line 162 "mylang.yy"
                                    {
                                        std::cout << "Matched RETURN expr SEMICOLON" << std::endl; 
                                        // return value
                                        tree retval = currentFunction->getFuncRetval();
                                        tree modify_retval = build2(MODIFY_EXPR,
                                                                    TREE_TYPE (retval),
                                                                    retval,
                                                                    yystack_[1].value.as < tree > ());
                                        yylhs.value.as < tree > () = build1(RETURN_EXPR,
                                                    TREE_TYPE (retval),
                                                    modify_retval);
                                    }
#line 951 "MylangParser.cc"
    break;

  case 19: // statement: WRITE ID SEMICOLON
#line 174 "mylang.yy"
                                    {
                                        std::cout << "Matched WRITE ID SEMICOLON" << std::endl;
                                        yylhs.value.as < tree > () = MyIO::Print(sym[yystack_[1].value.as < std::string > ()]);
                                    }
#line 960 "MylangParser.cc"
    break;

  case 20: // expr: ID
#line 180 "mylang.yy"
                    { 
                        std::cout << "Matched ID" << std::endl;
                        yylhs.value.as < tree > () = sym[yystack_[0].value.as < std::string > ()]; 
                    }
#line 969 "MylangParser.cc"
    break;

  case 21: // expr: INTLITERAL
#line 184 "mylang.yy"
                    { 
                        std::cout << "Matched INTLITERAL" << std::endl;
                        yylhs.value.as < tree > () = GeneratorUtils::generateIntConstant(std::string(yystack_[0].value.as < std::string > ()));
                    }
#line 978 "MylangParser.cc"
    break;

  case 22: // expr: FLOATLITERAL
#line 188 "mylang.yy"
                      { 
                        std::cout << "Matched FLOATLITERAL" << std::endl;
                        yylhs.value.as < tree > () = GeneratorUtils::generateFloatConstant(std::string(yystack_[0].value.as < std::string > ()));
                    }
#line 987 "MylangParser.cc"
    break;

  case 23: // expr: expr ADD expr
#line 192 "mylang.yy"
                    { yylhs.value.as < tree > () = GeneratorUtils::generateArithimaticBinaryOpTree('+',yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 993 "MylangParser.cc"
    break;

  case 24: // expr: expr MINUS expr
#line 193 "mylang.yy"
                      { yylhs.value.as < tree > () = GeneratorUtils::generateArithimaticBinaryOpTree('-',yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 999 "MylangParser.cc"
    break;

  case 25: // expr: expr MUL expr
#line 194 "mylang.yy"
                    { yylhs.value.as < tree > () = GeneratorUtils::generateArithimaticBinaryOpTree('*',yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1005 "MylangParser.cc"
    break;

  case 26: // expr: expr DIV expr
#line 195 "mylang.yy"
                    { yylhs.value.as < tree > () = GeneratorUtils::generateArithimaticBinaryOpTree('/',yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1011 "MylangParser.cc"
    break;

  case 27: // expr: expr LESS_THAN expr
#line 196 "mylang.yy"
                          { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::LESSER_THAN,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1017 "MylangParser.cc"
    break;

  case 28: // expr: expr GREATER_THAN expr
#line 197 "mylang.yy"
                             { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::GREATER_THAN,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1023 "MylangParser.cc"
    break;

  case 29: // expr: expr LESS_THAN_EQUAL expr
#line 198 "mylang.yy"
                                { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::LESSER_THAN_EQUAL,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1029 "MylangParser.cc"
    break;

  case 30: // expr: expr GREATER_THAN_EQUAL expr
#line 199 "mylang.yy"
                                   { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::GREATER_THAN_EQUAL,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1035 "MylangParser.cc"
    break;

  case 31: // expr: expr EQUAL expr
#line 200 "mylang.yy"
                      { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::EQUAL,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1041 "MylangParser.cc"
    break;

  case 32: // expr: expr NOT_EQUAL expr
#line 201 "mylang.yy"
                          { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::NOT_EQUAL,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1047 "MylangParser.cc"
    break;

  case 33: // expr: expr LOGICAL_AND expr
#line 202 "mylang.yy"
                            { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::AND,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1053 "MylangParser.cc"
    break;

  case 34: // expr: expr LOGICAL_OR expr
#line 203 "mylang.yy"
                           { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanBinaryOpTree(BooleanOpcode::OR,yystack_[2].value.as < tree > (), yystack_[0].value.as < tree > ()); }
#line 1059 "MylangParser.cc"
    break;

  case 35: // expr: LOGICAL_NOT expr
#line 204 "mylang.yy"
                       { yylhs.value.as < tree > () = GeneratorUtils::generateBooleanUnaryNotOpTree(yystack_[0].value.as < tree > ()); }
#line 1065 "MylangParser.cc"
    break;

  case 36: // expr: MINUS expr
#line 205 "mylang.yy"
                              { yylhs.value.as < tree > () = GeneratorUtils::generateArithimaticUnaryMinusOpTree(yystack_[0].value.as < tree > ()); }
#line 1071 "MylangParser.cc"
    break;

  case 37: // expr: LPAREN expr RPAREN
#line 206 "mylang.yy"
                         { yylhs.value.as < tree > () = yystack_[1].value.as < tree > (); }
#line 1077 "MylangParser.cc"
    break;


#line 1081 "MylangParser.cc"

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









  const signed char MylangParser::yypact_ninf_ = -14;

  const signed char MylangParser::yytable_ninf_ = -1;

  const short
  MylangParser::yypact_[] =
  {
      35,   -14,   -14,   -14,    58,   -14,    -9,    17,   -14,   -14,
     -14,   -14,     8,    -1,    35,   -14,   -14,     6,     5,     5,
     -14,     5,    24,     5,    27,   -14,    44,    33,    -6,     5,
     -14,    65,    86,   128,    29,   -14,    43,     5,     5,     5,
     -14,     5,     5,     5,     5,     5,     5,     5,     5,     5,
     -14,   -14,    35,   107,   -14,   -14,   -14,   -14,     4,   -14,
     -14,     0,     0,     0,     0,   173,   173,   167,   149,     4,
      62,   -14,   -14
  };

  const signed char
  MylangParser::yydefact_[] =
  {
       0,     8,     7,     6,     0,     2,     0,     0,     1,     3,
      13,     4,     0,     0,     9,    21,    22,    20,     0,     0,
      12,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      20,     0,     0,    35,     0,    36,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     5,     0,     0,    18,    37,    19,    16,    23,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    24,
       0,    17,    11
  };

  const signed char
  MylangParser::yypgoto_[] =
  {
     -14,   -14,    59,   -14,   -13,   -14,   -14,   -14,   -14,     7
  };

  const signed char
  MylangParser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,    28,    11,    13,    25,    26
  };

  const signed char
  MylangParser::yytable_[] =
  {
      24,    27,    15,    16,    17,     1,     2,     3,    15,    16,
      30,    18,    10,    37,    51,    38,    39,    52,    19,    38,
      39,    20,    12,    29,    19,    31,    32,    14,    33,    34,
      35,    21,    36,    22,    23,    49,    53,    21,    50,    70,
      23,     1,     2,     3,    58,    59,    60,    56,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    37,     8,    38,
      39,    57,    40,     9,     1,     2,     3,    72,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,    37,    49,
      38,    39,     0,    54,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    37,
      49,    38,    39,     0,     0,     0,    55,     0,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      37,    49,    38,    39,     0,    71,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    37,    49,    38,    39,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    37,    49,    38,    39,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      37,     0,    38,    39,    49,     0,    37,     0,    38,    39,
       0,    41,    42,    43,    44,    45,    46,    41,    42,    43,
      44,     0,    49,     0,     0,     0,     0,     0,    49
  };

  const signed char
  MylangParser::yycheck_[] =
  {
      13,    14,     3,     4,     5,     6,     7,     8,     3,     4,
       5,    12,    21,    13,    20,    15,    16,    23,    19,    15,
      16,    22,     5,    17,    19,    18,    19,    19,    21,     5,
      23,    32,     5,    34,    35,    35,    29,    32,     5,    52,
      35,     6,     7,     8,    37,    38,    39,    18,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    13,     0,    15,
      16,    18,    18,     4,     6,     7,     8,     5,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    13,    35,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    13,
      35,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      13,    35,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    13,    35,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    13,    35,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      13,    -1,    15,    16,    35,    -1,    13,    -1,    15,    16,
      -1,    24,    25,    26,    27,    28,    29,    24,    25,    26,
      27,    -1,    35,    -1,    -1,    -1,    -1,    -1,    35
  };

  const signed char
  MylangParser::yystos_[] =
  {
       0,     6,     7,     8,    38,    39,    40,    41,     0,    39,
      21,    43,     5,    44,    19,     3,     4,     5,    12,    19,
      22,    32,    34,    35,    41,    45,    46,    41,    42,    17,
       5,    46,    46,    46,     5,    46,     5,    13,    15,    16,
      18,    24,    25,    26,    27,    28,    29,    30,    31,    35,
       5,    20,    23,    46,    18,    20,    18,    18,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      41,    18,     5
  };

  const signed char
  MylangParser::yyr1_[] =
  {
       0,    37,    38,    38,    39,    40,    41,    41,    41,    42,
      42,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46
  };

  const signed char
  MylangParser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     5,     1,     1,     1,     0,
       2,     4,     3,     0,     2,     2,     3,     4,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const MylangParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTLITERAL",
  "FLOATLITERAL", "ID", "BOOLEAN_TYPE", "FLOAT_TYPE", "INT_TYPE", "IF",
  "ELSE", "WHILE", "RETURN", "ADD", "SUB", "MUL", "DIV", "ASSIGN",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COMMA",
  "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL",
  "EQUAL", "NOT_EQUAL", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "READ",
  "WRITE", "MINUS", "UMINUS", "$accept", "program", "function",
  "func_decl", "datatype", "args", "block", "statement_list", "statement",
  "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  MylangParser::yyrline_[] =
  {
       0,    93,    93,    99,   103,   110,   116,   117,   118,   121,
     125,   129,   135,   140,   144,   151,   152,   158,   162,   174,
     180,   184,   188,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
    };
    // Last valid token kind.
    const int code_max = 291;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 46 "mylang.yy"
} // mylang
#line 1505 "MylangParser.cc"

#line 209 "mylang.yy"

 
void mylang::MylangParser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
