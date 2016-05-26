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

void delete(node *a,int key)
{
 int flag=0;
  while(a->next!=NULL)
{
   if(a->key==key)
     {
      flag=1;
      break;
     }
  a=a->next;
}
  if(flag==0)
  printf("Element not found!!\n");
  else{
   a->prev->next=a->next;
   a->next->prev=a->prev;
   free(a); 
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
 printf("1:Insert\n2:Delete\n3:Print\n4:Exit\nEnter your choice:");
 scanf("%d",&c);
 switch(c)
{
  case 1:printf("Enter the Key to be inserted:");
         scanf("%d",&key);
         insert(a,key);
         break;
  case 2:printf("Enter the element to be deleted:");
         scanf("%d",&key);
         delete(a,key);
         break;
  case 3:print(a);
         break;
  case 4:return 0;
 default:printf("Enter a valid Choice!!\n");        
}
}
}
