#include<iostream>
using namespace std;

int decimal(int binary){
	int ans = 0, pow = 1;
	while(binary > 0){
		int rem = binary%10;
		binary = binary/10;
		ans += rem*pow;
		pow = pow*2;
	}
	return ans;
}

int main(){
	cout<<decimal(1011)<<endl;
	cout<<decimal(111)<<endl;
	cout<<decimal(100)<<endl;
	cout<<decimal(10)<<endl;
	cout<<decimal(1010)<<endl;
	cout<<decimal(1111)<<endl;
	cout<<decimal(1001)<<endl;
	cout<<decimal(1)<<endl;
	return 0;
}