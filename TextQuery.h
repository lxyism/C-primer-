#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<memory>
#include<String>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include "QueryResult.h"

class QueryResult;
class TextQuery{
public:
    typedef std::vector<std::String>::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    static std::string cleanup_str(const std::string&);
};
#endif