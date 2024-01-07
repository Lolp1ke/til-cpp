#include "./binary.node.h"

BinaryNode::BinaryNode(const Token *OPERATOR, const Node *RIGHT, const Node *LEFT)
    : OPERATOR(*OPERATOR), RIGHT(*RIGHT), LEFT(*LEFT) {
}