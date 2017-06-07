#include <iostream>
#include <stdlib.h>

/**TO DO
	
	levelorder
	find the diameter of tree(?)
	check tree is symmetric or not
	find tree is balanced or not
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
		
			if(curr->getVal() >= newNode->getVal()){
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

		//depth
		int maxDepth(TreeNode* node){
	        if (node == NULL)
	            return 0;
	        else
	        {
	            int leftDepth = maxDepth(node->getLeft());
	            int rightDepth = maxDepth(node->getRight());
	  
	            if (leftDepth > rightDepth)
	                return (leftDepth + 1);
	             else
	                return (rightDepth + 1);
	        }
	    }

	    int minDepth(TreeNode* node){
	        if (node == NULL)
	            return 0;
	        else
	        {
	            int leftDepth = maxDepth(node->getLeft());
	            int rightDepth = maxDepth(node->getRight());
	  
	            if (leftDepth < rightDepth)
	                return (leftDepth + 1);
	             else
	                return (rightDepth + 1);
	        }
	    }

	    TreeNode* invertTree(TreeNode* root) {
	    	if (root == NULL) {
	    		return NULL; 
	    	}
        	TreeNode* left = invertTree(root->getLeft()); 
        	TreeNode* right = invertTree(root->getRight()); 
        	root->setLeft(right);  
        	root->setRight(left);  
        	return root;
    	}
    	void LeafNode(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			LeafNode(curr->getLeft());
			LeafNode(curr->getRight());
			if(!(curr->getRight() || curr->getLeft())){
				cout<<(curr->getVal())<<endl;
			}
 		}

 		void oneChildLeaf(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			oneChildLeaf(curr->getLeft());
			oneChildLeaf(curr->getRight());
			if((!(curr->getRight()) && curr->getLeft()) || (curr->getRight() && !(curr->getLeft()))){
				cout<<(curr->getVal())<<endl;
			}
 		}
 		void twoChildLeaf(TreeNode* curr){
			if(curr == NULL){
				return;
			}
			twoChildLeaf(curr->getLeft());
			twoChildLeaf(curr->getRight());
			if((curr->getRight() && curr->getLeft())){
				cout<<(curr->getVal())<<endl;
			}
 		}

 		int max(int a, int b){
 			return (a >= b)? a: b;
 		}
 
		int maxPathSum(TreeNode* curr){
		    if(curr==NULL)
		    	return 0;
		    if(!curr->getLeft() && !curr->getRight())
		    	return curr->getVal();
		    int ls = maxPathSum(curr->getLeft());
		    int rs = maxPathSum(curr->getRight());

			if(curr->getLeft() && curr->getRight()){
				return max(ls, rs) + curr->getVal();
			}

		    return (!curr->getLeft())? rs + curr->getVal(): ls + curr->getVal();
		}

		int min(int a, int b){
			return (a <= b)? a: b;
		}

		int minPathSum(TreeNode* curr){
		    if(curr==NULL)
		    	return 0;
		    if(!curr->getLeft() && !curr->getRight())
		    	return curr->getVal();
		    int ls = minPathSum(curr->getLeft());
		    int rs = minPathSum(curr->getRight());

			if(curr->getLeft() && curr->getRight()){
				return min(ls, rs) + curr->getVal();
			}
			
		    return (!curr->getLeft())? rs + curr->getVal(): ls + curr->getVal();
		}
};


int main(){
	cout<<"Starting..."<<endl;
	Tree* T =  new Tree();

	TreeNode* tempRoot;
	int choice,item,depthMax,depthMin, sumMax, sumMin;
	while (1)

    {

        cout<<"\n-------------"<<endl;

        cout<<"Operations on Tree"<<endl;

        cout<<"\n-------------"<<endl;

        cout<<"1.Insert Element into the Tree"<<endl;

        cout<<"2.Depth of tree"<<endl;

        cout<<"3.Traverse the tree"<<endl;
        
        cout<<"4.Leaf Node"<<endl;

        cout<<"6.Quit"<<endl;

        cout<<"Enter your Choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Enter value to be inserted into the tree: ";

            cin>>item;

            T->addNode(item);

            break;

        case 2:

           	depthMax = T->maxDepth(T->getRoot());
           	depthMin = T->minDepth(T->getRoot());
           	cout<<"maxDepth ="<<depthMax<<endl;
           	cout<<"minDepth ="<<depthMin<<endl;

            break;

        case 3:
	        cout<<"\n-------------"<<endl;

	        cout<<"Inorder"<<endl;

	        cout<<"\n-------------"<<endl;
            T->printInOrder(T->getRoot());
            cout<<"\n-------------"<<endl;

	        cout<<"PostOrder"<<endl;

	        cout<<"\n-------------"<<endl;
			T->printPostOrder(T->getRoot());
			cout<<"\n-------------"<<endl;

	        cout<<"PreOrder"<<endl;

	        cout<<"\n-------------"<<endl;
			T->printPreOrder(T->getRoot());

            break;

        case 4:

            T->LeafNode(T->getRoot());
            cout<<"\n------One child-------"<<endl;
            T->oneChildLeaf(T->getRoot());
            cout<<"\n------Two child-------"<<endl;
            T->twoChildLeaf(T->getRoot());
            break;

        case 5:

           	tempRoot = T->invertTree(T->getRoot());

            break;
        case 6:
        	exit(0);
        	break;

        case 7:

        	sumMax = T->maxPathSum(T->getRoot());
        	cout<<sumMax<<endl;
        	sumMin = T->minPathSum(T->getRoot());
        	cout<<sumMin<<endl;

        	break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    return 0;
}


