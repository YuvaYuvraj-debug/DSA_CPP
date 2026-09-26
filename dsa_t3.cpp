// nCr --> binomial coefficient

#include<iostream>
using namespace std;

int fectorial(int n){
	if(n <= 1){
		return 1;
	}
	return n*fectorial(n-1);
}

int binomialCoefficient(int n, int r){
	if(n >= r && n > 0 && r > 0){
		cout<<"nCr = "<<n<<"C"<<r<<" = ";
		int biCo = (fectorial(n))/(fectorial(n - r)*fectorial(r));
	return biCo;
	}else{
		cout<<"error! ";
		return 0;
	}
}

int main(){
	cout<<fectorial(6)<<endl;
	cout<<binomialCoefficient(6, 3)<<endl;
	cout<<binomialCoefficient(3, 3)<<endl;
	cout<<binomialCoefficient(6, 7)<<endl;
	cout<<binomialCoefficient(6, -3)<<endl;
	cout<<binomialCoefficient(5, 4)<<endl;
	cout<<binomialCoefficient(10, 4)<<endl;
	
	return 0;
}

/*
#include<iostream>
using namespace std;

int fibonacci(int n){
	if(n < 2){
		return 1;
	}
	int t = fibonacci(n-1) + fibonacci(n-2);
	return t;
}

int main(){
	cout<<fibonacci(0)<<endl;
	cout<<fibonacci(1)<<endl;
	cout<<fibonacci(2)<<endl;
	cout<<fibonacci(3)<<endl;
	cout<<fibonacci(4)<<endl;
	cout<<fibonacci(5)<<endl;
	cout<<fibonacci(6)<<endl;
	cout<<fibonacci(7)<<endl;
	cout<<fibonacci(8)<<endl;
	cout<<fibonacci(9)<<endl;
	cout<<fibonacci(10)<<endl;
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

bool chkPrime(int a){
	bool isPrime = true;
	for(int i = 2; i < a; i++){
		if(a%i == 0){
			isPrime = false;
			break;
		}
	}
	if(isPrime == true && a > 1){
		return true;
	}else{
		return false;
	}
}

void printPrime(int b){
	for(int i = 0; i <= b; i++){
		if(chkPrime(i) == true){
			cout<<i<<endl;
		}
	}
}

int main(){
	printPrime(200);
	return 0;
}

*/


/*
#include<iostream>
using namespace std;

int sumDigit(int n){
	int digitSum = 0;
	while(n > 0){
		int lastDigit = n%10;
		n = n/10;
		digitSum += lastDigit;
	}
	return digitSum;
}

int main(){
	cout<<sumDigit(12345);
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

int sumVal(int n){
	if(n <= 1){
		return 1;
	}
	return (n+sumVal(n-1));
}

int main(){
	cout<<"Sm of n numbers is: "<<sumVal(100)<<endl;
	return 0;
}
*/