#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char input[1000];
    cin>>input;
    char*token=strtok(input,",");
    int sum=0;
    int largest=-1;
    while(token!=NULL){
        int a=atoi(token);
        sum+=a;
        if(a>largest)largest=a;
        token=strtok(NULL,",");
    }
    int total=largest*(largest+1)/2;
    cout<<total-sum;
    return 0;
}