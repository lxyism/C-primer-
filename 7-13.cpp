#include<iostream>
#include"Sales_data-2.h"
using namespace std;

int main()
{
    Sales_data total(cin);      ////////保存当前求和结果的变量
    if(cin)
    {
        Sales_data trans(cin);  //读取第一笔交易；并保存下一条交易数据的变量
        do
        {
            if(total.isbn() == trans.isbn())  //读入剩余的交易，检查isbn
                total.combine(trans);         //更新变量total当前的值
            else
            {
                print(cout, total) <<endl;    //输出结果
                total = trans;
            }
            
        } while (read(cin, trans));        
        print(cout, total)<<endl;
    }
    else
    {
        cerr<<"No data?"<<endl;
    }
    system("pause");
    return 0;
    
}