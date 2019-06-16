#include <stdio.h> 
#include <conio.h> 
#include <ctype.h> 
#include <string.h> 
#include<stdlib.h>
#define MAX 100
int st[MAX];
int top=-1;
void push(int[] ,int);
int pop(int[]);
void EvalPostfixExp(char[]);
void display(int[]);
int main()
{
	int infix[100];
	char exp[100];
	printf("\nEnter the postfix expression:");
	gets(exp);
	EvalPostfixExp(exp);
	getch();
	return 0;
}

void EvalPostfixExp(char exp[])
{
	int i=0; 
	int op1, op2, value; 
	while(exp[i] != '\0') 
	{  
		printf("\n%c\t",exp[i]);
		if(isdigit(exp[i]))
			push(st,exp[i]);
		else
		{
			printf("%d",top);
			
			op2 = pop(st);  
			printf("%d",top); 
			op1 = pop(st);   
			switch(exp[i])   
			{    
				case '+':     
					value = op1 + op2;     
					break;    
				case '–':     
					value = op1 - op2;     
					break;    
				case '/':     
					value = op1 / op2;     
					break;    
				case '*':     
					value = op1 * op2;     
					break;    
				case '%':     
					value = op1 % op2;     
					break;   
			}   
			push(st,value);		
		}
//		display(st);
		i++;
	}
	value=pop(st);
	printf("\nOutput: %d",value);
}

void push(int st[], int val) 
{ 
	printf("push");
	if(top==(MAX-1))  
		printf("\n STACK OVERFLOW"); 
	else 
	{  
		top++;  
		st[top]=val; 
	} 
}  

int pop(int st[]) 
{ 
	printf("pop");
	char val=' '; 
	if(top==-1)  
		printf("\n STACK UNDERFLOW"); 
	else 
	{  
		
		val=st[top];  
		top--; 
	} 
	return val; 
} 

void display(int aa[])
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d",aa[i]);
	}
}
