#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int key;
	cin>>key;
	unordered_set<int>seen;
	int found=0;
	for(int num:arr){
		int complement=key-num;
		if(seen.find(complement)!=seen.end()){
			cout<<"Yes"<<endl;
			found=1;
			break;
		}
		seen.insert(num);
	}
	if(found==0)cout<<"No"<<endl;
	return 0;
}