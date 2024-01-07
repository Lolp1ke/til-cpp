#include "./unary.node.h"

UnaryNode::UnaryNode(const Token *OPERATOR, const Node *OPERAND)
    : OPERATOR(*OPERATOR), OPERAND(*OPERAND) {
}