#include<vector>
#include<iostream>
// #include<string>
using std::vector;
using std::cout;
using std::endl;

int main(){
	// int a[10]={0,1,3,5,6,8,3,7,3,10};
	// int a2[10]={0};
	// for (size_t i=0; i <= 9; i++)
	// {
	// 	a2[i] = a[i];
	// 	cout<<a2[i]<<endl;
	// }
	//利用vector重写数组复制到另一个数组
	vector<int> a{0,1,3,5,6,7,8,9,10,11};
	vector<int> a2(10);

	for (auto &c : a){
		a2[c] = a[c];
		cout<<a2[c]<<endl;
	}
	

	return 0;
}
/* 1.10
int main()
{
	int i = 10;
	while (i >= 0){
		std::cout<<i<<" ";
		i--;
	}
	std::cout<<std::endl;
	return 0;
}
*/
//3.1
// using std::cout;
// using std::endl;
// int main()
// {
// 	int sum = 0;
// 	int i = 50;
// 	while (i <= 100){
// 		sum += i;
// 		i++;

// 	}
// 	cout<<"50-100之间的整数和为："<<sum<<endl;
// 	return 0;
// }
