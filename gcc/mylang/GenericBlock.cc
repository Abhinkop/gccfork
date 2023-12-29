#include "GenericBlock.h"

GenericBlock::GenericBlock(tree stmtList)
{

    current_block = make_node(BLOCK);
    bind_expr = build3(BIND_EXPR, void_type_node, NULL, stmtList, current_block);
}

void GenericBlock::copy(const GenericBlock &other)
{
    this->current_block = other.current_block;
    this->bind_expr = other.bind_expr;
}

GenericBlock::~GenericBlock()
{
}

GenericBlock::GenericBlock(const GenericBlock &other)
{
    copy(other);
}

GenericBlock &GenericBlock::operator=(const GenericBlock &other)
{
    copy(other);
    return *this;
}