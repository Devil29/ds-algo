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
};


class linkedList{
	private:
		Node* root;
		int value;
		linkedList* address;
		linkedList(){
		root=NULL;
	
		}
	public:
		linkedList(int v){
			value=v;
			address=NULL;
		}
		void setRoot(int v){
			value=v;
		}
		int getRoot(){
			return value;
		}
		
		linkedList* getAddress(){
			return address;
		}
		void addNode(Node* n){
			if(root==NULL){
				root=n;
			}
			else{
				n->setAddress(root);
				root=n;
			}
		}
		
};


class Node{
	private:
		linkedList* root;
	public:
		Node(){
			root=NULL;
		}
		Node(linkedList* n){
			root=n;
		}
		void setRoot(linkedList* n){
			root = n;
		}
		linkedList* getRoot(){
			return root;
		}
		void setAddress(linkedList* a){
			address=a;
		}
};


int main(){
	cout<<"Hello World"<<endl;
	return 0;
}

