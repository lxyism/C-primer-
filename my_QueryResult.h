#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include<memory>
#include<string>
#include<vector>
#include<set>
#include<iostream>
#include "my_StrBlob_3.h"

class QueryResult{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string s,std::shared_ptr<std::set<line_no>> p,StrBlob f):
                sought(s), lines(p), file(f) { }
    std::set<line_no>::size_type size() const  { return lines->size(); }
    line_it begin() const {return lines->begin();}
    line_it end() const {return lines->end();}
    StrBlob get_file() {return file;}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    // std::shared_ptr<std::vector<std::string>> file;  //利用shared_ptr对lines和file进行数据共享，保证两个类之间可以同时访问输入的file
    StrBlob file;  //输入文件
};

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    //如果找到了单词，打印出现次数及所有出现的行号
    os<<qr.sought<<" occurs "<<qr.lines->size() << " "<<make_plural(qr.lines->size(),"time","s")<<endl;
    //打印单词出现的每一行
    for(auto num: *qr.lines)        //对set中每个元素
    //不让用户对从0开始的文本行号困惑
        os<<"\t(line "<<num+1<<") "<<qr.file.begin().deref(num)<<endl;
    return os;
}
#endif
