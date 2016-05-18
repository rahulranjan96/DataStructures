#include<stdlib.h>
#include<stdio.h>

void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
int partition(int *a,int l,int r)
{
  int i,j;
  int x=a[r];
  i=l-1;
  for(j=l;j<=r-1;j++)
  {
    if(a[j]<=x)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  return i+1;
}

void quick_sort(int *a,int l,int r)
{
  if(l<r)
  {
    int p = partition(a,l,r);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
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
 quick_sort(a,0,n-1);
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
