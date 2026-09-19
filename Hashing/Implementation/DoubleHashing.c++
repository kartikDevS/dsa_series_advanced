int HashTable[SIZE];

int hash1(int x) {
	return x % SIZE;
}
int hash2(int x) {
	return PRIME - x % PRIME;
}
void insertEle(int x) {
	int index=hash1(x);
	int k=index;
	int i=1;
	while(HashTable[index]!=-1){
		if(HashTable[index]==x){
			cout<<x<<" already exists in the hash table."<<endl;
			return;
		}
		index=(k+i*hash2(x))%SIZE;
		i++;
		if(index==k){
			cout<<"Hash table is full."<<endl;
			return;
		}
	}
	HashTable[index]=x;
	cout<<"Successfully inserted."<<endl;
}
void deleteEle(int x) {
	int index=hash1(x);
	int k=index;
	int i=1;
	while(HashTable[index]!=x){
		index=(k+i*hash2(x))%SIZE;
		i++;
		if(index==k){
			cout<<"Element not found."<<endl;
			return;
		}
	}
	HashTable[index]=-1;
	cout<<"Successfully deleted."<<endl;
}
void searchEle(int x) {
	int index=hash1(x);
	int k=index;
	int i=1;
	while(HashTable[index]!=x){
		if(HashTable[index]==x)break;
		index=(k+i*hash2(x))%SIZE;
		i++;
		if(index==k){
			cout<<"Element not found."<<endl;
			return;
		}
	}
	cout<<"Element found."<<endl;
}
void print() {
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=>"<<HashTable[i];
		cout<<endl;
	}
}
