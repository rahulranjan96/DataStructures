#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
 float key;
 struct Node *next;
 struct Node *prev;
}node;

void insert(node *a,float key)
{
  node *b=(node*)malloc(sizeof(node));
  b->key=key;
  b->next=a->next;
  if(a->next!=NULL)
    a->next->prev=b;
  b->prev=a;
  a->next=b;  
}

void print(node *a)
{
 while(a->next!=NULL)
  {
   printf("%f ",a->next->key);
   a=a->next;
  }
}

void bubble_sort(node *a)
{
float temp;
node *b=a;
node *c=a;
 for(;b->next!=NULL;b=b->next)
  for(c=a->next;c->next!=NULL;c=c->next)
   {
    if(c->key > c->next->key)
     { 
       temp=c->key;
       c->key=c->next->key;
       c->next->key=temp; 
     }
   }
}

int main()
{
  int i=0,n=0;
  float num;
  node **a=(node**)malloc(10*sizeof(node*));
  for(i=0;i<10;i++)
  {
    a[i]=(node*)malloc(sizeof(node));
    a[i]->next=NULL;
    a[i]->prev=NULL;
    a[i]->key=i;
  }
  printf("Enter number of elements to be sorted:");
  scanf("%d",&n);
  printf("Enter the elements to be sorted:\n");
  for(i=0;i<n;i++)
   {
     printf("Enter the %dth element:",i+1);
     scanf("%f",&num);
     insert(a[(int)(10*num)],num);
   }
 for(i=0;i<10;i++)
 {
   if(a[i]->next!=NULL)
   bubble_sort(a[i]);
 }
  for(i=0;i<10;i++)
   {
    print(a[i]);
   }
printf("\n");
return 0;
}
