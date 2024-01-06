#include "../token/token.cpp"
#include <iostream>

class Parser {
	private:
	unsigned int pos{0};
	const vector<Token> TOKENS;
	const TokenList tokenList;

	public:
	explicit Parser(const vector<Token> &TOKENS)
	    : TOKENS(TOKENS) {
	}

	private:
	variant<Token, bool> match(const vector<TokenType> &tokenTypes) {
		if (this->pos < this->TOKENS.size()) {
			const Token &token = this->TOKENS[this->pos];

			for (const TokenType &tokenType: tokenTypes) {
				if (tokenType.NAME == token.TYPE.NAME) {
					this->pos++;
					return token;
				}
			}
		}

		return false;
	}

	Token require(const vector<TokenType> &tokenTypes) {
		const variant<Token, bool> &token = this->match(tokenTypes);
		try {
			return std::get<Token>(token);
		} catch (const std::bad_variant_access &_) {
			throw std::runtime_error(std::to_string(this->pos) + "- jolynda qate bar" + tokenTypes[0].NAME + "kerek");
		}
	}
};