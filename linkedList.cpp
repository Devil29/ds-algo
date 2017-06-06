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
		void setRoot(Node* n){
			next = n;
		}
		Node* getRoot(){
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
		void DeleteNode(){
			if(Head==NULL){
				cout<<"LinkedList is empty."<<endl;
			}
			else{
				Head=Head->getNext();
			}
		}
		
};



int main(){
	cout<<"Hello World"<<endl;
	return 0;
}

