#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int key;
struct Node *next;
struct Node *prev;
}node;

void insert(node *a,int key)
{
 node *b=(node*)malloc(sizeof(node));
 b->key=key;
 b->next=a->next;
 if(a->next!=NULL)
   a->next->prev=b;
 a->next=b;
 b->prev=a;
}

void print(node *a)
{
 while(a->next!=NULL)
{
 printf("%d ",a->next->key);
 a=a->next;
}
 printf("\n");
}

node* reverse(node *a)
{
 if(a->next==NULL)
 {
 printf("Sorry Empty List!!\n");
  return a;
 }
 else{
  node *b=NULL;
  a=a->next;
  b=a->next;
  free(a->prev);
  a->next=NULL;
  a->prev=b;
  if(b!=NULL)
  {
    a=b;
    while(a->next!=NULL)
    {
      b=a->next;
      a->next=a->prev;
      a->prev=b;
      a=b;
    }
    node *c=(node*)malloc(sizeof(node));
    c->prev=NULL;
    c->key=0;
    c->next=a;
    a->next=a->prev;
    a->prev=c;
    return c;
  }
  else{
    node *c=(node*)malloc(sizeof(node));
    c->prev=NULL;
    c->key=0;
    c->next=a;
    a->prev=c;
    return c;
  }
}
}

int main()
{
 node *a=(node*)malloc(sizeof(node));
 a->next=NULL;
 a->prev=NULL;
 a->key=0;
 int c=0,key=0;
 while(1)
{
 printf("1:Insert\n2:Reverse\n3:Print\n4:Exit\nEnter your choice:");
 scanf("%d",&c);
 switch(c)
{
  case 1:printf("Enter the Key to be inserted:");
         scanf("%d",&key);
         insert(a,key);
         break;
  case 2:a=reverse(a);
         break;
  case 3:print(a);
        break;
  case 4:return 0;
 default:printf("Enter a valid Choice!!\n");        
}
}
}
