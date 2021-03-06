#include <iostream>
#include <cstdlib>
using namespace std;

struct node

{

    int info;

    struct node *link;    

}*front, *rear;

class queue_list

{

    public:

        void insert(int);

        void display();

        void del();

        queue_list()

        {

            front = NULL;

            rear = NULL;

        }               

};

void queue_list::insert(int item)

{

    node *tmp;

    tmp = new (struct node);

    tmp->info = item;

    tmp->link = NULL;

    if (front == NULL)

        front = tmp;

    else

        rear->link = tmp;

    rear = tmp;

}

int queue_list::del()

{

    node *tmp;

    if (front == NULL){

        cout<<"Queue Underflow"<<endl;
    	return -1;
    }
    else

    {       

        tmp = front;

        cout<<"Element Deleted: "<<tmp->info<<endl;
        tempPrint = temp->info ;
        front = front->link;

        free(tmp);
        return tempPrint;

    }
    return -1;
}

void queue_list::display()

{       

    node *ptr;

    ptr = front;

    if (front == NULL)

        cout<<"Queue is empty"<<endl;

    else

    {

        cout<<"Queue elements :"<<endl;

        while (ptr != NULL)

        {

            cout<<ptr->info<<" ";

            ptr = ptr->link;

        }

        cout<<endl;

    }

}

int Queue(int item){
	queue_list ql;

	if(item == -1){
		return ql.del();
	}else{
		ql.insert(item);
		return -1;
	}
	

}

int main()

{

    int choice, item;

    queue_list ql;

    while (1)

    {

        cout<<"\n-------------"<<endl;

        cout<<"Operations on Queue"<<endl;

        cout<<"\n-------------"<<endl;

        cout<<"1.Insert Element into the Queue"<<endl;

        cout<<"2.Delete Element from the Queue"<<endl;

        cout<<"3.Traverse the Queue"<<endl;

        cout<<"4.Quit"<<endl;

        cout<<"Enter your Choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Enter value to be inserted into the queue: ";

            cin>>item;

            ql.insert(item);

            break;

        case 2:

            ql.del();

            break;

        case 3:

            ql.display();

            break;

        case 4:

            exit(1);

            break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    return 0;

}