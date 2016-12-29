#include "TextQuery.h"

TextQuery::TextQuery(string strArray[], vector<string>::size_type count) {
    lines_of_text.assign(strArray, strArray+count);
}

set<TextQuery::line_no> TextQuery::run_query(const string&word) const {
    set<line_no> ret_lines;
    for (int i=0;i<lines_of_text.size();i++) {
        string line = lines_of_text[i];
        if (line.find(word) != string::npos) {
            ret_lines.insert(i);
        }
    }
    return ret_lines;
}

TextQuery::line_no TextQuery::size() const {
    return lines_of_text.size();
}