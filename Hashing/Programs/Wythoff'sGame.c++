#include <bits/stdc++.h>
using namespace std;

bool isLosing(int r,int c){
	if(r>c)swap(r,c);
	double phi=(1+sqrt(5))/2;
	int k=c-r;
	int a=floor(k*phi);
	int b=a+k;
	return (a==r && b==c);
}

int main(){
	int k;
	cin>>k;
	vector<string>results;
	while(k--){
		int r,c;
		cin>>r>>c;
		if(isLosing(r,c))results.push_back("sami");
		else results.push_back("canthi");
	}
	for(string s:results)cout<<s<<endl;
	return 0;
}