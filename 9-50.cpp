#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<string> vs = {"12.3", "+4.56","-7.89e-2"};
    float sum = 0;
    for (auto iter = vs.begin(); iter != vs.end();iter++)
        sum += stof(*iter);
    cout<<"ºÍ:"<<sum<<endl;
    system("pause");

    return 0;
}