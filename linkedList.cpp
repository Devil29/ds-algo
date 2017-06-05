#include<iostream>

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
