#include <string>
#include <vector>
#include <iostream>

#include "../types.h"
#include "../token/token.cpp"


class Lexer {
		const string CODE;
		unsigned int pos{0};
		vector<Token> tokens;
		vector<TokenType> tokenTypes = TokenList().getAll();
		
	public:
		explicit Lexer(string CODE): CODE(std::move(CODE)) {}
		
	private:
		bool next() {
			if (this->pos >= this->CODE.length()) return false;
			
			for (const TokenType &tokenType : tokenTypes) {
				string substr = this->CODE.substr(this->pos);
				
				std::smatch smatch;
				const bool &isToken = std::regex_search(substr, smatch, tokenType.REGEXP);
				if (isToken) {
					const string &token = smatch[0].str();
					this->tokens.push_back({tokenType, token, this->pos});
					this->pos += token.length();
					return true;
				}
			}
			return false;
			
//			for (int i{0}; i <= tokenTypes.size(); i++) {
//				const TokenType tokenType = tokenTypes[i];
//
//				std::cout << tokenType.NAME;
//				const string substr = this->CODE.substr(this->pos);
//				std::smatch smatch;
//				const bool isToken = regex_match(substr, smatch, tokenType.REGEXP);
//
//				if (isToken) {
//					const string token = smatch[0].str();
//					this->tokens.push_back({tokenType, token, this->pos});
//					this->pos += token.length();
//					std::cout << this->pos << "\n";
//					return true;
//				}
//			}
		}
		
	public:
		vector<Token> analysis() {
			while (this->next());
//			TokenList tokenList;
//			auto notSpace = [&tokenList](const Token& token) {
//				return token.TYPE.NAME != tokenList.SPACE.NAME;
//			};

//			this->tokens.erase(std::remove_if(tokens.begin(), tokens.end(), notSpace), tokens.end());
			return this->tokens;
		}
};
