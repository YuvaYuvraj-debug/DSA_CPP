#include<iostream>
using namespace std;

bool chkPower(int n){
	bool isPower;
	if(n <= 0){
		isPower = false;
	}else{
		int originalNum = n;
		while(n%2 == 0){
			n /= 2;
		}
		if(n == 1){
			isPower = true;
		}else{
			isPower = false;
		}
	}
	
	return isPower;
}

int main(){
	cout<<chkPower(16);
	return 0;
}


/*
#include<iostream>
using namespace std;

int reverseNum(int n){
	int ans = 0, pow = 1;
	int re_n = n;
	while(re_n > 0){
		re_n /= 10;
		pow = pow*10;
	}
	while(n > 0){
		int rem = n%10;
		pow = pow/10;
		ans += rem*pow;
		n /= 10;
	}
	return ans;
}

int main(){
	cout<<reverseNum(3214)<<endl;
	return 0;
}
*/


/*
#include<iostream>
using namespace std;

bool chkPower(int n){
	bool isPower;
	if((n > 0) && ((n&(n-1)) == 0)){
		isPower = true;
	}else{
		isPower = false;
	}
	return isPower;
}

int main(){
	cout<<chkPower(2);
	return 0;
}
*/


/*
#include<iostream>
using namespace std;

int main(){
	
	cout<<sizeof(int)<<endl;
	cout<<sizeof(long int)<<endl;
	cout<<sizeof(long long int)<<endl;
	cout<<sizeof(short int)<<endl;
	
	
	unsigned int x = -10, y = -1;
	
	cout<<x<<endl<<y<<endl;
	return 0;
}
*/