#include<bits/stdc++.h>
#include<string>
using namespace std;
class Node
{
	public:
	int data1;
	int data2;
	Node*next;
};
void Add(Node**head_ref,int a,int b)
{
	Node*new_node= new Node();
	new_node->data1=a;
	new_node->data2=b;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
int DeleteFirst(Node**head)
{
	if(*head==NULL)
	{	
		cout<<"\n";
		cout<<"Linked list is empty";
		return(-1);
	}
	Node*temp=*head;
	*head=temp->next;
	delete temp;
	return(0);
}
int Delete(Node**head,int x,int y)
{
	if(*head==NULL)
	{	
		cout<<"\n";
		cout<<"Linked list is empty";
		return(-1);
	}
	int count=-1;
	Node*temp=*head;
	Node*cat=*head;
	while(temp!=NULL)
	{
		if(temp->data1!=x&&temp->data2!=y)
		{
			count++;
			break;
		}
		temp=temp->next;		
	}
	if(temp==NULL)
	{	
		cout<<"\n";
		cout<<"Numbers is not present";
		cout<<"\n";
		return -1;
	}
	if(count==0)
	{
		*head=cat->next;
		delete cat;
		return(0);
	}
	for(int i=0;cat!=NULL && i<count-1;i++)
		cat=cat->next;
	Node*Dog=cat->next->next;
	delete cat->next;
	cat->next=Dog;
	return(0);
}
void Search(Node**head,float d)
{
	Node*temp=*head;
	while(temp!=NULL)
	{
		float a=sqrt((temp->data1)*(temp->data1)+(temp->data2)*(temp->data2));
		if(a<=d)
		{
			cout<<"\n";
			cout<<temp->data1<<" "<<temp->data2;
			cout<<"\n";
		}
		temp=temp->next;
	}
}
void Search2(Node**head,int x,int y)
{
	Node*temp=*head;
	while(temp!=NULL)
	{
		if(temp->data1==x&&temp->data2==y)
		{
			cout<<"\n";
			cout<<"True";
			cout<<"\n";
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"\n";
		cout<<"False";
		cout<<"\n";
	}
}
void Length(Node**head)
{
	Node*temp=*head;
	int count=0;
	while(temp!=NULL)
	{	
		temp=temp->next;
		count++;
	}
	cout<<"\n";
	cout<<count;
	cout<<"\n";
}
int main()
{
	Node*head=NULL;
	int t;
	cin>>t;
	while(t!=0)
	{
		int a;
		cin>>a;
		switch(a)
		{
			case 1:
				int x,y;
				cin>>x;
				cin>>y;
				Add(&head,x,y);
				t--;
				break;
			case 2:
				int A;
				A=DeleteFirst(&head);
				cout<<A;
				t--;
				break;
			case 3:
				int p,q,B;
				cin>>p;
				cin>>q;
				B=Delete(&head,p,q);
				cout<<"\n";
				cout<<B;
				cout<<"\n";
				t--;
				break;
			case 4:
				float d;
				cin>>d;
				Search(&head,d);
				t--;
				break;
			case 5:
				int r,s;
				cin>>r;
				cin>>s;
				Search2(&head,r,s);
				t--;
				break;
			case 6:
				Length(&head);
				t--;
				break;
		}
	}
}
