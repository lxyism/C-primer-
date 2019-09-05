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
    // std::shared_ptr<std::vector<std::string>> file;  //����shared_ptr��lines��file�������ݹ�����֤������֮�����ͬʱ���������file
    StrBlob file;  //�����ļ�
};

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    //����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ��к�
    os<<qr.sought<<" occurs "<<qr.lines->size() << " "<<make_plural(qr.lines->size(),"time","s")<<endl;
    //��ӡ���ʳ��ֵ�ÿһ��
    for(auto num: *qr.lines)        //��set��ÿ��Ԫ��
    //�����û��Դ�0��ʼ���ı��к�����
        os<<"\t(line "<<num+1<<") "<<qr.file.begin().deref(num)<<endl;
    return os;
}
#endif
