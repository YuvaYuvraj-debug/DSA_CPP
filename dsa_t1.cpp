#include<iostream>
using namespace std;

int getFectorial(int n){
	if(n <= 1){
		return 1;
	}
	return n*getFectorial(n-1);
}

int main(){
	int n;
	cout<<"Enter the number of which fectorial is to find:"<<endl;
	cin>>n;
	
	if(n < 0){
		cout<<"Fectorial of negative number deos not exist!"<<endl;
	}
	else if(n >= 13){
		cout<<"ERROR! number limit is exceeded."<<endl;
	}
	else{
		cout<<"Factorial of "<<n<<" = "<<getFectorial(n)<<endl;
	}
	return 0;
}

/*
#include<iostream>
using namespace std;

int main(){
	// for(int i = 1; i <= 5; i++){
		// cout<<"*****"<<endl;
	// }
	int x = 10;
	for(int i = 1; i <= 10; i++){
	
	for(int j = 1; j <= x; j++){
		cout<<"* ";
	}
	cout<<endl;
	x--;
	}
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

int main(){
	int n  = 12;
	bool isPrime = true;
	for(int i = 2; i*i <= n; i++){
	 	if(n%i == 0){
			isPrime = false;
			break;
		}
	}
	if(isPrime == true){
		cout<<"Given number is prime!"<<endl;
	}
	else{
		cout<<"Given number is non-prime!"<<endl;
	}
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number;"<<endl;
	cin>>n;
	for(int i = 0; i < n; i++){
		char ch = 'A';
		for(int j = 0; j < n; j++){
			cout<<ch<<" ";
			ch = ch + 1;// 65 + 1 = 66 -> B
		}
		cout<<endl;
	}
	return 0;
} 
*/