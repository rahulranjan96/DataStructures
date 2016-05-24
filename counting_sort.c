#include<stdio.h>
#include<stdlib.h>


void counting_sort(int *a,int n,int k)
{
  int i=0;
  int *b=(int*)malloc(n*sizeof(int));
  int *c=(int*)malloc((k+1)*sizeof(int));
  for(i=0;i<=k;i++)
   c[i]=0;
  for(i=0;i<n;i++)
   c[a[i]]++;
  for(i=1;i<=k;i++)
   c[i]+=c[i-1];
  for(i=n-1;i>=0;i--)
   {
    b[c[a[i]]-1]=a[i];
      c[a[i]]--;
   }
 for(i=0;i<n;i++)
   a[i]=b[i];
}

int main()
{
   int i,n,k;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   printf("Enter the largest element in the array:");
   scanf("%d",&k);
   int *a=(int*)malloc(n*sizeof(int));             //Dynamically declaring the array.
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
 counting_sort(a,n,k);                             //Calling the Bubble Sort Function.
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
