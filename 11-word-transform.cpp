#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>

using namespace std;

//����ת��ӳ��
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;  //����ת������
    string key;                     //Ҫת���ĵ���
    string value;                   //�滻�������
    //��ȡ��һ�����ʴ���key�У������������ݴ���value
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)  //����Ƿ���ת������
            trans_map[key] = value.substr(1); //����ǰ���ո�
        else 
            throw runtime_error("no rule for" + key);
    }
    return trans_map;
}

//����ת���ı�
const string & transform(const string &s, const map<string, string> &m)
{
    //ʵ�ʵ�ת���������˲����ǳ���ĺ���
    auto map_it = m.find(s);
    //���������ת������map��
    if (map_it != m.cend())
        return map_it->second;  //ʹ���滻����
    else 
        return s;
}


void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);  //����ת������
    string text;
    while(getline(input, text)){          //��ȡÿһ������
        istringstream stream(text);       //��ȡÿ������ istringstream������ִ��C++���Ĵ��������������ostringstream������ִ��C���Ĵ��������������
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

