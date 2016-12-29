#include "Query.h"
#include "Query_base.h"

using namespace std;

inline Query operator~(const Query &oper) {
    return new NotQuery(oper);
}

inline Query operator|(const Query &left, const Query &right) {
    return new OrQuery(left, right);
}

inline Query operator&(const Query &left, const Query &right) {
    return new AndQuery(left, right);
}

int main(int argc, const char * argv[])
{
    string article[] = {
        "Alice Emma has long flowing red hair.",
        "Her Daddy says when the wind blows",
        "through her hair, it looks almost alive,",
        "like a fiery bird in flight",
        "A beautiful fiery bird, he tells her,",
        "magical but untamed.",
        "\"Daddy, shush, there is no such thing,\"",
        "she tells him, at the same time wanting",
        "him to tell her more.",
        "Shyly, she asks, \"I mean, Daddy, is there?\""
    };

    Query q = ~(Query("fiery") & Query("bird") | Query("wind"));
    cout<<q<<endl;
    set<vector<string>::size_type> result = q.eval(TextQuery(article, sizeof(article)/sizeof(article[0])));
    for (set<vector<string>::size_type>::iterator iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter+1 << endl;
    }
    return 0;
}
