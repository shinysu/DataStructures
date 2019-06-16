#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#define MAX 3

int st[MAX], top=-1; 
void push(int); 
int pop(); 
int peek(); 
void display();

void main()
{
	int val, option;
	do
	{
		printf("\n *****MAIN MENU*****");  
		printf("\n 1. PUSH");  
		printf("\n 2. POP");  
		printf("\n 3. PEEK");  
		printf("\n 4. DISPLAY");  
		printf("\n 5. EXIT");  
		printf("\n Enter your option: ");  
		scanf("%d", &option);
		switch(option)  
		{  
			case 1:
				printf("Enter the value to be pushed into the stack");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				val=pop();
				printf("The value deleted from the stack is %d",val);
				break;
			case 3:
				val=peek();
				printf("The value stored at the top of the stack is %d",val);
				break;
			case 4:
				display();
				break;
			case 5:
				
				break;
		}
	}while(option!=5);
}

void push(int val)
{
	if(top==MAX-1)
	{
		printf("\nStack Overflow");
	}
	else
	{
		top++;
		st[top]=val;
	}
}

int pop()
{
	int val;
	if(top==-1)
	{
		printf("Stack Underflow");
		return -1;
	}
	else
	{
		val=st[top];
		top--;
		return val;
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d",st[i]);
		}
	}
}

int peek()
{
	if(top==-1)
	{
		printf("Stack is empty");
		return -1;
	}
	else
	{
		return (st[top]);
	}
}
