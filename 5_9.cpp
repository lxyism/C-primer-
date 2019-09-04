#include<iostream>
using namespace std;
int main(){
	unsigned int vowelCnt = 0;
	char ch;
	cout<<"please input a text!"<<endl;
	while(cin >> ch)
	{
		if (ch == 'a')
			++vowelCnt;
		if (ch == 'e')
			++vowelCnt;
		if (ch == 'i')
			++vowelCnt;
		if (ch == 'o')
			++vowelCnt;
		if (ch == 'u')
			++vowelCnt;


	}
	cout<<"your input have "<<vowelCnt<<"元音字母"<<endl;
	return 0;
}