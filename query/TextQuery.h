#ifndef __TestC____TextQuery__
#define __TestC____TextQuery__

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>  

using namespace std;

class TextQuery {
public:
    typedef vector<string>::size_type line_no;
    
    TextQuery(string[], vector<string>::size_type);
    set<line_no> run_query(const string&) const;
    line_no size() const;
private:
    vector<string> lines_of_text;
};

#endif /* defined(__TestC____TextQuery__) */
