#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void merge(int *a,int low,int mid,int high)
{
   int n1 = mid-low+1;
   int n2 = high-low;
   int i,j,k;
   int *left = (int*)malloc((n1+1)*sizeof(int));
   int *right = (int*)malloc((n2+1)*sizeof(int));
   for(i=0;i<n1;i++)
    left[i] = a[low+i];
   for(i=0;i<n2;i++)
    right[i] = a[mid+1+i];
  left[n1] = INT_MAX;
  right[n2] = INT_MAX;
  i=0;
  j=0;
   for(k=low;k<=high;k++)
   {
    if(left[i]<=right[j])
      {
      a[k] = left[i];
      i++;
      }
    else
    {
      a[k] = right[j];
      j++;
    }
   }

}

void merge_sort(int *a,int low,int high)
{
   if(low<high)
   {
    int mid = (low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
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
 merge_sort(a,0,n-1);
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
