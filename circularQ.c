#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void insert()
{
	int val;
	printf("Enter the number to be inserted: ");
	scanf("%d",&val);
	if((front==0 && rear==MAX-1)||(rear==front-1))
	{
		printf("\nQueue Overflow");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}

int deleteval()
{
	int val;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue Underflow");
		return -1;
	}
	val=queue[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front=MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
	return val;
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("\t%d",queue[i]);
			}
		}
		else
		{
			for(i=front;i<MAX;i++)
			{
				printf("\t%d",queue[i]);	
			}
			for(i=0;i<=rear;i++)
			{
				printf("\t%d",queue[i]);	
			}
		}
	}
}

int main()
{
	int option,val;
//	clrscr();
	do
	{
		printf("\n1.Insert an element");
		printf("\n2.Delete an element");
		printf("\n3.Display the Queue");
		printf("\n4.Exit");
		printf("\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				insert();
				break;
			case 2: 
				val=deleteval();
				if(val!=-1)
					printf("\nThe value deleted is %d",val);
				break;
			case 3:
				display();
				break;
		}
	}while(option!=4);
	getch();
}
