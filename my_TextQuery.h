#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<memory>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include "my_QueryResult.h"

class QueryResult;
class TextQuery{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();
private:
    StrBlob file;  //输入文件
    // std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    static std::string cleanup_str(const std::string&);
};

QueryResult TextQuery::query(const string &sought) const
{
    //如果未找到sought，将返回一个指向下面这个set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    //使用find而不是下标操作的原因是避免将不在wm中的单词添加进去！
    auto loc = wm.find(cleanup_str(sought));

    if (loc == wm.end())
        return QueryResult(sought, nodata, file);  //未找到
    else
    {
        return QueryResult(sought, loc->second, file);
    }
    
}
//读取输入文件，建立映射
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while(getline(is, text)){     //读取文件的每一行
        file.push_back(text);     //保存读入的文本行
        int n = file.size() - 1;    //当前行号
        istringstream line(text);    //从行中分理处单词
        string word;
        while(line >> word){
            word = cleanup_str(word);
            //如果单词还未在wm中，使用下标操作将其添加进去
            auto &lines = wm[word];    //lines是一个shared_ptr
            if (!lines)  //第一次遇到一个单词时，此指针为空
                lines.reset(new set<line_no>);    //分配一个新的set

            lines->insert(n);        //插入当前行号
        }
    }
}

//cleanup_str删除标点，并将所有文本转换为小写形式，从而查询是大小写不敏感
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it){
        if(!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}
#endif