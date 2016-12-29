#ifndef __TestC____Query__
#define __TestC____Query__

#include <iostream>
#include "TextQuery.h"


class Query_base;

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const string &);
    Query(const Query &);
    virtual ~Query();
    Query& operator=(const Query&);
    
    set<TextQuery::line_no> eval(const TextQuery&) const;
    ostream & display(ostream &) const;
private:
    Query(Query_base *);
    
    Query_base *q;
    size_t *use;
    void decr_use();
};

inline ostream & operator<<(ostream &os, const Query &q) {
    return q.display(os);
}

#endif /* defined(__TestC____Query__) */
