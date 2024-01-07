#pragma once

#include "../token/token.h"


class Lexer {
	private:
	const string CODE;
	unsigned int pos{0};
	vector<Token> tokens;
	const vector<TokenType> tokenTypes = TokenList().getAll();

	public:
	explicit Lexer(const string *CODE);

	private:
	bool next();


	public:
	vector<Token> analysis();
};
