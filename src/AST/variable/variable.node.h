#pragma once

#include "../node.h"

class VariableNode : public Node {
	public:
	const Token TOKEN;

	public:
	explicit VariableNode(const Token *TOKEN);
};