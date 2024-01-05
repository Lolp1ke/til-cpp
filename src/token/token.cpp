#include "../types.h"

struct TokenType {
	const string NAME;
	const regexp REGEXP;
	
	TokenType(string NAME, regexp REGEXP): NAME(std::move(NAME)), REGEXP(std::move(REGEXP)) {}
};

struct Token {
	const TokenType TYPE;
	string value;
	unsigned int pos;
};

class TokenList {
	public:
		const TokenType ADD{"qosý", regexp(R"(^[+])")};
//		const TokenType MINUS{"mınýs", regexp("[-]")};
//		const TokenType POWER{"dáreje", regexp("[*][*]")};
//		const TokenType REMAINLESS_DIVISION{"qaldyqsyz bólý", std::regex("(/[/]/)")};
//		const TokenType MULTIPLICATION{"kóbeıtý", regexp("([*])")};
//		const TokenType DIVISION{"bólý", regexp("([/])")};
//
//		const TokenType ASSIGN{"teń", regexp("(=)")};
//
		const TokenType LOG{"kórset", regexp(R"(^korset\b)")};
//
//		const TokenType SEMICOLON{"núkteli útir", regexp("(;)")};
//		const TokenType COLON{"qos núkte", regexp("(:)")};
//
		const TokenType SPACE{"bos oryn", regexp(R"(^[ \t\n\r]+)")};
//
//		const TokenType LEFT_BRACKET{"sol jaq jaqsha", regexp("([\\(])")};
//		const TokenType RIGHT_BRACKET{"oń jaq jaqsha", regexp("([\\)])")};
//
//		const TokenType CONST{"turaqty", regexp("(turaqty*)")};
//		const TokenType LET{"bolsyn", regexp("(bolsyn*)")};
//
//		const TokenType TYPE{"túri", regexp("(\bjol\b|\bsan\b|\blogika\b*)")};
//    const TokenType VARIABLE{"aınymaly", regexp("([_A-Z]*)")};
//
//		const TokenType STRING{"jol", std::regex("([a-z]*)")};
		const TokenType NUMBER{"san", std::regex(R"(^[-+]?\d*\.?\d+)")};
//		const TokenType BOOLEAN{"logika", std::regex("(\bdurys|\bburys*)")};
		
		std::vector<TokenType> getAll() const {
			return {
				SPACE,
				ADD,
				
				LOG,
				NUMBER,
//				ADD, MINUS, POWER, REMAINLESS_DIVISION, MULTIPLICATION,
//				DIVISION, ASSIGN, LOG, SEMICOLON, COLON, SPACE,
//				LEFT_BRACKET, RIGHT_BRACKET, CONST, LET, TYPE, VARIABLE,
//				BOOLEAN, NUMBER, STRING
			};
		}
};