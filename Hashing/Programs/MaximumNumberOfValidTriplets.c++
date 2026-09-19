#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<int>arr(N);
	unordered_map<int,int>freq;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		if(arr[i]<=M)freq[arr[i]]++;
	}
	int triplets=0;
	for(auto &p:freq){
		int count=p.second/3;
		triplets+=count;
		freq[p.second]-=count*3;
	}
	for(int i=1;i<=M-2;i++){
		while(freq[i]>0 && freq[i+1]>0 && freq[i+2]>0){
			triplets++;
			freq[i]--;
			freq[i+1]--;
			freq[i+2]--;
		}
	}
	cout<<triplets<<endl;
	return 0;
}