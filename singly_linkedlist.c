#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int key;
  struct Node *next;
}node;

void insert(node *a,int x)
{
 node *b = (node*)malloc(sizeof(node));
 b->next=NULL;
 b->key=x;
 b->next=a->next;
 a->next=b;
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
a->key=0;
a->next=NULL;
int x,i;
while(1)
{
printf("1:Insert\n2:Print\n3:Exit\nEnter Choice:");
scanf("%d",&i);
switch(i)
{
 case 1: printf("Enter the element to be inserted:");
         scanf("%d",&x);
         insert(a,x);
         break;
 case 2: print(a);
         printf("\n");
         break;
 case 3: return 0;
         break;

}

}

}
