#include<stdio.h>
#include<stdlib.h>


void counting_sort(int *a,int n,int k,int d)
{
  int i=0;
  int *b=(int*)malloc(n*sizeof(int));
  int *c=(int*)malloc(10*sizeof(int));
  for(i=0;i<=k;i++)
   c[i]=0;
  for(i=0;i<n;i++)
    c[(a[i]/d)%10]++;
  for(i=1;i<=k;i++)
   c[i]+=c[i-1];
  for(i=0;i<n;i++)
   { 
    b[c[(a[i]/d)%10] - 1] = a[i];
    c[(a[i]/d)%10]--;    
   }
 for(i=0;i<n;i++)
   a[i]=b[i];
}

void radix_sort(int *a,int n,int k)
{
 int d=0,i=0;
 int max=a[0];
  for(i=1;i<n;i++)
    if(a[i]>max)
      max=a[i];
    for(d=1;max/d>0;d=d*10)
      counting_sort(a,n,d);
}

int main()
{
   int i,n,k;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   int *a=(int*)malloc(n*sizeof(int));             //Dynamically declaring the array.
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
     printf("Enter %dth element:",i+1);
     scanf("%d",&a[i]);
   }
 radix_sort(a,n,k);                             //Calling the Bubble Sort Function.
  printf("Sorted array is:\n");
 for(i=0;i<n;i++)
{
  printf("%d\n",a[i]);
}
  return 0;
}
