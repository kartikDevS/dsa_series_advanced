#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	cin>>target;
	int low=0,high=n-1;
	int lans=-1,rans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			lans=mid;
			high=mid-1;
		}
		else if(arr[mid]>target){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
			rans=mid;
			low=mid+1;
		}
		else if(arr[mid]>target){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	cout<<lans<<" "<<rans;
}