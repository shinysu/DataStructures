#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int left=-1,right=-1;

void insert_right()
{
	int val;
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	if(left==0 && right==MAX-1)||(right==left-1)
	{
		printf("\nOverflow");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==MAX-1&& left!=0)
			right=0;
		else
			right=right+1;
	}
	queue[right]=val;
}

void insert_left()
{
	int val;
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	if(left==0 && right==MAX-1)||(right==left-1)
	{
		printf("\nOverflow");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
		{
			left=MAX-1;
		}
		else
		{
			left=left+1;
		}
	}
	queue[left]=val;
}

void delete_left()
{
	if(left==-1)
	{
		printf("\n Underflow");
		return;
	}
	printf("\n the deleted element is: %d", queue[left]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(left==MAX-1)
			left=0;
		else
			left=left+1;
	}
}

void delete_right()
{
	if(left==-1)
	{
		printf("\n Underflow");
		return;
	}
	printf("\n the deleted element is: %d", queue[right]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(right==0)
			right=MAX-1;
		else
			right=right-1;
		
	}
}

void display()
{
	int front=left,rear=right;
	if(front=-1)
	{
		printf("\nQueue is empty");
		return;
	}
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

void input_deque()
{
		int option;
		do
		{
			printf("\n INPUT RESTRICTED DEQUE");  
			printf("\n 1.Insert at right");  
			printf("\n 2.Delete from left");  
			printf("\n 3.Delete from right");  
			printf("\n 4.Display");  
			printf("\n 5.Quit");  
			printf("\n Enter your option : ");  
			scanf("%d",&option);  
			switch(option)  
			{   
				case 1:    
					insert_right();    
					break;   
				case 2:    
					delete_left();    
					break;   
				case 3:    
					delete_right();    
					break;   
				case 4:    
					display();    
					break;  
			} 
		}while(option!=5);
	}
}

void output_deque() 
{ 
	int option; 
	do {  
		printf("OUTPUT RESTRICTED DEQUE");  
		printf("\n 1.Insert at right");  
		printf("\n 2.Insert at left");  
		printf("\n 3.Delete from left");  
		printf("\n 4.Display");  
		printf("\n 5.Quit");  
		printf("\n Enter your option : ");  
		scanf("%d",&option);  
		switch(option)  
		{   
			case 1:    
				insert_right();    
				break;   
			case 2:    
				insert_left();	    
				break;   
			case 3:    
				delete_left();    
				break;   
			case 4:    
				display();    
				break;  
			} 
		}while(option!=5); 
	} 
}
