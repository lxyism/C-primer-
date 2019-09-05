#include<string>
#include<iostream>
#include<cstdlib>
#include"make_plural.h"
#include"my_TextQuery.h"

// #include"my_TextQuery.cpp"

using namespace std;
void runQueries(ifstream &infile)
{
    //infile是一个ifstream，是我们查询的文件
    TextQuery tq(infile);  //保存文件并创建映射表
    //程序主循环：提示用户输入一个单词，查询次单词并打印结果
    while(true){
        cout<<"enter word to look for, or q to quit:";
        string s;
        //若遇见文件结尾或用户输入了‘q’，则退出循环
        if(!(cin>>s) || s == "q") break;
        //执行查询并打印结果
        print(cout, tq.query(s)) <<endl;
    }
}

//程序接收单一参数，指出要查询的文件
int main(int argc, char **argv)
{
    //打开文件，将其中查询用户指定的单词
    ifstream infile;
    //open本身返回void，所以我们用逗号运算符（返回第二个运算对象的值）
    //检查infile的状态
    if(argc < 2 || !(infile.open(argv[1]), infile)){
        cerr<<"No input file!"<<endl;
        return EXIT_FAILURE;
    }
    runQueries(infile);
    return 0;
}