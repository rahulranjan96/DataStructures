#include<stdio.h>
#include<stdlib.h>

int x=0; 

typedef struct Node{
int key;
struct Node *next;
struct Node *prev;
}node;

void push(node *a)
{
 node *b=(node*)malloc(sizeof(node));
 b->key=x;
 b->next=a->next;
 if(a->next!=NULL)
 a->next->prev=b; 
 a->next=b;
 b->prev=a;

}

void pop(node *a)
{
if(a->next!=NULL)
 {
 printf("%d\n",a->next->key);
 node *b=a->next;
 if(a->next->next!=NULL)
 {
  a->next=a->next->next;
  a->next->prev=a;
 }
else a->next=NULL;
 free(b);
}
else
{
 printf("Sorry Empty List\n");
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
int c;
while(1)
{
printf("1:Push\n2:Pop\n3:Print\n4:Exit\nEnter Choice:");
scanf("%d",&c);
switch(c)
{
case 1:printf("Enter the element to be pushed:");
       scanf("%d",&x);
       push(a);
       break;
case 2:pop(a);
       break;
case 3:print(a);
       printf("\n");
       break;
case 4:return 0;
       break;
default:printf("Enter a Valid Choicei\n");
}
}


}

