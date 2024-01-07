#include "./parser.h"

#include "../AST/constant/constant.node.h"
#include "../AST/operator/binary/binary.node.h"
#include "../AST/operator/unary/unary.node.h"
#include "../AST/root/root.node.h"

Parser::Parser(const vector<Token> *TOKENS)
    : TOKENS(*TOKENS) {
}

//Token *Parser::match(const vector<TokenType> &tokenTypes) {
//	if (this->pos < this->TOKENS.size()) {
//		Token token = this->TOKENS[this->pos];
//
//		for (const TokenType &tokenType: tokenTypes) {
//			if (tokenType.NAME == token.TYPE.NAME) {
//				this->pos++;
//				return  token;
//			}
//		}
//	}
//
//	return nullptr;
//}
const Token *Parser::match(const std::vector<TokenType> &tokenTypes) {
	if (this->pos < this->TOKENS.size()) {
		const Token *token = &this->TOKENS[this->pos];

		for (const TokenType &tokenType: tokenTypes) {
			if (tokenType.NAME == token->TYPE.NAME) {
				this->pos++;
				return const_cast<Token *>(token);
			}
		}
	}

	return nullptr;
}

Token Parser::require(const vector<TokenType> &tokenTypes) {
	const Token *token = this->match(tokenTypes);
	if (token != nullptr) return *token;

	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar " + tokenTypes[0].NAME + " kerek");
}

const Node *Parser::value() {
	const Token *CONSTANT = this->match({this->tokenList.CONSTANT});
	if (CONSTANT != nullptr) return new ConstantNode(CONSTANT);

	delete CONSTANT;
	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar {shama} nemese {aınymaly} kerek");
}

const Node *Parser::log() {
	const Token *LOG = this->match({this->tokenList.LOG});
	if (LOG != nullptr) return new UnaryNode(LOG, this->expression());

	delete LOG;
	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar {kórset} kerek");
}

const Node *Parser::parentheses() {
	if (this->match({this->tokenList.LEFT_BRACKET})) {
		const Node *NODE = this->expression();
		this->require({this->tokenList.RIGHT_BRACKET});
		return NODE;
	} else {
		return this->value();
	}
}

const Node *Parser::expression() {
	const vector<TokenType> OPERATORS = {
	  this->tokenList.ADD,
	  this->tokenList.MINUS,
	  this->tokenList.POWER,
	  this->tokenList.REMAINLESS_DIVISION,
	  this->tokenList.MULTIPLICATION,
	  this->tokenList.DIVISION,
	};

	Node *leftNode = const_cast<Node *>(this->parentheses());
	const Token *_operator = this->match(OPERATORS);

	while (_operator != nullptr) {
		const Node *rightNode = this->parentheses();
		leftNode = new BinaryNode(_operator, rightNode, leftNode);
		_operator = this->match(OPERATORS);
	}

	return leftNode;
}

const Node *Parser::parse() {
	if (!this->match({this->tokenList.CONST, this->tokenList.LET})) return this->log();

	this->require({this->tokenList.COLON});
	const Token TYPE = this->require({this->tokenList.INT, this->tokenList.STRING, this->tokenList.BOOLEAN});

	Node *variableNode = const_cast<Node *>(this->value());

	const Token *assign = this->match({this->tokenList.ASSIGN});
	if (assign != nullptr) {
		const Node *rightNode = this->expression();
		return new BinaryNode(assign, rightNode, variableNode);
	}

	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar {teń} kerek");
}

const Node *Parser::code() {
	RootNode root;

	while (this->pos < this->TOKENS.size()) {
		const Node *codeLine = this->parse();
		this->require({this->tokenList.SEMICOLON});
		root.addNode(codeLine);
	}

	return &root;
}

auto Parser::run(const Node *node) {
}