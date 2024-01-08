#include <codecvt>
#include <fstream>
#include <iostream>

#include "./lexer/lexer.h"
#include "./parser/parser.h"

int main(int argv, char **argc) {
	if (argv != 2) return EXIT_FAILURE;
	std::ifstream source(argc[1]);
	source.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	std::string code;

	char c;
	while (source.get(c)) {
		code += c;
	}
	source.close();

	Lexer lexer(&code);
	const vector<Token> &tokens = lexer.analysis();
	for (const Token &token: tokens) {
		//		std::cout << token.TYPE.NAME << "\n";
	}
	std::cout << std::endl;
	Parser parser(&tokens);

	parser.run(parser.code());

	return EXIT_SUCCESS;
}
