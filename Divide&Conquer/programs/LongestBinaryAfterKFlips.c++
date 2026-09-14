#include <iostream>
#include <vector>
using namespace std;

int LongestBinaryAfterKFlips(vector<int>&arr,int k){
    int left=0;int right=0;
    int zeroCount=0;
    int maxLen=0;
    while(right<arr.size()){
        if(arr[right]==0)zeroCount++;
        while(zeroCount>k){
            if(arr[left]==0)zeroCount--;
            left++;
        }
        maxLen=max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<LongestBinaryAfterKFlips(arr,k)<<endl;
    return 0;
}