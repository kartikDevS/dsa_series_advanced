#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

class node{
public:
int data;
node*next;
};

class HashTable{
	public:
	node *table[SIZE];
	node* newNode(int x);
	int hash(int x);
	void insert(int x);
	void deleteE(int x);
	void search(int x);
	void display();
};

int HashTable:: hash(int x){
	return x%SIZE;
}

node* HashTable:: newNode(int x){
	node*tmp=new node;
	tmp->data=x;
	tmp->next=NULL;
	return tmp;
}

void HashTable::insert(int x){
	int index=hash(x);
	node *tmp=newNode(x);
	tmp->next=table[index];
	table[index]=tmp;
}

void HashTable::deleteE(int x){
	int index=hash(x);
	node*tmp=table[index];
	node*prev=NULL;
	if(tmp==NULL){
		return ;
	}
	if(tmp->data==x){
		table[index]=tmp->next;
		delete tmp;
		return;
	}
	while(tmp!=NULL && tmp->data!=x){
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp==NULL){
		return;
	}
	else{
		prev->next=tmp->next;
		delete tmp;
		return;
	}
}

void HashTable::search(int x){
	int index=hash(x);
	node*tmp=table[index];
	if(tmp==NULL){
		cout<<"Not Found\n";
		return;
	}
	if(tmp->data==x){
		cout<<"Found\n";
		return;
	}
	while(tmp!=NULL && tmp->data!=x){
		tmp=tmp->next;
	}
	if(tmp==NULL){
		cout<<"Not Found\n";
		return;
	}
	else{
		cout<<"Found\n";
		return;
	}
}

void HashTable::display(){
	for(int i=0;i<SIZE;i++){
		cout<<"Bucket["<<i<<"]:";
		node*tmp=table[i];
		while(tmp!=NULL){
			cout<<" "<<tmp->data;
			tmp=tmp->next;
		}
		cout<<"\n";
	}
}

int main(){
	HashTable ht;
	for(int i=0;i<SIZE;i++){
		ht.table[i]=NULL;
	}
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ht.insert(x);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		switch(a){
			case 1:
				ht.insert(b);
				break;
			case 2:
				ht.deleteE(b);
				break;
			case 3:
				ht.search(b);
				break;
		}
	}
	ht.display();
}