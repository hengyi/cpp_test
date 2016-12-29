#ifndef __TestC____Query_base__
#define __TestC____Query_base__

#include <iostream>
#include "TextQuery.h"
#include "Query.h"

class Query_base {
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() {}
private:
    virtual set<line_no> eval(const TextQuery&) const = 0;
    virtual ostream & display(ostream & = cout) const = 0;
};

class WordQuery : Query_base {
    friend class Query;
    WordQuery(const string &);
    set<line_no> eval(const TextQuery&) const;
    ostream & display(ostream & = cout) const;
    
    string query_word;
};

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    
    NotQuery(Query);
    set<line_no> eval(const TextQuery&) const;
    ostream & display(ostream & = cout) const;
    const Query query;
};

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(Query left, Query right, string op);
    ostream & display(ostream & = cout) const;
    
    const Query lhs, rhs;
    const string oper;
};

class AndQuery : BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(Query left, Query right);
    set<line_no> eval(const TextQuery&) const;
};

class OrQuery : BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(Query left, Query right);
    set<line_no> eval(const TextQuery&) const;
};

#endif /* defined(__TestC____Query_base__) */