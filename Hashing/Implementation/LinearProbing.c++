int HashTable[SIZE];
int hash_function(int x) {
	return x % SIZE;
}
void insertEle(int x) {
	// write your code here...
	int index,start;
	index=hash_function(x);
	start=index;
	while(HashTable[index]!=-1){
		index=(index+1)%SIZE;
		if(index==start){
			cout<<"Hash Table is full."<<endl;
			return;
		}
	}
	HashTable[index]=x;
	cout<<"Successfully inserted."<<endl;
}
void deleteEle(int x) {
	// write your code here...
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){
		index=(index+1)%SIZE;
		if(index==start){
			cout<<"Element not found. So cannot delete the element."<<endl;
			return;
		}
	}
	HashTable[index]=-1;
	cout<<"Successfully deleted."<<endl;
}
void searchEle(int x) {
	// write your code here...
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){
		index=(index+1)%SIZE;
		if(index==start){
			cout<<"Element not found."<<endl;
			return;
		}
	}
	cout<<"Element found."<<endl;
}
void print() {
	// write your code here...
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=>"<<HashTable[i];
			cout<<endl;
	}
}
