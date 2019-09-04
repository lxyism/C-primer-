#include<iostream>
#include"Sales_data-1.h"

using namespace std;
int main()
{
    cout<<"请输入交易记录（ISBN、销售量、原价、实际售价）："<<endl;
    Sales_data total;
    //读入第一条交易记录，并确保有数据可以处理
    if(cin >> total)
    {
        Sales_data trans;  //保存和的变量
        while(cin >> trans)
        {
            if(total.isbn() == trans.isbn())
                total += trans;
            else
            {
                //打印前一本书的结果
                cout<<total<<endl; 
                total = trans;  //total现在表示下一本书的销售额
            }
        }
        cout<<total<<endl;  //打印最后一本书的结果
    }
    else
    {
        //没有输入！敬告读者
        cerr << "No data?!"<<endl;
        return -1;
    }

    system("pause");
    return 0;
    
}