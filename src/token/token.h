#pragma once

#include "../types.h"

struct TokenType {
	const string NAME;
	const regexp REGEXP;

	TokenType(string NAME, regexp REGEXP);
};

struct Token {
	const TokenType TYPE;
	string value;
	const unsigned int POS;

	Token(const TokenType *TYPE, const string *VALUE, const unsigned int *POS);
};


class TokenList {
	public:
	const TokenType SPACE{"bos oryn", regexp(R"(^[ \t\n\r]+)")};
	const TokenType INT{"san", regexp(R"(^san\b)")};
	const TokenType STRING{"jol", regexp(R"(^jol\b)")};
	const TokenType BOOLEAN{"tujyrym", regexp(R"(^tujyrym\b)")};


	const TokenType LOG{"kórset", regexp(R"(^korset\b)")};
	const TokenType CONST{"turaqty", regexp(R"(^turaqty\b)")};
	const TokenType LET{"bolsyn", regexp(R"(^bolsyn\b)")};


	const TokenType ADD{"qosý", regexp(R"(^[+])")};
	const TokenType MINUS{"azaıtý", regexp(R"(^[-])")};
	const TokenType POWER{"dáreje", regexp(R"(^[\^])")};
	const TokenType REMAINLESS_DIVISION{"qaldyqsyz bólý", std::regex(R"(^[/][/])")};
	const TokenType MULTIPLICATION{"kóbeıtý", regexp(R"(^[*])")};
	const TokenType DIVISION{"bólý", regexp(R"(^[/])")};
	const TokenType ASSIGN{"teń", regexp(R"(^[=])")};


	const TokenType SEMICOLON{"núkteli útir", regexp(R"(^[;])")};
	const TokenType COLON{"qos núkte", regexp(R"(^[:])")};
	const TokenType RIGHT_BRACKET{"oń jaq jaqsha", regexp(R"(^[\)])")};
	const TokenType LEFT_BRACKET{"sol jaq jaqsha", regexp(R"(^[\(])")};
	const TokenType RIGHT_CURLY_BRACKET{"oń jaq buıra jaqsha", regexp(R"(^[}])")};
	const TokenType LEFT_CURLY_BRACKET{"sol jaq buıra jaqsha", regexp(R"(^[{])")};


	const TokenType AND{"jáne", regexp(R"(^jane\b)")};
	const TokenType OR{"nemese", regexp(R"(^nemese\b)")};


	const TokenType IF{"eger", regexp(R"(^eger\b)")};
	const TokenType ELSE{"bolmasa", regexp(R"(^bolmasa\b)")};


	const TokenType CONSTANT{"turaqty mán", regexp(R"(^(-?\d+(\.\d+)?|shyn|jalgan|("[^"\\]*(\\.[^"\\]*)*")))")};
	const TokenType VARIABLE{"aınymaly", regexp(R"(^[a-zA-Z_]*)")};

	public:
	[[nodiscard]] vector<TokenType> getAll() const;
};