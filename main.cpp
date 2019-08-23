#include<iostream>

int main()
{
	//int low=0,high=0;
	//std::cin >> low >> high;
	//int sum = 0,val=0;//val<10
	//while (std::cin>>val)
	//	sum += val;

	//std::cout<<sum<<std::endl;

	
	//std::cout<<"sum of 1 to 10 inclusive is "<<sum<<std::endl;
    //std::cout << "hello world,please enter 2 numbers:" << std::endl;
    //int v1 = 0,v2=0;
    //std::cin>>v1>>v2;
    //std::cout<<"the sum of "<< v1 <<" and "<< v2 <<" is "<<v1+v2<<std::endl;
    //std::cout<<"the mutipy of "<< v1 <<" and " <<v2<<" is "<<v1*v2<<std::endl;
    int currVal = 0,val =0;
    if(std::cin>>currVal){
    	int cnt=1;
    	while(std::cin>>val){
    		if(val == currVal)
    			++cnt;
    		else {
    			std::cout<<currVal<<" occurs "<<cnt<<" times"<<std::endl;
    			currVal = val;
    			cnt = 1;
    		}
    	}
    	std::cout<<currVal<<" occurs "<<cnt<<" times"<<std::endl;
    }
    
    return 0;
}