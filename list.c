#include<stdio.h>
#include<conio.h>
#define MAXLEN 100
int list[MAXLEN], listsize;

void create()
{
	int i;
	printf("Enter the number of elements in the list\n");
	scanf("%d",&listsize);
	printf("\nEnter the elements\n");
	for(i=0;i<listsize;i++)
	{
		scanf("%d", &list[i]);
	}
}

void printlist()
{
	int i;
	printf("The elements in the list:\n");
	for(i=0;i<listsize;i++)
		printf("%d\n",list[i]);
	
}

void insert()
{
	int val,pos,i;
	printf("\nEnter the value to be inserted in the list\n");
	scanf("%d",&val);
	printf("\nEnter the position in which the value is to be inserted\n");
	scanf("%d",&pos);
	
	if(pos<0||pos>listsize)
	{
		printf("\nInvalid index");
	}
	if(listsize==MAXLEN)
	{
		printf("\nList already full\n");
	}
	printf("hello");
	for(i=listsize;i>pos;i--)
	{
		printf("here %d",&i);
		list[i]=list[i-1];
	}
	list[pos]=val;
	listsize++;
}

void delete()
{
	int i,pos;
	printf("\nEnter the position from which the value is to be deleted\n");
	scanf("%d",&pos);
	
	if(pos<0||pos>=listsize)
	{
		printf("\npos: %d",pos);
		printf("\nlistsize: %d",listsize);
		printf("\nInvalid index");
	}
	
	for(i=pos;i<=listsize-2;i++)
	{
	//	printf("\n then %d",list[i]);
		list[i]=list[i+1];
	//	printf("\n now %d\n",list[i]);
	}
	listsize--;
}

void search()
{
	int i,e;
	printf("\nEnter the element to be found");
	scanf("%d",&e);
	
	for(i=0;i<listsize;i++)
	{
		if(list[i]==e)
		{
			printf("Element found at position %d\n",i);
			break;
		}
	}
}

void main()
{
//	clrscr();
	int ch;
	char g='y';
//	printf("hello");
	do{
		printf("\n Main menu");
		printf("\n1.Create \n 2.Delete\n 3.Find\n 4.Insert\n 5.Print list\n 6.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch)	;
		
		switch(ch)
		{
			case 1:
				create();
				break;
			
			case 2:
				delete();
				break;
			
			case 3:
				search();
				break;
			
			case 4:
				insert();
				break;
			
			case 5:
				printlist();
				break;
			
			case 6:
				break;
				
			default:
				printf("\nEnter the correct choice");
		}
		printf("\ndo you want to continue?");
		scanf("\n%c",&g);
	}
	while (g=='y'||g=='Y');
	getch();
}

