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
#line 31 "parser.y"

#include "ast.h"
extern ASTPtr ast_root;
void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

#line 49 "parser.tab.cc"


#include "parser.tab.hh"




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

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.copy< ASTPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.move< ASTPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< ASTPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.move< ASTPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.copy< ASTPtr > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        value.move< ASTPtr > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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
      case symbol_kind::S_program: // program
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_simple_stmt: // simple_stmt
      case symbol_kind::S_block_stmt: // block_stmt
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< ASTPtr > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
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
  case 2: // program: stmt_list
#line 57 "parser.y"
                                      { ast_root = yystack_[0].value.as < ASTPtr > (); }
#line 738 "parser.tab.cc"
    break;

  case 3: // stmt_list: stmt_list stmt
#line 61 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_stmt_list(yystack_[1].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 744 "parser.tab.cc"
    break;

  case 4: // stmt_list: stmt
#line 62 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_stmt_list(nullptr, yystack_[0].value.as < ASTPtr > ()); }
#line 750 "parser.tab.cc"
    break;

  case 5: // stmt: simple_stmt
#line 66 "parser.y"
    { yylhs.value.as < ASTPtr > () = yystack_[0].value.as < ASTPtr > (); }
#line 756 "parser.tab.cc"
    break;

  case 6: // stmt: block_stmt
#line 67 "parser.y"
    { yylhs.value.as < ASTPtr > () = yystack_[0].value.as < ASTPtr > (); }
#line 762 "parser.tab.cc"
    break;

  case 7: // simple_stmt: ID ASSIGN expr SEMICOLON
#line 71 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_assign(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ASTPtr > ()); }
#line 768 "parser.tab.cc"
    break;

  case 8: // simple_stmt: INT_TYPE ID SEMICOLON
#line 72 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_decl("int", yystack_[1].value.as < std::string > ()); }
#line 774 "parser.tab.cc"
    break;

  case 9: // simple_stmt: STRING_TYPE ID SEMICOLON
#line 73 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_decl("string", yystack_[1].value.as < std::string > ()); }
#line 780 "parser.tab.cc"
    break;

  case 10: // simple_stmt: PRINT expr SEMICOLON
#line 74 "parser.y"
                                      { yylhs.value.as < ASTPtr > () = new_print(yystack_[1].value.as < ASTPtr > ()); }
#line 786 "parser.tab.cc"
    break;

  case 11: // simple_stmt: IF LPAREN expr RPAREN stmt ELSE stmt
#line 76 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_if_else(yystack_[4].value.as < ASTPtr > (), yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 792 "parser.tab.cc"
    break;

  case 12: // simple_stmt: IF LPAREN expr RPAREN stmt
#line 78 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_if(yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 798 "parser.tab.cc"
    break;

  case 13: // simple_stmt: WHILE LPAREN expr RPAREN stmt
#line 79 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_while(yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 804 "parser.tab.cc"
    break;

  case 14: // block_stmt: LBRACE stmt_list RBRACE
#line 83 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = yystack_[1].value.as < ASTPtr > (); }
#line 810 "parser.tab.cc"
    break;

  case 15: // block_stmt: error SEMICOLON
#line 84 "parser.y"
                                       { yyerrok; yylhs.value.as < ASTPtr > () = nullptr; }
#line 816 "parser.tab.cc"
    break;

  case 16: // expr: expr PLUS expr
#line 88 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("+", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 822 "parser.tab.cc"
    break;

  case 17: // expr: expr MINUS expr
#line 89 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("-", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 828 "parser.tab.cc"
    break;

  case 18: // expr: expr MUL expr
#line 90 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("*", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 834 "parser.tab.cc"
    break;

  case 19: // expr: expr DIV expr
#line 91 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("/", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 840 "parser.tab.cc"
    break;

  case 20: // expr: expr EQ expr
#line 92 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("==", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 846 "parser.tab.cc"
    break;

  case 21: // expr: expr NEQ expr
#line 93 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("!=", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 852 "parser.tab.cc"
    break;

  case 22: // expr: expr LT expr
#line 94 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("<", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 858 "parser.tab.cc"
    break;

  case 23: // expr: expr GT expr
#line 95 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop(">", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 864 "parser.tab.cc"
    break;

  case 24: // expr: expr LE expr
#line 96 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("<=", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 870 "parser.tab.cc"
    break;

  case 25: // expr: expr GE expr
#line 97 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop(">=", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 876 "parser.tab.cc"
    break;

  case 26: // expr: expr AND expr
#line 98 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("and", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 882 "parser.tab.cc"
    break;

  case 27: // expr: expr OR expr
#line 99 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_binop("or", yystack_[2].value.as < ASTPtr > (), yystack_[0].value.as < ASTPtr > ()); }
#line 888 "parser.tab.cc"
    break;

  case 28: // expr: NOT expr
#line 100 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_unop("not", yystack_[0].value.as < ASTPtr > ()); }
#line 894 "parser.tab.cc"
    break;

  case 29: // expr: LPAREN expr RPAREN
#line 101 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = yystack_[1].value.as < ASTPtr > (); }
#line 900 "parser.tab.cc"
    break;

  case 30: // expr: ID
