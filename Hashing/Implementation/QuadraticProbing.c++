int HashTable[SIZE];
int hash_function(int x) {
	return x % SIZE;
}
void insertEle(int x) {
	// write your code here...
	int index=hash_function(x);
	int start=index;
	int i=1;
	while(HashTable[index]!=-1){
		index=(start+(i*i))%SIZE;
		i++;
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
	int i=1;
	while(HashTable[index]!=x){
		index=(start+(i*i))%SIZE;
		i++;
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
	int i=1;
	while(HashTable[index]!=x){
		index=(start+(i*i))%SIZE;
		i++;
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