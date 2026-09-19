#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	int k;
	cin>>k;

	unordered_map<int,int>freq;
	for(int i=0;i<k;i++){
		freq[arr[i]]++;
	}
	cout<<freq.size()<<endl;
	for(int i=k;i<n;i++){
		freq[arr[i-k]]--;
		if(freq[arr[i-k]]==0){
			freq.erase(arr[i-k]);
		}
		freq[arr[i]]++;
		cout<<freq.size()<<endl;
	}
	return 0;
}