#include<stdlib.h>
#include<stdio.h>

void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubble_sort(int *a,int n)
{
   int i,j,flag=0;
   for(i=0;i<n;i++)
   {   
        flag=0;
      for(j=0;j<n-1;j++)
     {
       if(a[j]>a[j+1])
         {
           swap(&a[j],&a[j+1]);
           flag=1;
         }  
     
     }
       if(flag==0)
         break;
   }
}

int main()
{
   int i,n;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc(n*sizeof(int));
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
 bubble_sort(a,n);
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
