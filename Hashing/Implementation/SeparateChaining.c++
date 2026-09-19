class node {
	public :
	int data;
	node * next;
};
class HashTable {
	public:
	node *table[SIZE];
	node* newNode(int x);
	int hash(int x);
	void insertEle(int x);
	void deleteEle(int x);
	void searchEle(int x);
	void display();
};
int HashTable::hash(int x) {
	return x % SIZE;
}
node* HashTable::newNode(int x) {
	// write your code here...
	node*tmp=new node;
	tmp->data=x;
	tmp->next=NULL;
	return tmp;
}
void HashTable::insertEle(int x) {
	// write your code here...
	int index=hash(x);
	node*tmp=newNode(x);
	tmp->next=table[index];
	table[index]=tmp;
}
void HashTable::deleteEle(int x) {
	// write your code here...
	int index=hash(x);
	node*tmp=table[index];
	node*prev=NULL;
	if(tmp==NULL){
		cout<<"Element not found. So cannot delete."<<endl;
		return;
	}
	if(tmp->data==x){
		table[index]=tmp->next;
		delete tmp;
		cout<<"Successfully deleted."<<endl;
		return;
	}
	while(tmp!=NULL && tmp->data!=x){
		prev=tmp;
		tmp=tmp->next;
	}
	if(tmp==NULL){
		cout<<"Element not found. So cannot delete."<<endl;
		return;
	}
	else{
		prev->next=tmp->next;
		cout<<"Successfully deleted."<<endl;
		delete tmp;
		return;
	}
}
void HashTable::searchEle(int x) {
	// write your code here...
	int index=hash(x);
	node*tmp=table[index];
	while(tmp!=NULL && tmp->data!=x){
		tmp=tmp->next;
	}
	if(tmp==NULL){
		cout<<"Element not found."<<endl;
		return;
	}
	else{
		cout<<"Element found."<<endl;
	}
}
void HashTable::display() {
	// write your code here...
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=> ";
		node*tmp=table[i];
		while(tmp!=NULL){
			cout<<tmp->data<<" ";
			tmp=tmp->next;
		}
		cout<<endl;
	}
}
