#include "./root.node.h"

void RootNode::addNode(const Node *NODE) {
	this->nodes.emplace_back(*NODE);
}