#include "GenericStatementList.h"

GenericStatementList::GenericStatementList()
{
    stmt_list = alloc_stmt_list();
    current_stmt_iter = tsi_start(stmt_list);
}

void GenericStatementList::copy(const GenericStatementList &other)
{
    this->stmt_list = other.stmt_list;
    this->current_stmt_iter = other.current_stmt_iter;
}

GenericStatementList::~GenericStatementList()
{
}

GenericStatementList::GenericStatementList(const GenericStatementList &other)
{
    copy(other);
}

GenericStatementList &GenericStatementList::operator=(const GenericStatementList &other)
{
    copy(other);
    return *this;
}

void GenericStatementList::addStatement(tree stmt)
{
    tsi_link_after(&current_stmt_iter, stmt, TSI_CONTINUE_LINKING);
}