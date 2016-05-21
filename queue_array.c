#include<stdio.h>
#include<stdlib.h>

int x,head=0,tail=-1,length=10;
int *a;

void enqueue()
{
	if(tail<length)
	{
		tail++;
		a[tail]=x;
	}
	else if(tail==length)
	{
		int *b=(int*)malloc(2*length*sizeof(int));
		length=2*length;
		int i=0;
		for(i=0;i<=tail;i++)
			b[i]=a[i];
		a=b;
		a[++tail]=x;
	}
}

void dequeue()
{
	if(head<=tail)
		printf("%d\n",a[head++]);
	else printf("Sorry Empty List");
}

void print()
{
	int i=0;
	for(i=head;i<=tail;i++)
		printf("%d ",a[i]);
}

int main()
{

	int c;
	a=(int*)malloc(length*sizeof(int));
	while(1)
	{
		printf("1:Enqueue\n2:Dequeue\n3:Print\n4:Exit\nEnter Choice:");
		scanf("%d",&c);
		switch(c)
		{

			case 1:printf("Enter the element to enqueued:");
			       scanf("%d",&x);
			       enqueue();
			       break;

			case 2:dequeue();
			       break;

			case 3:print();
			       printf("\n");

			       break;
			case 4:return 0;
			       break;

			default:printf("Enter a valid choice\n");

		}
	}
}
