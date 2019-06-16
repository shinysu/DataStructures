#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start;
void create();
void display();
void insertfirst();
void insertmid();
void insertlast();
void deletevalue();
void find();
void revdisplay();
int main()
{
	int choice,value,y;
	char ch;
	start=NULL;
	printf("** Linked List Implementation **");
	do
	{
		printf("\n 1. Create \t2.display\t3.Insertfirst\t4.Insertmid\t5.InsertLast\t6.Delete\t7.search\t8.Display the list in reverse\t");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:display();
				break;

			case 3:
				insertfirst();
				break;
			case 4:
				insertmid();
				break;
			case 5:
				insertlast();
				break;
			case 6:
				deletevalue();
				break;
			case 7:
				find();
				break;
			case 8:
				revdisplay();
				break;
			default:
			printf("invalid choice");
		}
		printf("\n do you want to continue?");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}

void create()
{
	  struct node *temp;
	  int value;
	  temp=(struct node *)malloc(sizeof(struct node));		//allocate space for new node
	  printf("\n enter value:");
	  scanf("%d",&value);
	  if(start==NULL)      			//Check if the list is empty
	  {
	  	  temp->prev=NULL;
		  temp->data=value;
		  temp->next=NULL;
		  start=temp;
	  } 
	   printf("list created");
}

void display()
{
	struct node *p;
	p=start;

	if(p==NULL)						//check for empty list
	{
		printf("\n empty list");
		return;
	}
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
}

void revdisplay()					//display the list in reverse order
{
	struct node *p;
	p=start;

	if(p==NULL)						//check if list is empty
	{
		printf("\n empty list");
		getch();
		return;
	}
	while(p->next!=NULL)			//traverse to the last element
	{
		p=p->next;
	}
	while(p!=NULL)					//print the elements one by one from the last element
	{
		printf("%d->",p->data);
		p=p->prev;
	}
}


void insertfirst()
{
	int value;
	struct node *temp;
	  temp=(struct node *)malloc(sizeof(struct node));   		//allocate space for new node
	  printf("\n enter value:");
	  scanf("%d",&value);
	  
	  	  temp->prev=NULL;
		  temp->data=value;
		  temp->next=NULL;
		  
		  start->prev=temp;
		  temp->next=start;
		  start=temp;
	  
}

void insertmid()
{
   struct node *temp,*p,*t1;
	int value,pos,i;
	  temp=(struct node *)malloc(sizeof(struct node));
	  printf("\n enter the value to be inserted:");
	  scanf("%d",&value);
	  printf("\n enter the position:");
	  scanf("%d",&pos);
	  
	  temp->prev=NULL;
	  temp->data=value;
	  temp->next=NULL;
	  
	    p=start;
		for(i=0;i<pos-1;i++)
			p=p->next;

		  t1=p->next;
		  temp->next=t1;
		  t1->prev=temp;
		  p->next=temp;
		  temp->prev=p;
	  
}

void insertlast()
{
	struct node *temp,*p;
	int value;
	  temp=(struct node *)malloc(sizeof(struct node));			//allocate space for new node
	  printf("\n enter the value to be inserted:");
	  scanf("%d",&value);
	  
	  	  temp->prev=NULL;
		  temp->data=value;
		  temp->next=NULL;
		  
		  p=start;
		  while(p->next!=NULL)
		  {
			p=p->next;
		  }
		  p->next=temp;
		  temp->prev=p;
	  
}
void find()
{
	struct node *p;
	int j=0,value;
	printf("\n enter value to be found:");
	  scanf("%d",&value);
	  
	  p=start;
	  while(p!=NULL&&p->data!=value)
	  {
		p=p->next;
		j++;
	  }
	  if(p==NULL)
		printf("The element is not in the list");
	  else
		printf("The element %d is in position %d",value,j+1);
}
void deletevalue()
{
	struct node *p,*temp,*t1;
	int value;
	printf("\n enter value to be deleted:");
	  scanf("%d",&value);
	  
	p=start;
	if(p->data==value)							//check if the value to be deleted is the first element
	{
		
		start=p->next;
		start->prev=NULL;
		free(p);
	}
	else
	{
		while(p->next!=NULL&&p->next->data!=value)
			p=p->next;
		if(p->next!=NULL)
		{
			
		temp=p->next;
		t1=temp->next;
		p->next=t1;
		if(t1!=NULL)
			t1->prev=p;
		free(temp);
		}
	}
	
	printf("\n The element has been deleted");
}
				

