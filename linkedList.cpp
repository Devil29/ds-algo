#include <iostream>

/**TO DO

	search all node
	print linked list
	print linked list from last
	reverse linked list
	check linked list have a cycle or not
	find the linked list is palindrome or not
	convert to double linked list
	remove a element in the linked list
	
*/

using namespace std;

class Node{
	private:
		Node* next;
		int value;
	public:
		Node(int v){
			value=v;
			next=NULL;
		}
		Node(Node* n){
			next=n;
		}
		void setVal(Node* n){
			next = n;
		}
		Node* getVal(){
			return next;
		}
		void setNext(Node* a){
			next=a;
		}
		Node* getNext(){
			return next;
		}
};


class linkedList{
	private:
		Node* Head;
		
	public:
		linkedList(){
			Head=NULL;
		}

		linkedList(Node *n){
			Head=n;
		}

		void setHead(Node* h){
			Head = h;
		}

		Node getHead(){
			return Head;
		}

		void addNode(Node* n){
			if(Head==NULL){
				Head=n;
			}
			else{
				n->setNext(Head);
				Head=n;
			}
		}

		void printLinkedList(){
			Node* temp = Head;
        	while(temp!= NULL){
            	cout<<(temp->getVal())<<endl;
            	temp = temp->getNext();
			}
			cout<<"<--finished"<<endl;
		}

		void DeleteNode(){
			if(Head==NULL){
				cout<<"LinkedList is empty."<<endl;
			}
			else{
				Head=Head->getNext();
			}
		}
		void addNodeLast(Node* n){
			Node* temp=Head;
			Node* temp2=temp;
			while(temp!=NULL){
				temp2=temp;
				temp=temp->getNext();
			}
			temp2->setNext(n);
		}
		
};



int main(){
	int n;
	cout<<"Hello World"<<endl;
	int q;
	linkedList* obj = new linkedList();
	while(1){
		cout<<"1 Enter root node"<<endl;
		cout<<"2 Add a node"<<endl;
		cout<<"3 Delete a node from beginning"<<endl;
		cout<<"4 Print the linkedList"<<endl;
		
		cin>>n;
		switch(n){
			case 1:
				// ll->getHead();
				break;
			case 2:{
				cout<<"Add node :"<<endl;
				cin>>q;
				Node* x=new Node(q);
				obj->addNode(x);					
				break;
			}
			case 3:
				break;
			case 4:
				obj->printLinkedList();
				break;
			
		}
	}
	return 0;
}

