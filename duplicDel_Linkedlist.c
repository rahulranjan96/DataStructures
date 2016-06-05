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
b->prev=a;
b->next=a->next;
a->next=b;
if(b->next!=NULL)
 b->next->prev=b;
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

void deldup(node *a)
{
 node *b=NULL,*c=NULL,*temp=NULL;
 for(b=a->next;b->next!=NULL;b=b->next)
  for(c=b->next;c!=NULL;c=c->next)
   {
    if(c->key==b->key)
     {
      c->prev->next=c->next;
      if(c->next!=NULL)
        c->next->prev=c->prev;
      temp=c;
      free(temp);
     }
   }
}


int main()
{
 node *list=(node*)malloc(sizeof(node));
 list->next=NULL;
 list->prev=NULL;
 list->key=0;
 int c,x;
 while(1)
{
  printf("1:Insert\n2:Delete Duplicates\n3:Print\n4:Exit\nEnter Choice:");
  scanf("%d",&c);
 switch(c)
{
 case 1:printf("Enter the element to be inserted:");
        scanf("%d",&x);
        insert(list,x);
        break;
 case 2:deldup(list);
        break;
 case 3:print(list);
        break;
 case 4:return 0;
 default:printf("Enter a valid choice\n");
         break;
}
}
 return 0;
}
