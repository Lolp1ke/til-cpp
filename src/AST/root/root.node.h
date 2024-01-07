#pragma once

#include "../node.h"

class RootNode : public Node {
	public:
	vector<Node> nodes;

	public:
	void addNode(const Node *NODE);
};