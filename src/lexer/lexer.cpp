#include "lexer.h"

Lexer::Lexer(const string *CODE)
    : CODE(*CODE) {
}

bool Lexer::next() {
	if (this->pos >= this->CODE.length()) return false;

	for (const TokenType &tokenType: tokenTypes) {
		const string &substr = this->CODE.substr(this->pos);

		std::smatch smatch;
		const bool &isToken = std::regex_search(substr, smatch, tokenType.REGEXP);
		if (isToken) {
			const string &token = smatch[0].str();
			this->tokens.emplace_back(&tokenType, &token, &this->pos);
			this->pos += token.length();
			return true;
		}
	}

	return false;
}

vector<Token> Lexer::analysis() {
	while (this->next()) {}

	vector<Token> filteredTokens;
	for (const Token &token: this->tokens) {
		if (token.TYPE.NAME == TokenList().SPACE.NAME) continue;
		filteredTokens.push_back(token);
	}

	return filteredTokens;
}