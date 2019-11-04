#include<bits/stdc++.h>
using namespace std;
int queue_array[100];
int rear = - 1;
int front = - 1;
void insert()
{
    int add_item;
    if(rear==99)
    	cout<<"Full\n";
    else
    {
        if (front == - 1)
        front = 0;
        cin>>add_item;
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}
 
void Delete()
{
    if (front == - 1 || front > rear)
    {
        cout<<"Queue Underflow \n";
        return ;
    }
    else
    {
        cout<<"Element deleted from queue is : "<<queue_array[front]<<"\n";
        front = front + 1;
    }
}
 
void display()
{
    int i;
    if (front == - 1)
       cout<<"Queue is empty \n";
    else
    {
        cout<<"Queue is : \n";
        for (i = front; i <= rear; i++)
            cout<<queue_array[i]<<" ";
       cout<<" \n";
    }
}
int main()
{
    int choice;
    	cout<<"1.Insert element to queue \n";
        cout<<"2.Delete element from queue \n";
        cout<<"3.Display all elements of queue \n";
        cout<<"4.Quit \n";
        cout<<"Enter your choice : ";
    while (1)
    {
        cin>>choice;
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            Delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            cout<<"Wrong choice \n";
        }
	}
}
