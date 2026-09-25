#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];

	unordered_map<string,vector<string>> groups;
	vector<string>order;
	for(string s:arr){
		string key=s;
		sort(key.begin(),key.end());
		if(groups.find(key)==groups.end()){
			order.push_back(key);
		}
		groups[key].push_back(s);
	}
	vector<vector<string>>result;
	for(string key:order){
		result.push_back(groups[key]);
	}
	sort(result.begin(),result.end(),[](const vector<string>&a,const vector<string>&b){
		return a[0]<b[0];
	});
	for(auto&group:result){
		for(auto&word:group){
			cout<<word<<" ";
		}
		cout<<endl;
	}
	return 0;
}