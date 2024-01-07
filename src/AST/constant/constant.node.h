#pragma once

#include "../node.h"

class ConstantNode : public Node {
	public:
	const Token TOKEN;

	public:
	explicit ConstantNode(const Token *TOKEN);
};