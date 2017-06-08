#include <iostream>
#include <stdlib.h>

/**TO DO
	
	levelorder(using queue)
	Find the common ansestor of two node(3 cases both l, r or l&r)
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

		bool isMirror(TreeNode* root1, TreeNode* root2){
		    if (root1 == NULL && root2 == NULL)
		        return true;
		    //if we have to check value also then compare val in if condition
		    if (root1 && root2 )
		        return isMirror(root1->getLeft(), root2->getRight()) && isMirror(root1->getRight(), root2->getLeft());

    		return false;
		}

		bool isSymmetric(TreeNode* root)
		{
		    return isMirror(root, root);
		}

		int diameter(TreeNode* curr){
		   if (curr == NULL)
		     return 0;

		  int lheight = maxDepth(curr->getLeft());
		  int rheight = maxDepth(curr->getRight());

		  int ldiameter = diameter(curr->getLeft());
		  int rdiameter = diameter(curr->getRight());
		 //explain
		  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
		} 

		// void getLeftNode(TreeNode* root, int n){
		// 	if (root == NULL) {
	 //    		return; 
	 //    	}
  //       	getLeftNode(root->getLeft(), n); 
  //       	getLeftNode(root->getRight(), n); 
        	
  //       	if(root->getLeft()->getVal()==n){
  //       		return left;
  //       	}
  //       	return root;
		// }

		void levelOrder(TreeNode* node){
	        int h = maxDepth(node);
	        int i;
	        for (i=1; i<=h; i++){
	            printlevelOrder(node, i);
	            cout<<"\n";
	        }
	    }

	    void printlevelOrder(TreeNode* curr ,int level){
	        if (curr == NULL)
	            return;
	        if (level == 1){
	            cout<<(curr->getVal());
	        	cout<<" ";
	        }	
	        else if (level > 1)
	        {
	            printlevelOrder(curr->getLeft(), level-1);
	            printlevelOrder(curr->getRight(), level-1);
	        }
	    }

	    bool isBalanced(TreeNode* root){
		   int lh; 
		   int rh; 

		   if(root == NULL)
		    return 1; 

		   lh = maxDepth(root->getLeft());
		   rh = maxDepth(root->getRight());
		 
		   if( abs(lh-rh) <= 1 && isBalanced(root->getLeft()) && isBalanced(root->getRight()))
		     return 1;
		 
		   return 0;
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

        cout<<"5.Invert Tree"<<endl;

        cout<<"7.Sum max and min"<<endl;

        cout<<"8.isSymmetric"<<endl;

        cout<<"9.diameter"<<endl;

        cout<<"10.Lowest common ansestor"<<endl;

        cout<<"11.isBalanced"<<endl;

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
	        cout<<"\n-------------"<<endl;

	        cout<<"levelOrder"<<endl;
	        cout<<"\n-------------"<<endl;
	        T->levelOrder(T->getRoot());
	        cout<<"\n-------------"<<endl;

			

            break;

        case 4:

        	cout<<"\n------No  child-------"<<endl;
            T->LeafNode(T->getRoot());
            cout<<"\n------One child-------"<<endl;
            T->oneChildLeaf(T->getRoot());
            cout<<"\n------Two child-------"<<endl;
            T->twoChildLeaf(T->getRoot());
            break;

        case 5:

           	tempRoot = T->invertTree(T->getRoot());
           	cout<<"\n------inverted-------"<<endl;

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

        case 8:

        	(T->isSymmetric(T->getRoot())) ? cout<<"is symmetric"<<endl : cout<<"is not symmetric"<<endl;
        	break;

        case 9:

        	cout<<(T->diameter(T->getRoot()))<<endl;

        	break;

        case 10:

        	

        	break;

        case 11:

        	(T->isBalanced(T->getRoot())) ? cout<<"is Balanced"<<endl : cout<<"is not Balanced"<<endl;
        	
        	break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    return 0;
}