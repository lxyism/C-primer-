#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
int main()
{
    // ifstream in("data");
    // if (in){
    //     cerr<<"无法打开输入文件"<<endl;
    //     return -1;
    // }
    string line;
    vector<string> words;
    while(cin>>line){
        words.push_back(line);
    }
    // cin.close();
    vector<string>::const_iterator it = words.begin() ;
    while (it != words.end()){
        cout<<*it<<endl;
        ++it;
    }
    system("pause");
    return 0;
}