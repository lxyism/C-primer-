#include<iostream>
#include"Sales_data-2.h"
using namespace std;

int main()
{
    Sales_data total(cin);      ////////���浱ǰ��ͽ���ı���
    if(cin)
    {
        Sales_data trans(cin);  //��ȡ��һ�ʽ��ף���������һ���������ݵı���
        do
        {
            if(total.isbn() == trans.isbn())  //����ʣ��Ľ��ף����isbn
                total.combine(trans);         //���±���total��ǰ��ֵ
            else
            {
                print(cout, total) <<endl;    //������
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