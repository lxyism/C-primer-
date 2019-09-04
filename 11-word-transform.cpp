#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>

using namespace std;

//建立转换映射
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;  //保存转换规则
    string key;                     //要转换的单词
    string value;                   //替换后的内容
    //读取第一个单词存入key中，行中神与内容存入value
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)  //检查是否有转换规则
            trans_map[key] = value.substr(1); //跳过前导空格
        else 
            throw runtime_error("no rule for" + key);
    }
    return trans_map;
}

//生成转换文本
const string & transform(const string &s, const map<string, string> &m)
{
    //实际的转换工作；此部分是程序的核心
    auto map_it = m.find(s);
    //如果单词在转换规则map中
    if (map_it != m.cend())
        return map_it->second;  //使用替换短语
    else 
        return s;
}


void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);  //保存转换规则
    string text;
    while(getline(input, text)){          //读取每一行输入
        istringstream stream(text);       //读取每个单词 istringstream类用于执行C++风格的串流的输入操作。ostringstream类用于执行C风格的串流的输出操作。
        string word;
        bool firstword = true;
        while(stream >> word){
            if(firstword)
                firstword = false;
            else
                cout<<" ";
            cout<<transform(word, trans_map);
            
        }
        cout<<endl;
    }   
}

