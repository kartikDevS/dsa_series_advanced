#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	unordered_map<int,int>lastIndex;
	int dist;
	cin>>dist;
	int found=0;
	for(int i=0;i<n;i++){
		int num=arr[i];
		if(lastIndex.find(num)!=lastIndex.end()){
			if(i-lastIndex[num]<=dist){
				cout<<"True"<<endl;
				found=1;
				break;
			}
		}
		lastIndex[num]=i;
	}
	if(found==0)cout<<"False"<<endl;
	return 0;
}