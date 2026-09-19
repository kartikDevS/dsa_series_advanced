#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr1(n);
	for(int i=0;i<n;i++)cin>>arr1[i];
	int m;
	cin>>m;
	vector<int>arr2(m);
	for(int j=0;j<m;j++)cin>>arr2[j];
	vector<int>result;
	int i=0,j=0;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			result.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j])i++;
		else j++;
	}
	if(result.empty()){
		cout<<-1<<endl;
	}
	else{
		for(int num:result)cout<<num<<" ";
	}
	return 0;
}