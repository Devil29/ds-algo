#include <iostream>

using namespace std;

class treeNode{
	private: 
		int val;
		treeNode* left;
		treeNode* right;

	
	public:
		treeNode(int n){
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
		void setLeft(treeNode* l){
			left=l;
		}
		treeNode* getLeft(){
			return left;
		}
		void setRight(treeNode* r){
			right=r;
		}
		treeNode* getRight(){
			return right;
		}
};



int main(){
	cout<<"Hello World"<<endl;
	return 0;
}
