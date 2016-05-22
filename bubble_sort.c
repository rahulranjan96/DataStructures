#include<stdlib.h>
#include<stdio.h>

void swap(int *a,int *b)      //Declaring and Defining swap function
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubble_sort(int *a,int n)    //Declaring and Defining Bubble Sort Function. 
{
   int i,j,flag=0;               //Declring flag variable to check whether the given array is already sorted or not.
   for(i=0;i<n;i++)             
   {   
        flag=0;
      for(j=0;j<n-1;j++)        //Moving the largest element to the end of the list.
     {
       if(a[j]>a[j+1])
         {
           swap(&a[j],&a[j+1]);
           flag=1;
         }  
     
     }
       if(flag==0)            //Checking after each iteration that whether the given array has been sorted or not and 
         break;               // thus avoiding the subsequent iterations over the loop and hence optimizing.
   }
}

int main()
{
   int i,n;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc(n*sizeof(int));             //Dynamically declaring the array.
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
 bubble_sort(a,n);                             //Calling the Bubble Sort Function.
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
