#include<iostream>
using namespace std;

typedef struct Node{
	int key;
	struct Node *next;
	struct Node *prev;
}node;

void insert(node *a,int key)
{
	node *b=new node[1];
	b->key=key;
	b->next=a->next;
	b->prev=a;
	a->next=b;
	if(b->next!=NULL)
		b->next->prev=b;
}

void print(node *a)
{
	while(a->next!=NULL)
	{
		cout<<a->next->key<<" ";
		a=a->next;
	}
	cout<<"\n";
}

void mergesort(node *list)
{
	//cout<<"Sorted\n";
	node *head=list;
	node *a,*b;
	if(list->next==NULL||list==NULL)
		return;
	FrontBackSplit(head,a,b);
	mergesort(a);
	mergesort(b);
	list=SortedMerge(a,b);
}

void FrontBackSplit(node *source,node *a,node *b)
{
	node *slow,*fast;
	if(source==NULL||source->next==NULL)
		{
			a=source;
			b=NULL;
		}
	else{
		slow=source;
		fast=source->next;
		while(b!=NULL)
		{
			b=b->next;
			if(b->next!=NULL)
			{
				a=a>next;
				b=a->next;
			}
		}
	}
}

int main()
{
   node *list=new node[1];
   list->key=0;
   list->next=NULL;
   list->prev=NULL;
   int key=0,c=0;
   while(1)
   {
   	cout<<"1).Insert\n2).Sort\n3).Print\n4).Exit\nEnter Choice:";
   	cin>>c;
   	switch(c)
   	{
   		case 1:cout<<"Enter the number to be inserted\n";
   		       cin>>key;
   		       insert(list,key);
   		       break;
   		case 2:mergesort(list);
   		       break;
   		case 3:print(list);
   		      break;
   		case 4:return 0;
   		default:cout<<"Enter a valid Choice\n";
   		        break;
   	}
   }
   delete list;
   return 0;
}