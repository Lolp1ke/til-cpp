#pragma once

#include "../../node.h"

class UnaryNode : public Node {
	public:
	const Token OPERATOR;
	const Node OPERAND;

	public:
	UnaryNode(const Token *OPERATOR, const Node *OPERAND);
};