#line 102 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_var(yystack_[0].value.as < std::string > ()); }
#line 906 "parser.tab.cc"
    break;

  case 31: // expr: INT
#line 103 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_int(yystack_[0].value.as < int > ()); }
#line 912 "parser.tab.cc"
    break;

  case 32: // expr: STRING
#line 104 "parser.y"
                                       { yylhs.value.as < ASTPtr > () = new_string(yystack_[0].value.as < std::string > ()); }
#line 918 "parser.tab.cc"
    break;


#line 922 "parser.tab.cc"

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  Parser::yy_lac_check_ (symbol_kind_type yytoken) const
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
  Parser::yy_lac_establish_ (symbol_kind_type yytoken)
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
  Parser::yy_lac_discard_ (const char* event)
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
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  Parser::yysyntax_error_ (const context& yyctx) const
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


  const signed char Parser::yypact_ninf_ = -26;

  const signed char Parser::yytable_ninf_ = -3;

  const short
  Parser::yypact_[] =
  {
      63,   -25,   -13,   -17,   -16,    29,     7,     8,    63,    14,
      38,   -26,   -26,   -26,   -26,    29,    29,    29,   -26,   -26,
     -26,    29,    29,    70,   -12,     1,    50,   -26,   -26,    86,
     102,   118,   -26,   134,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,   -26,   -26,   -26,   -26,
     -26,    63,    63,   -26,   159,   148,   170,   170,   179,   179,
     179,   179,   -21,   -21,   -26,   -26,     9,   -26,    63,   -26
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,    15,     0,     0,     0,    31,    30,
      32,     0,     0,     0,     0,     0,     0,     1,     3,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     8,     9,    14,
       7,     0,     0,    29,    26,    27,    20,    21,    24,    25,
      22,    23,    16,    17,    18,    19,    12,    13,     0,    11
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -26,   -26,    10,   -10,   -26,   -26,   -14
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     9,    10,    11,    12,    13,    23
  };

  const signed char
  Parser::yytable_[] =
  {
      28,    29,    30,    31,    44,    45,    14,    32,    33,    15,
      16,    17,    24,    25,    27,     0,    28,    68,    26,    47,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    48,    18,    19,    20,     0,     0,    -2,     1,
       0,    66,    67,     2,    21,     3,     0,     4,     5,     6,
       7,     1,     0,     0,     0,     2,    22,     3,    69,     4,
       5,     6,     7,     0,     1,     0,     0,     8,     2,     0,
       3,     0,     4,     5,     6,     7,     0,     0,     0,     8,
      49,     0,     0,    34,    35,     0,    36,    37,    38,    39,
      40,    41,     8,    42,    43,    44,    45,     0,     0,    34,
      35,    46,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,     0,     0,    34,    35,    50,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,     0,
      51,    34,    35,     0,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,     0,    52,    34,    35,     0,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    34,    53,     0,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    -3,    -3,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    -3,    -3,    -3,
      -3,     0,    42,    43,    44,    45
  };

  const signed char
  Parser::yycheck_[] =
  {
      10,    15,    16,    17,    25,    26,    31,    21,    22,    22,
      27,    27,     5,     5,     0,    -1,    26,     8,     8,    31,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    31,     4,     5,     6,    -1,    -1,     0,     1,
      -1,    51,    52,     5,    15,     7,    -1,     9,    10,    11,
      12,     1,    -1,    -1,    -1,     5,    27,     7,    68,     9,
      10,    11,    12,    -1,     1,    -1,    -1,    29,     5,    -1,
       7,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    29,
      30,    -1,    -1,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    29,    23,    24,    25,    26,    -1,    -1,    13,
      14,    31,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    -1,    -1,    13,    14,    31,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    -1,
      28,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    -1,    28,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    13,    28,    -1,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    18,    19,    20,
      21,    -1,    23,    24,    25,    26
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     5,     7,     9,    10,    11,    12,    29,    34,
      35,    36,    37,    38,    31,    22,    27,    27,     4,     5,
       6,    15,    27,    39,     5,     5,    35,     0,    36,    39,
      39,    39,    39,    39,    13,    14,    16,    17,    18,    19,
      20,    21,    23,    24,    25,    26,    31,    31,    31,    30,
      31,    28,    28,    28,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    36,    36,     8,    36
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       3,     7,     5,     5,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LOWER_THAN_ELSE",
  "INT", "ID", "STRING", "IF", "ELSE", "WHILE", "PRINT", "INT_TYPE",
  "STRING_TYPE", "AND", "OR", "NOT", "EQ", "NEQ", "LE", "GE", "LT", "GT",
  "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMICOLON", "ERROR", "$accept", "program", "stmt_list",
  "stmt", "simple_stmt", "block_stmt", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  Parser::yyrline_[] =
  {
       0,    57,    57,    61,    62,    66,    67,    71,    72,    73,
      74,    75,    77,    79,    83,    84,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
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
      25,    26,    27,    28,    29,    30,    31,    32
    };
    // Last valid token kind.
    const int code_max = 287;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1634 "parser.tab.cc"

#line 107 "parser.y"

