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
    StrBlob file;  //�����ļ�
    // std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    static std::string cleanup_str(const std::string&);
};

QueryResult TextQuery::query(const string &sought) const
{
    //���δ�ҵ�sought��������һ��ָ���������set��ָ��
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    //ʹ��find�������±������ԭ���Ǳ��⽫����wm�еĵ�����ӽ�ȥ��
    auto loc = wm.find(cleanup_str(sought));

    if (loc == wm.end())
        return QueryResult(sought, nodata, file);  //δ�ҵ�
    else
    {
        return QueryResult(sought, loc->second, file);
    }
    
}
//��ȡ�����ļ�������ӳ��
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while(getline(is, text)){     //��ȡ�ļ���ÿһ��
        file.push_back(text);     //���������ı���
        int n = file.size() - 1;    //��ǰ�к�
        istringstream line(text);    //�����з�������
        string word;
        while(line >> word){
            word = cleanup_str(word);
            //������ʻ�δ��wm�У�ʹ���±����������ӽ�ȥ
            auto &lines = wm[word];    //lines��һ��shared_ptr
            if (!lines)  //��һ������һ������ʱ����ָ��Ϊ��
                lines.reset(new set<line_no>);    //����һ���µ�set

            lines->insert(n);        //���뵱ǰ�к�
        }
    }
}

//cleanup_strɾ����㣬���������ı�ת��ΪСд��ʽ���Ӷ���ѯ�Ǵ�Сд������
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