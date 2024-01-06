#include "../token/token.cpp"

class Lexer {
	private:
	const string CODE;
	unsigned int pos{0};
	vector<Token> tokens;
	const vector<TokenType> tokenTypes = TokenList().getAll();

	public:
	explicit Lexer(string CODE)
	    : CODE(std::move(CODE)) {
	}

	private:
	bool next() {
		if (this->pos >= this->CODE.length()) return false;

		for (const TokenType &tokenType: tokenTypes) {
			const string &substr = this->CODE.substr(this->pos);

			std::smatch smatch;
			const bool &isToken = std::regex_search(substr, smatch, tokenType.REGEXP);
			if (isToken) {
				const string &token = smatch[0].str();
				this->tokens.emplace_back(tokenType, token, this->pos);
				this->pos += token.length();
				return true;
			}
		}

		return false;
	}

	public:
	vector<Token> analysis() {
		while (this->next()) {}

		vector<Token> filteredTokens;
		for (const Token &token: this->tokens) {
			if (token.TYPE.NAME == TokenList().SPACE.NAME) continue;
			filteredTokens.push_back(token);
		}

		return filteredTokens;
	}
};
