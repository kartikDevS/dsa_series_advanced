#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int k;
	cin>>k;
	unordered_map<int,int> freq;
	vector<int>order;

	for(int x:arr){
		if(freq.find(x)==freq.end()){
			order.push_back(x);
		}
		freq[x]++;
	}
	sort(order.begin(),order.end(),[&](int a,int b){
		if(freq[a]!=freq[b])return freq[a]>freq[b];
		return find(arr.begin(),arr.end(),a)<find(arr.begin(),arr.end(),b);
	});

	for(int i=0;i<k;i++){
		cout<<order[i]<<" ";
	}
	cout<<endl;
}