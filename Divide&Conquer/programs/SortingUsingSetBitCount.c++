#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	
	stable_sort(arr.begin(),arr.end(),[](int a,int b){
		return countBits(a)>countBits(b);
	});
	cout<<"[";
	for(int i=0;i<n;i++){
		cout<<arr[i];
		if(i!=n-1)cout<<", ";
	}
	cout<<"]"<<endl;
}