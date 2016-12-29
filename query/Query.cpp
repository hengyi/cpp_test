#include "Query.h"
#include "Query_base.h"

Query::Query(const Query &c) : q(c.q), use(c.use) {
    ++*use;
}

Query::Query(const string &s) : q(new WordQuery(s)), use(new size_t(1)) {
    
}

Query::Query(Query_base *query) : q(query), use(new size_t(1)) {
    
}

Query::~Query() {
    decr_use();
}

void Query::decr_use() {
    if (--*use == 0) {
        delete q;
        delete use;
    }
}

set<TextQuery::line_no> Query::eval(const TextQuery &t) const{
    return q->eval(t);
}

ostream& Query::display(ostream &os) const {
    return q->display(os);
}