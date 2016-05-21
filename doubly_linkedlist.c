#include<stdio.h>
#include<stdlib.h>



typedef struct Node
{
	int key;
	struct Node *next;
	struct Node *prev;
}node;

void insert(node *a,int key)
{
	node *b=(node*)malloc(sizeof(node));
	b->prev=NULL;
	b->next=NULL;
	b->key=key;
	if(a->next==NULL)
	{
		a->next=b;
		b->prev=a;
	}
	else
	{
		a->next->prev=b;
		b->next=a->next;
		a->next=b;
		b->prev=a;
	}
}

void print(node *a)
{
	while(a->next!=NULL)
	{
		printf("%d ",a->next->key);
		a=a->next;
	}
}

int main()
{
	node *a=(node*)malloc(sizeof(node));
	a->next=NULL;
	a->prev=NULL;
	a->key=0;
	int i,x;
	while(1)
	{
		printf("1:Insert\n2:Print\n3:Exit\nEnter Choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("Enter the number to be inserted:");
			       scanf("%d",&x);
			       insert(a,x);
			       break;
			case 2:print(a);
			       printf("\n");
			       break;
			case 3:return 0;
		}

	}

}
