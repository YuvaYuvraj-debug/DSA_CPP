// BOOK ALLOCATION PROBLEM

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	bool isValide(vector<int> arr, int n, int m, int maxPages){
		int student = 1, pages = 0;
		
		for(int i = 0; i < n; i++){
			if(arr[i] > maxPages){
				return false;
			}
			
			if(pages + arr[i] <= maxPages){
				pages += arr[i];
			}else{
				student++;
				pages = arr[i];
			}
		}
		return (student > m)? false : true;
	}

public:
	int bookAllocation(vector<int>& arr, int n, int m){
		if(m > n) return -1;
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += arr[i];
		}
		
		int st = 0, end = sum, ans = -1;
		
		while(st <= end){
			int mid = st + (end - st)/2;
			
			if(isValide(arr, n, m, mid)){
				ans = mid;
				end = mid - 1;
			}else{
				st = mid + 1;
			}
		}
		return ans;
	}
};

int main(){
	vector<int> arr = {40, 30, 10, 20};
	int n = arr.size();
	int studentNum = 2;
	
	Solution obj;
	int result = obj.bookAllocation(arr, n, studentNum);
	cout<<result<<endl;
	return 0;
}