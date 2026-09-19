#include <bits/stdc++.h>
using namespace std;

int LongestCon(vector<int>&arr){
	int longest=0;
	unordered_set<int>s(arr.begin(),arr.end());
	for(int num:s){
		if(s.find(num-1)==s.end()){
			int current=num;
			int length=1;
			while(s.find(current+1)!=s.end()){
				current++;
				length++;
			}
			longest=max(longest,length);
		}
	}
	return longest;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<LongestCon(arr);
}