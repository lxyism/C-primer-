#include<iostream>
#include"Sales_data-2.h"

using namespace std;
int main()
{
    cout<<"�����뽻�׼�¼��ISBN����������ԭ�ۡ�ʵ���ۼۣ���"<<endl;
    Sales_data total;
    //�����һ�����׼�¼����ȷ�������ݿ��Դ���
    if(read(cin, total))
    {
        Sales_data trans;  //����͵ı���
        while(read(cin, trans))
        {
            if(total.isbn() == trans.isbn())
                total = add(total, trans);  //���������۶�
            else
            {
                //��ӡǰһ����Ľ��
                print(cout, total);
                cout<<endl; 
                total = trans;  //total���ڱ�ʾ��һ��������۶�
            }
        }
        print(cout, total);
        cout<<endl;  //��ӡ���һ����Ľ��
    }
    else
    {
        //û�����룡�������
        cerr << "No data?!"<<endl;
        return -1;
    }

    system("pause");
    return 0;
    
}