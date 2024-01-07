#pragma once

#include "../AST/node.h"
#include "../token/token.h"

class Parser {
	private:
	unsigned int pos{0};
	const vector<Token> TOKENS;
	const TokenList tokenList;

	public:
	explicit Parser(const vector<Token> *TOKENS);

	private:
	const Token *match(const vector<TokenType> &tokenTypes);
	Token require(const vector<TokenType> &tokenTypes);

	const Node *value();
	const Node *log();
	const Node *parentheses();
	const Node *expression();
	const Node *parse();
	const Node *code();

	public:
	auto run(const Node *node);
};
