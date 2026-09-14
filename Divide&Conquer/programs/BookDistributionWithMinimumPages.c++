#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>&arr,int n,int m,int mid){
	int student=1;
	int pages=0;
	for(int i=0;i<n;i++){
		if(arr[i]>mid)return false;
		if(pages+arr[i]>mid){
			student++;
			pages=arr[i];
			if(student>m)return false;
		}
		else{
			pages+=arr[i];
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int>arr(n);
	int low=-1;
	int high=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		low=max(low,arr[i]);
		high+=arr[i];
	}
	if(m>n){
		cout<<-1<<endl;
		return 0;
	}
	
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(isPossible(arr,n,m,mid)){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}