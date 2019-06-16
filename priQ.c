#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	int priority;
	struct node *next;
};

struct node *start=NULL;

void insert()
{
	int val,pri;
	struct node *temp,*p;
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to be inserted:");
	scanf("%d",&val);
	printf("\nEnter the priority:");
	scanf("%d",&pri);
	
	temp->data=val;
	temp->priority=pri;
	
	
	if(start==NULL||pri< start->priority)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		p=start;
		while(p->next!=NULL && p->next->priority<=pri)
			p=p->next;
		temp->next=p->next;
		p->next=temp;
	}
}

void deleteval()
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nUnderflow");
	}
	else
	{
		p=start;
		printf("\nThe deleted item is %d",p->data);
		start=start->next;
		free(p);
	}
}

void display()
{
	struct node *p;
	p=start;
	if(start==NULL)
	{
		printf("\nQueue is Empty");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d[p: %d]",p->data,p->priority);
			p=p->next;
		}
	}
	
}

int main()
{
	int option,val;
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
				printf("insertion completed");
				break;
			case 2: 
				deleteval();
				break;
			case 3:
				display();
				break;
		}
	}while(option!=4);
	getch();
}
