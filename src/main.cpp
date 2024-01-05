#include <iostream>
#include <fstream>
#include <codecvt>

#include "./lexer/lexer.cpp"

int main(int argv, char** argc) {
	if (argv != 2) return EXIT_FAILURE;
	std::ifstream source(argc[1]);
	source.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	std::string code;
	
	char c;
	while (source.get(c)) {
		code += c;
	}
	source.close();
	
//	std::cout << regex_search(code, std::regex(R"(^korset\b)"));
//
//	std::string substr = code.substr(0);
//	std::smatch smatch;
//	if (std::regex_search(code, smatch, regexp(R"(^korset\b)"))) {
//		std::string matchedToken = smatch[0].str();
//		std::cout << "Matched token: " << matchedToken << std::endl;
//	}


	Lexer lexer(code);
	const vector<Token> tokens = lexer.analysis();
	for (const Token &token : tokens) {
		std::cout << token.TYPE.NAME << "\n";
	}
	
	return EXIT_SUCCESS;
}
