#include<iostream>
#include<string>
using namespace std;
int main()
{
	int grade;
	cout<<"���������ĳɼ���"<<endl;
	cin >> grade;
	if (grade<0 || grade>100)
	{
		cout<<"�óɼ����Ϸ���"<<endl;
		return -1;
	}
	if (grade == 100)
	{
		cout<<"�ȼ��ɼ��ǣ�A++"<<endl;
		return -1;
	}
	if (grade < 60)
	{
		cout<<"�ȼ��ɼ��ǣ�F"<<endl;
		return -1;
	}
	int iU = grade / 10;
	int iT = grade % 10;
	string score, level, lettergrade;
	if (iU == 9)
		score = "A";
	else if (iU == 8)
		score == "B";
	else if (iU == 7)
		score = "C";
	else
		score = "D";
	if (iT < 3)
		level = "-";
	else if (iT > 7)
		level = "+";
	else 
		level = " ";
	lettergrade = score + level;
	cout<<"�ȼ��ɼ���"<<lettergrade<<endl;
	return 0;
}