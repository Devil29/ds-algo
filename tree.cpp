#include <iostream>

/**TO DO
	
	insert a node
	levelorder
	MaxheightofTree
	Min Height of tree
	Invert Tree
	Find all leaf node of tree
	find all tree with one child
	find all tree with two childs
	find the diameter of tree
	check tree is symmetric of not
	find tree is balanced or not
	Max root to leave sum
	min  root to leave sum
	Find the common ansestor of two node
	convert a tree to linked list

*/

using namespace std;

class TreeNode{
	private: 
		int val;
		TreeNode* left;
		TreeNode* right;

	
	public:
		TreeNode(int n){
			val=n;
			left=NULL;
			right=NULL;
		}
		void setVal(int v){
			val=v;
		}
		int getVal(){
			return val;
		}
		void setLeft(TreeNode* l){
			left=l;
		}
		TreeNode* getLeft(){
			return left;
		}
		void setRight(TreeNode* r){
			right=r;
		}
		TreeNode* getRight(){
			return right;
		}
};


class Tree{
	private:
		TreeNode* root;

	public:
		Tree(){
			root = NULL;
		}
		Tree(TreeNode* n){
			root = n;
		}
		void setRoot(TreeNode* n){
			root = n;
		}
		TreeNode* getRoot(){
			return root;
		}

		void printInOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			printInOrder(curr->getLeft());
			cout<<(curr->getVal())<<endl;
			printInOrder(curr->getRight());
 		}

 		void printPostOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			printPostOrder(curr->getLeft());
			printPostOrder(curr->getRight());
			cout<<(curr->getVal())<<endl;
 		}

 		void printPreOrder(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			cout<<(curr->getVal())<<endl;
			printPreOrder(curr->getLeft());
			printPreOrder(curr->getRight());
 		}

 		void addNodeToTree(TreeNode* curr,TreeNode* newNode ){
		
			if(curr->getVal() > newNode->getVal()){
				if(curr->getLeft()==NULL)
					curr->setLeft(newNode);
				else
					addNodeToTree(curr->getLeft(),newNode);
			}
			else{
				if(curr->getRight()==NULL)
					curr->setRight(newNode);
				else
					addNodeToTree(curr->getRight(),newNode);
			}
		}

		void addNode(int n){
			cout<<"adding..."<<endl;
			TreeNode* newNode =new TreeNode(n);
			if(root==NULL){
				root=newNode;
			}
			else{
				addNodeToTree(root,newNode);
			}
		}
};


int main(){
	cout<<"Hello World"<<endl;
	TreeNode* root = new TreeNode(20);
	Tree* T =  new Tree(root);

	TreeNode* temp = new TreeNode(5);
	T->getRoot()->setLeft(temp);
	// temp = new TreeNode(3);
	// T->getRoot()->getLeft()->setLeft(temp);
	// temp = new TreeNode(2);
	// T->getRoot()->getLeft()->setRight(temp);
	// temp = new TreeNode(6);
	// T->getRoot()->setRight(temp);
	// temp = new TreeNode(7);
	// T->getRoot()->getRight()->setLeft(temp);
	// temp = new TreeNode(9);
	// T->getRoot()->getRight()->setRight(temp);
	T->addNode(1);
	T->addNode(2);
	T->addNode(3);
	T->addNode(7);
	T->addNode(8);
	T->addNode(9);


	T->printInOrder(T->getRoot());
	T->printPostOrder(T->getRoot());
	T->printPreOrder(T->getRoot());

	return 0;
}


