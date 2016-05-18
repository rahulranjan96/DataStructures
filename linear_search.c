#include<stdio.h>
#include<stdlib.h>


void linear_search(int *a,int n,int key)
{
   int i=0,flag=0;
   for(i=0;i<n;i++)
   	 {
   	 	if(a[i] == key)
   	 		{
   	 			printf("Found:%dth\n",i+1);
   	 			flag=1;
   	 		}
     }
   if(flag==0)
   	printf("Sorry not found");
}

int main()
{
   int i,n,key;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc(n*sizeof(int));
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
   printf("Enter the key to be searched:");
   scanf("%d",&key);
 linear_search(a,n,key);
  return 0;
}
