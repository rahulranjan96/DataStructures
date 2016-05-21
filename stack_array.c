#include<stdio.h>
#include<stdlib.h>

int length = 2;
int x,head=-1;
int *a;

void push()
{
     if(head<length-1)
   {
       head++;
      a[head]=x;
   }
  else if(head==length-1)
 {
    int *b = (int*)malloc(2*length*sizeof(int));
    int i;
    for(i=0;i<length;i++)
      b[i]=a[i];
    a=b;
    head++;
    a[head]=x;
    length=2*length;
 }
}

void pop()
{
 if(head>=0)
 {
   printf("%d\n",a[head]);
   head--;
 }
 else
   printf("Under Flow Error\n");
}

void print()
{
int i=0;
for(i=0;i<=head;i++)
printf("%d ",a[i]);
}


int main()
{
        a=(int*)malloc(length*sizeof(int));
	int c;
       while(1)
{
   printf("1:Push\n2:Pop\n3:Print\n4:Exit\nEnter Choice:");
        scanf("%d",&c);

	switch(c)
	{
		case 1:printf("Enter the element to be pushed:");
		       scanf("%d",&x);
		       push();
		       break;
		case 2:pop();
                       printf("\n");
		       break;
		case 3:print();
                       printf("\n");
		       break;
		case 4:return 0;

		default:printf("Enter a valid choice\n");
			
	}

}
}

