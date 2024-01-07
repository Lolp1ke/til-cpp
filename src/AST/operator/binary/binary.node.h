#pragma once

#include "../../node.h"

class BinaryNode : public Node {
	public:
	const Token OPERATOR;

	const Node RIGHT;
	const Node LEFT;

	public:
	BinaryNode(const Token *OPERATOR, const Node *RIGHT, const Node *LEFT);
};