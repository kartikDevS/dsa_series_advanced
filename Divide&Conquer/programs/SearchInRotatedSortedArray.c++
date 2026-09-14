//some fault in this code as it doesnt pass one hidden test case
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int m;
	cin>>m;
	m=((m%n)+n)%n;
	int key;
	cin>>key;
	rotate(arr.begin(),arr.begin()+m,arr.end());
	for(int i=0;i<n;i++){
		cout<<arr[i];
		if(i!=n-1)cout<<" ";
	}
	cout<<endl;
	int low=0,high=n-m-1;
	int lans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==key){
			lans=mid;
			break;
		}
		else if(arr[mid]<key)low=mid+1;
		else high=mid-1;
	}
	low=n-m,high=n-1;
	int rans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==key){
			rans=mid;
			break;
		}
		else if(arr[mid]<key)low=mid+1;
		else high=mid-1;
	}
	if(lans!=-1){
		cout<<lans<<endl;
		return 0;
	}
	if(rans!=-1){
		cout<<rans<<endl;
		return 0;
	}
	cout<<lans<<endl;
	return 0;
}