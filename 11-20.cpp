#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if(!in){
        cout<<"���ļ�ʧ�ܣ�"<<endl;
        exit(1);
    }
    map<string, size_t> word_count;
    string word;
    while(in >>word){
        auto ret = word_count.insert({word,1});  //���뵥�ʣ�����Ϊ1
        if(!ret.second)                          //����ʧ��
            ++ret.first->second;                 //���е��ʵĳ��ִ���+1
    }
    for (const auto &w :word_count)
        cout<<w.first<<"������"<<w.second<<"��"<<endl;
    system("pause");
    return 0;
}