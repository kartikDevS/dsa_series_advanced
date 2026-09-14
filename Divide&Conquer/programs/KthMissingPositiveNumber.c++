#include <iostream>
#include <vector>
using namespace std;

int KthMissing(vector<int>&arr,int k){
	int n=arr.size();
	int expected=1;
	for(int i=0;i<n;i++){
		if(arr[i]>expected){
			int gap=arr[i]-expected;
			if(k<=gap){
				return expected+k-1;
			}
			k-=gap;
		}
		expected=arr[i]+1;
	}
	return arr[n-1]+k;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int k;
	cin>>k;
	cout<<KthMissing(arr,k)<<endl;
	return 0;
}