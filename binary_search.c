#include<stdio.h>
#include<stdlib.h>


void binary_search(int *a,int n,int key)   //Binary Search Function Declaration and Defination
{
  int low = 0;
  int high = n-1;
  int mid = 0; 
  int flag = 0;                         //flag to check whether element belongs to the list or not
  while(low<=high)
  {
    mid = (low+high)/2;                   
     if(a[mid] == key)
      {
        printf("Found:%dth",mid+1);
        flag = 1;                      //declaring flag to 1 confirms that the element has been found in the list
        break;                         //Breaking out of the loop since the element has been found 
      }
    else if(a[mid]>key)
      high = mid - 1;                   //Updating high to mid - 1 if a[mid]>key as key will lie on left side of mid
    else low = mid + 1;                 //Updating low to mid + 1 if a[mid]<key as key will lie on right side od mid

  }
  if(flag == 0)                       //Printint thet element has not been found since flag==0
    printf("Sorry not found\n");
}

int main()
{
   int i,n,key;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc(n*sizeof(int));           //Dynamically declaring the array of length n
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
   printf("Enter the key to be searched:");
   scanf("%d",&key);
 binary_search(a,n,key);                       //Calling Binary Search Function
  return 0;
}
