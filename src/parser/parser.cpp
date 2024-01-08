#include <iostream>
#include <memory>

#include "../util.h"
#include "./parser.h"

#include "../AST/constant/constant.node.h"
#include "../AST/operator/binary/binary.node.h"
#include "../AST/operator/unary/unary.node.h"
#include "../AST/root/root.node.h"
#include "../AST/variable/variable.node.h"

Parser::Parser(const vector<Token> *TOKENS)
    : TOKENS(*TOKENS) {
}

const Token *Parser::match(const std::vector<TokenType> &tokenTypes) {
	if (this->pos < this->TOKENS.size()) {
		const Token *TOKEN = &this->TOKENS[this->pos];

		for (const TokenType &tokenType: tokenTypes) {
			if (tokenType.NAME == TOKEN->TYPE.NAME) {
				this->pos += 1;
				return TOKEN;
			}
		}
	}

	return nullptr;
}

Token Parser::require(const vector<TokenType> &tokenTypes) {
	const Token *TOKEN = this->match(tokenTypes);
	if (TOKEN != nullptr) return *std::make_unique<Token>(*TOKEN).release();
	//	*TOKEN;

	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar " + tokenTypes[0].NAME + " kerek");
}

const Node *Parser::value() {
	const Token *CONSTANT = this->match({this->tokenList.CONSTANT});
	if (CONSTANT)
		return new ConstantNode(CONSTANT);

	const Token *VARIABLE = this->match({this->tokenList.VARIABLE});
	if (VARIABLE)
		return std::make_unique<VariableNode>(VARIABLE).release();
	//		return std::make_unique<ConstantNode>(CONSTANT).release();

	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar {shama} nemese {aınymaly} kerek");
}

const Node *Parser::log() {
	const Token *LOG = this->match({this->tokenList.LOG});
	if (LOG != nullptr)
		//		return std::make_unique<UnaryNode>(LOG, this->expression()).release();
		return new UnaryNode(LOG, this->expression());

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
		leftNode =
		  //		  std::make_unique<BinaryNode>(_operator, rightNode, leftNode).release();
		  new BinaryNode(_operator, rightNode, leftNode);
		_operator = this->match(OPERATORS);
	}

	return leftNode;
}

const Node *Parser::parse() {
	if (!this->match({this->tokenList.CONST, this->tokenList.LET})) return this->log();

	const Node *variableNode = this->value();

	this->require({this->tokenList.COLON});
	const Token TYPE = this->require({this->tokenList.INT, this->tokenList.STRING, this->tokenList.BOOLEAN});

	const Token *assign = this->match({this->tokenList.ASSIGN});
	if (assign != nullptr) {
		const Node *rightNode = this->expression();
		return std::make_unique<BinaryNode>(assign, rightNode, variableNode).release();
		//		  new BinaryNode(assign, rightNode, variableNode);
	}

	throw std::runtime_error(std::to_string(this->pos) + " - jolynda qate bar {teń} kerek");
}

const Node *Parser::code() {
	std::unique_ptr<RootNode> root = std::make_unique<RootNode>();

	while (this->pos < this->TOKENS.size()) {
		const Node *codeLine = this->parse();
		if (instanceof <UnaryNode>(codeLine)) {
			std::cout << -1;
		}
		this->require({this->tokenList.SEMICOLON});
		root->addNode(codeLine);
	}

	return root.release();
}


void Parser::run(const Node *NODE) {
	if (instanceof <ConstantNode>(NODE)) {
		std::cout << "constant";
	}

	if (instanceof <BinaryNode>(NODE)) {
		std::cout << "binaryNode";
	}

	if (instanceof <UnaryNode>(NODE)) {
		std::cout << "unary";
	}

	if (instanceof <RootNode>(NODE)) {
		const auto *rootNode = dynamic_cast<const RootNode *>(NODE);

		for (const Node &node: rootNode->nodes) {
			this->run(&node);
		}
	}
}
