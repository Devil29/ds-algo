#include <iostream>

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
				cout<<"Hello World"<<endl;
				// return 0;
			}
			printInOrder(curr->getLeft());
			cout<<(curr->getVal())<<endl;;
			printInOrder(curr->getRight());
 	}

};


int main(){
	cout<<"Hello World"<<endl;
	TreeNode* root = new TreeNode(10);
	Tree* T =  new Tree(root);

	TreeNode* temp = new TreeNode(5);
	T->getRoot()->setLeft(temp);
	temp = new TreeNode(3);
	T->getRoot()->getLeft()->setLeft(temp);
	temp = new TreeNode(2);
	T->getRoot()->getLeft()->setRight(temp);
	temp = new TreeNode(6);
	T->getRoot()->setRight(temp);
	temp = new TreeNode(7);
	T->getRoot()->getRight()->setLeft(temp);
	temp = new TreeNode(9);
	T->getRoot()->getRight()->setRight(temp);

	T->printInOrder(T->getRoot());
	return 0;
}


