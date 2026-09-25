#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high,int*rcount,int*ccount){
	int i=low,j=mid+1,temp[high-low+1],idx=0;
	while(i<=mid && j<=high){
		(*ccount)++;
		if(arr[i]<=arr[j]){
			temp[idx]=arr[i];
			i++;
			idx++;
		}
		else{
			temp[idx]=arr[j];
			j++;
			idx++;
		}
	}
	while(i<=mid){
		temp[idx]=arr[i];
		idx++;
		i++;
	}
	while(j<=high){
		temp[idx]=arr[j];
		idx++;
		j++;
	}
	for(int k=0;k<(high-low+1);k++){
		arr[k+low]=temp[k];
	}
}

void mergesort(int arr[],int low,int high,int*rcount,int*ccount){
	(*rcount)++;
	if(low<high){
		int mid=low+(high-low)/2;
		mergesort(arr,low,mid,rcount,ccount);
		mergesort(arr,mid+1,high,rcount,ccount);
		merge(arr,low,mid,high,rcount,ccount);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int rcount=0,ccount=0;
	mergesort(arr,0,n-1,&rcount,&ccount);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	cout<<rcount<<'\n'<<ccount<<'\n';
}