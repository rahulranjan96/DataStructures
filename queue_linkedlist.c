#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int key;
struct Node *next;
struct Node *prev;
}node;

node *tail;
int x;

void enqueue(node *a)
{
  node *b=(node*)malloc(sizeof(node));
  b->key=x;
  if(a->next==NULL)
  {
  a->next=b;
  b->next=NULL;
  b->prev=a;
  tail=a->next;
  }
 else
 {
  b->next=a->next;
  a->next->prev=b;
  b->prev=a;
  a->next=b;
 }

}
void dequeue(node *a)
{
  if(a->next==NULL)
   printf("Sorry List emptied!!\n");
  else 
   {
    node *b= tail->prev;
    printf("%d\n",tail->key);
    free(tail);
    tail=b;
    tail->next=NULL;
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
  a->key=0;
  a->next=NULL;
  a->prev=NULL;
  int c=0;
  while(1)
{
  printf("1:Enqueue\n2:Dequeue\n3:Print\n4:Exit\nEnter choice:");
  scanf("%d",&c);
  switch(c)
{
  case 1:printf("Enter the element to be enqueued:");
         scanf("%d",&x);
	 enqueue(a);
         break;
  case 2:dequeue(a);
         break;
  case 3:print(a);
         printf("\n");
         break;
  case 4:return 0;
 default:printf("Enter a valid choice\n");
}

}
}
