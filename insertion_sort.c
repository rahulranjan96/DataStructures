#include<stdlib.h>
#include<stdio.h>

void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void insertion_sort(int *a,int n)
{
  int i,j,temp;
   for (i = 1; i < n; i++)
   {
       temp = a[i];
       j = i-1;
       while (j >= 0 && a[j] > temp)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = temp;
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
 insertion_sort(a,n);
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
