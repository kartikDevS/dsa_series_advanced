#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int freq;
};

class HashTable{
    public:
    int tablesize;
    vector<list<Node>>table;
    vector<int>order;
    HashTable(int x) : tablesize(x) {
        table.resize(tablesize);
    }
    int hashF(int x);
    void insert(int x);
    int getfrequency(int x);
    void printfrequency();
};

int HashTable:: hashF(int x){
    return x%tablesize;
}

void HashTable:: insert(int x){
    int index=hashF(x);
    for(auto &node:table[index]){
        if(node.data==x){
            node.freq++;
            return;
        }
    }
    table[index].push_back({x,1});
    order.push_back(x);
}

int HashTable::getfrequency(int x){
    int index=hashF(x);
    for(auto &node:table[index]){
        if(node.data==x){
            return node.freq;
        }
    }
    return 0;
}

void HashTable::printfrequency(){
    for(int num:order){
        cout<<num<<":"<<getfrequency(num)<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    HashTable t=10;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        t.insert(x);
    }
    t.printfrequency();
    return 0;
}