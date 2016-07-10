#include<stdlib.h>
#include<stdio.h>

//For array starting with index 0 to n-1
//Pass n-1 in heapsort function in main function
//Do all the replacement in for loops
//left child=2*i+1
//right child=2*i+2
//parent=(i-1)/2
void swap(int *a,int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void max_heapify(int *a,int n,int i)
{
  int l = 2*i;
  int r = 2*i + 1;
  int largest = 0;
  if(l<=n && a[l] > a[i])
    largest = l;
  else largest = i;
  if(r<=n && a[r] > a[largest])
    largest = r;
  if(largest != i)
  {
    swap(&a[largest],&a[i]);
    max_heapify(a,n,largest);
  }
}

void build_max_heap(int *a,int n)
{
  int i=0;
  for(i=n/2;i>=1;i--)
    max_heapify(a,n,i);
}
void heap_sort(int *a,int n)
{
  build_max_heap(a,n);
  int i = 0;
  for(i=n;i>=2;i--)
  {
    swap(&a[i],&a[1]);
    n--;
    max_heapify(a,n,1);
  }
}

int main()
{
   int i,n;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc((n+1)*sizeof(int));
   printf("Enter the elements of the array\n");
   for(i=1;i<=n;i++)
   {
     printf("Enter %dth element:",i);
     scanf("%d",&a[i]);
   }
 heap_sort(a,n);
  printf("Sorted array is:\n");
 for(i=1;i<=n;i++)
{
  printf("%d\n",a[i]);
}
  free(a);
  
  return 0;
}
