#include<stdio.h>
#include<stdlib.h>


void binary_search(int *a,int n,int key)
{
  int low = 0;
  int high = n-1;
  int mid = 0; 
  int flag = 0;
  while(low<=high)
  {
    mid = (low+high)/2;
     if(a[mid] == key)
      {
        printf("Found:%dth",mid+1);
        flag = 1;
        break;
      }
    else if(a[mid]>key)
      high = mid - 1;
    else low = mid + 1;

  }
  if(flag == 0)
    printf("Sorry not found\n");
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
 binary_search(a,n,key);
  return 0;
}
