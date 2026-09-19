#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,size;
	cin>>n>>size;
	if(n==0){
		cout<<"Hash Table is empty"<<endl;
		return 0;
	}
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	vector<int>table(size,-1);
	for(int x:arr){
		int index=x%size;
		bool inserted=false;
		for(int i=0;i<size;i++){
			int newIdx=(index+i*i)%size;
			if(table[newIdx]==-1){
				table[newIdx]=x;
				inserted=true;
				break;
			}
		}
		if(!inserted){
			cout<<"Hash table is full. Cannot insert records from key "<<x<<endl;
			for(int i=0;i<size;i++){
				cout<<"T["<<i<<"] -> "<<table[i]<<endl;
			}
			return 0;
		}
	}
	for(int i=0;i<size;i++){
		cout<<"T["<<i<<"] -> "<<table[i]<<endl;
	}
	return 0;
}