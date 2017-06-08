#include <iostream>
#include <stdlib.h>
#include <cmath>

/**TO DO
	
	levelorder
	find the diameter of tree(?)
	check tree is symmetric or not
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
			if(!(curr->getRight()||curr->getLeft())){
				cout<<(curr->getVal())<<endl;
			}
 		}
 		void NodeTwoChild(TreeNode* curr){
 			if(curr==NULL){
 				return;
 			}
 			NodeTwoChild(curr->getLeft());
			NodeTwoChild(curr->getRight());
			if((curr->getRight() && curr->getLeft())){
				cout<<(curr->getVal())<<endl;
			}
 		}
 		int BalancedTree(TreeNode* node){
 			if(node==NULL){
 				//cout<<"Empty tree."<<endl;
 				return 1;
 			}
 			else{
 				int left=maxDepth(node->getLeft());
 				int right=maxDepth(node->getRight());

 				if(left-right < abs(2)){
 					return BalancedTree(node->getLeft()) && BalancedTree(node->getRight());
 				}
 				else{
 					return 0;
 				}


 			}
 		}

 		void OneLeafNode(TreeNode* curr){
 			if(curr==NULL){
 				return;
 			}
 			else{
 				if(curr->getLeft()==NULL && curr->getRight()==NULL){
 					return;
 				}
	 			OneLeafNode(curr->getLeft());
				OneLeafNode(curr->getRight());
				if((curr->getLeft() == NULL && curr->getRight()!=NULL) || (curr->getRight()==NULL && curr->getLeft()!=NULL)){
					cout<<(curr->getVal())<<endl;
				}
 			}
 		}
 		void BothChild(TreeNode* curr){
 			if(curr==NULL){
 				return;
 			}
 			else{
 				BothChild(curr->getLeft());
 				BothChild(curr->getRight());
 				if((curr->getLeft() && curr->getRight())){
 					cout<<curr->getVal()<<endl;
 				}
 			}
 		}

 		int PathMin(TreeNode* curr){
 			if(curr==NULL)
 				return 0;
 			
			int leftDepth=PathMin(curr->getLeft());
			int rightDepth=PathMin(curr->getRight());
			if(curr->getLeft() && curr->getRight()){
				if(leftDepth<rightDepth){
					return(leftDepth + curr->getVal());
				}
				else{
					return(rightDepth + curr->getVal());
				}
			}
 			if(!curr->getRight()){
 				return(leftDepth + curr->getVal());
 			}else{
 				return(rightDepth + curr->getVal());
	 		}
 		}

 		int PathMax(TreeNode* curr){
 			if(curr==NULL){
 				return 0;
 			}
 			int left=PathMax(curr->getLeft());
 			int right=PathMax(curr->getRight());
 			if(curr->getLeft() && curr->getRight()){
 				if(left>right){
 					return left + curr->getVal();
 				}
 				else{
 					return right + curr->getVal();
 				}
 			}
 			if(!curr->getRight()){
 				return(left + curr->getVal());
 			}else{
 				return(right + curr->getVal());
	 		}
 		}

 		int DiameterOfTree(TreeNode* curr){
 			if(curr==NULL){
 				return 0;
 			}
            int leftDepth = maxDepth(curr->getLeft());
            int rightDepth = maxDepth(curr->getRight());
            return (leftDepth+rightDepth);
 		}

 		void LevelOrder(TreeNode* curr, int height)
		{
		    if (curr == NULL){
		        return;
		    }
		    if(height==1){
		    	cout<<curr->getVal()<<endl;
		    }
		   	if(height>1){
		   		LevelOrder(curr->getLeft() , height-1);
		   		LevelOrder(curr->getRight() , height-1);
		   	}
		    
		}
		void printLevelOrder(TreeNode* curr){
			int height=maxDepth(curr);
			for(int i=1;i<=height;i++){
				LevelOrder(curr, i);
			}
		}
};


int main(){
	cout<<"Starting..."<<endl;
	Tree* T =  new Tree();

	TreeNode* tempRoot;
	int choice,item,depthMax,depthMin;
	while (1)

    {

        cout<<"\n-------------"<<endl;

        cout<<"Operations on Tree"<<endl;

        cout<<"\n-------------"<<endl;

        cout<<"1.Insert Element into the Tree"<<endl;

        cout<<"2.Depth of tree"<<endl;

        cout<<"3.Traverse the tree"<<endl;
        
        cout<<"4.Leaf NOde"<<endl;

        cout<<"6.Quit"<<endl;

        cout<<"7. Node with two child."<<endl;

        cout<<"8. Balanced Tree"<<endl;

        cout<<"9. Minimum path"<<endl;

        cout<<"10.Maximum path"<<endl;

        cout<<"11.Diameter of tree."<<endl;

        cout<<"12. Level Order traversal of tree"<<endl;

        cout<<"Enter your Choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Enter value to be inserted into the queue: ";

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

            break;

        case 5:

           	tempRoot = T->invertTree(T->getRoot());

            break;
        case 6:
        	exit(0);
        	break;
        case 7:
        	T->NodeTwoChild(T->getRoot());

        	break;
        case 8:
        	if(T->BalancedTree(T->getRoot())){

        		cout<<"----------"<<endl;
        		cout<<"Balanced tree"<<endl;
        	}
        	else{
        		cout<<"----------"<<endl;
        		cout<<"Not balanced tree"<<endl;
        	}
        	
        	break;
        case 9:
        	cout<<T->PathMin(T->getRoot())<<endl;
        	break;

        case 10:
        	cout<<T->PathMax(T->getRoot())<<endl;
        	break;

        case 11:
        	cout<<T->DiameterOfTree(T->getRoot())<<endl;
        	break;
        case 12:
        	cout<<(T->LevelOrder(T->getRoot(), height))<<endl;
        	break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    return 0;
}


