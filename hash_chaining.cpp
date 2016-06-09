#include<iostream>
using namespace std;

typedef struct Node{
int key;
struct Node *next;
struct Node *prev;
}node;

void insert(node *a,int key)
{
 node *b=new node;
 b->next=a->next;
 b->prev=a;
 b->key=key;
 a->next=b;
 if(b->next!=NULL)
  b->next->prev=b;
}

node* search(node *a,int key)
{
 while(a->next!=NULL)
  {
    if(a->next->key==key)
     {
       cout<<"Found\n";
       return a->next;
     }
    a=a->next;
  }
cout<<"Not Found\n";
}

void del(node *a,int key)
{
 node *b=search(a,key);
 if(b!=NULL)
 {
   b->prev->next=b->next;
   if(b->next!=NULL)
   b->next->prev=b->prev;
   delete b;
 }
}

void print(node *a)
{
 while(a->next!=NULL)
{
 cout<<a->next->key<<" ";
 a=a->next;
}
}

int main()
{
 node **table=new node*[10];
 for(int i=0;i<10;i++)
  {
   table[i] = new node;
   table[i]->key=0;
   table[i]->next=NULL;
   table[i]->prev=NULL;
  }
int key=0,c=0;
 while(1)
{
 cout<<"1:Insert\n2:Search\n3:Delete\n4:Print\n5:Exit\nEnter Choice:";
 cin>>c;
 switch(c)
{
 case 1:cout<<"Enter the key to be added:";
        cin>>key;
        insert(table[key%10],key);
        break;
 case 2:cout<<"Enter the key to be searched:";
        cin>>key;
        search(table[key%10],key);
        break;
 case 3:cout<<"Enter the key to be deleted:";
        cin>>key;
        del(table[key%10],key);
        break;
 case 4:for(int i=0;i<10;i++)
        {
          if(table[i]->next!=NULL)
          {
          print(table[i]);
          cout<<"\n";
          }
        }
        break;
 case 5:return 0;
 default:cout<<"Enter a valid Choice\n";
}
}
return 0; 
}
