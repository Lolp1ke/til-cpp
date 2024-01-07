#include "./token.h"

TokenType::TokenType(string NAME, regexp REGEXP)
    : NAME(std::move(NAME)), REGEXP(std::move(REGEXP)) {
}

Token::Token(const TokenType *TYPE, const string *VALUE, const unsigned int *POS)
    : TYPE(*TYPE), value(*VALUE), POS(*POS) {
}

vector<TokenType> TokenList::getAll() const {
	return {
	  SPACE,

	  INT,
	  STRING,
	  BOOLEAN,

	  LOG,
	  CONST,
	  LET,

	  ADD,
	  MINUS,
	  POWER,
	  REMAINLESS_DIVISION,
	  MULTIPLICATION,
	  DIVISION,
	  ASSIGN,

	  SEMICOLON,
	  COLON,
	  RIGHT_BRACKET,
	  LEFT_BRACKET,
	  RIGHT_CURLY_BRACKET,
	  LEFT_CURLY_BRACKET,

	  AND,
	  OR,

	  IF,
	  ELSE,

	  CONSTANT,
	  VARIABLE,
	};
}