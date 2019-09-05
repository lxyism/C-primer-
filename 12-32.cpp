#include<string>
#include<iostream>
#include<cstdlib>
#include"make_plural.h"
#include"my_TextQuery.h"

// #include"my_TextQuery.cpp"

using namespace std;
void runQueries(ifstream &infile)
{
    //infile��һ��ifstream�������ǲ�ѯ���ļ�
    TextQuery tq(infile);  //�����ļ�������ӳ���
    //������ѭ������ʾ�û�����һ�����ʣ���ѯ�ε��ʲ���ӡ���
    while(true){
        cout<<"enter word to look for, or q to quit:";
        string s;
        //�������ļ���β���û������ˡ�q�������˳�ѭ��
        if(!(cin>>s) || s == "q") break;
        //ִ�в�ѯ����ӡ���
        print(cout, tq.query(s)) <<endl;
    }
}

//������յ�һ������ָ��Ҫ��ѯ���ļ�
int main(int argc, char **argv)
{
    //���ļ��������в�ѯ�û�ָ���ĵ���
    ifstream infile;
    //open������void�����������ö�������������صڶ�����������ֵ��
    //���infile��״̬
    if(argc < 2 || !(infile.open(argv[1]), infile)){
        cerr<<"No input file!"<<endl;
        return EXIT_FAILURE;
    }
    runQueries(infile);
    return 0;
}