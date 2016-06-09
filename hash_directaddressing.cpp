#include<iostream>
using namespace std;

void insert(int *table,int key)
{
  if(table[key]==-1)
    {
     table[key]=key;
     cout<<"Inserted\n";
    }
 else cout<<"Already Present\n";
}

void search(int *table,int key)
{
 if(table[key]!=-1)
   cout<<"Found:"<<table[key]<<"\n";
 else cout<<"Not Found\n";
}

void del(int *table,int key)
{
  if(table[key]!=-1)
    table[key]=-1;
 cout<<"Deleted!!\n";
}

void print(int *table,int n)
{
 for(int i=0;i<=n;i++)
  if(table[i]!=-1)
    cout<<table[i]<<" ";
 cout<<"\n";
}

int main()
{
  int n,key,c;
  cout<<"Enter the largest element to be inserted:";
  cin>>n;
  int *table = new int[n+1];
  for(int i=0;i<=n;i++)
    table[i]=-1;
  while(1)
{  
  cout<<"1:Insert\n2:Search\n3:Delete\n4:Print\n5:Extt\nEnter Choice:";
  cin>>c;
  switch(c)
 {
  case 1:cout<<"Enter the element to be inserted:";
         cin>>key;
         insert(table,key);
         break;
  case 2:cout<<"Enter the element to be searched:";
        cin>>key;
        search(table,key);
        break;
  case 3:cout<<"Enter the element to be deleted:";
        cin>>key;
        del(table,key);
        break;
  case 4:print(table,n);
        break;
  case 5:return 0;
  default:cout<<"Enter a valid choice\n";
       break;
 }
}
 delete[] table;
return 0; 
}
