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

class linkedList{
	private:
		int value;
		linkedList* address;
	public:
		linkedList(int v){
			value=v;
			address=NULL;
		}
		void setValue(int v){
			value=v;
		}
		int getValue(){
			return value;
		}
		void setAddress(linkedList* a){
			address=a;
		}
		linkedList* getAddress(){
			return address;
		}
};


int main(){
	cout<<"Hello World"<<endl;
	return 0;
}

class List{
	private:
		linkedList* root;
	public:
		List(){
			root=NULL;
		}
		List(linkedList* n){
			root=n;
		}
		void setRoot(linkedList* n){
			root = n;
		}
		linkedList* getRoot(){
			return root;
		}
};
