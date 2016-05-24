#include<stdio.h>
#include<stdlib.h>

int power(int a,int b)
{
 int i=0;
 if(b>=2)
 {
 for(i=2;i<=b;i++)
    a=a*a;
  return a;
 }
 else if(b==1)
    return a;
 else if(b==0)
    return 1;
}

void counting_sort(int *a,int n,int k,int d)
{
  int i=0;
  int *b=(int*)malloc(n*sizeof(int));
  int *c=(int*)malloc((k+1)*sizeof(int));
  for(i=0;i<=k;i++)
   c[i]=0;
  for(i=0;i<n;i++)
   c[(a[i]%power(10,d))/power(10,d-1)]++;
  for(i=1;i<=k;i++)
   c[i]+=c[i-1];
  for(i=0;i<n;i++)
   {
    b[c[(a[i]%power(10,d))/power(10,d-1)]-1]=a[i] ;
      c[(a[i]%power(10,d))/power(10,d-1)]-- ;
   }
 for(i=0;i<n;i++)
   a[i]=b[i];
}

void radix_sort(int *a,int n,int k)
{
 int d=0,i=0;
 int num = a[0];
 while(num>0)
{
 num = num/10;
 d++;
}
 for(i=1;i<=d;i++)
{
  counting_sort(a,n,k,d);
}
}

int main()
{
   int i,n,k;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   printf("Enter the largest digit in any number:");
   scanf("%d",&k);
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
