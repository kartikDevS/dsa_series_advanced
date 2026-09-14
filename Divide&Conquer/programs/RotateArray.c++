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
	int ans=arr[0];
	reverse(arr.begin(),arr.end());
	reverse(arr.begin(),arr.begin()+m);
	reverse(arr.begin()+m,arr.end());
	for(int i=0;i<n;i++){
		cout<<arr[i];
		if(i!=n-1)cout<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
}