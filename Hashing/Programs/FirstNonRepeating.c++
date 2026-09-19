#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	unordered_map<char,int>seen;
	for(char c:s){
		seen[c]++;
	}
	for(char c:s){
		if(seen[c]==1){
			cout<<c<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}