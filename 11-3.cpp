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
        cout<<"打开文件失败！"<<endl;
        exit(1);
    }

    map<string, size_t> word_count;//string到count的映射
    string word;
    while(in >> word)
    {
        ++word_count[word];  //这个单词出现次数+1 
    }
    for (const auto &w : word_count)  
        cout<<w.first<<"出现了"<<w.second<<"次"<<endl;
    
    system("pause");
    return 0;

}