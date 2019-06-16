#include <stdio.h> 
#include <conio.h> 
#include <ctype.h> 
#include <string.h> 
#include<stdlib.h>
#define MAX 100
char st[MAX];
int top=-1;
void push(char[],char );
char pop(char[]);
void InfixtoPostfix(char[]);
void display(char[]);
int getPriority(char);
int main()
{
	char infix[100];
	printf("\nEnter an infix expression:");
	gets(infix);
	InfixtoPostfix(infix);
	getch();
	return 0;
}

void InfixtoPostfix(char source[])
{
	char postfix[100];
	strcpy(postfix,"");
	int i=0,j=0;
	char temp;
	while(source[i]!='\0')	
	{
		printf("\n%c",source[i]);
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			while((top!=-1)&&(st[top]!='('))
			{
				postfix[j]=pop(st);
				j++;
			}
			if(top==-1)   
			{    
				printf("\n INCORRECT EXPRESSION");    
				exit(1);   
			}   
			temp = pop(st);//remove left parenthesis   
			printf("%c",temp);
			i++; 
		}
		else if(isdigit(source[i]) || isalpha(source[i]))  
		{   
			postfix[j] = source[i];   
			j++;   
			i++;  
		} 
		else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') 
		{
			while( (top!=-1) && (st[top]!= '(') && (getPriority(st[top]) > getPriority(source[i])))
			{
				postfix[j] = pop(st);    
				j++; 
			}
			 push(st, source[i]);   
			 i++; 
		}
		else
		{
			printf("\n INCORRECT ELEMENT IN EXPRESSION");   
			printf("\n Element is %s",source[i]);
			exit(1); 
		}
		printf("\t");
		display(st);
		printf("\t");
		display(postfix);
	}
	while((top!=-1) && (st[top]!='(')) 
	{  
		postfix[j] = pop(st);  
		j++; 
	} 
	postfix[j]='\0'; 
	printf("\n The corresponding postfix expression is : "); 
	puts(postfix); 
} 

int getPriority(char op) 
{ 
	if(op=='/' || op == '*' || op=='%')  
		return 1; 
	else if(op=='+' || op=='–')  
		return 0; 
}

void push(char st[], char val) 
{ 
	if(top==(MAX-1))  
		printf("\n STACK OVERFLOW"); 
	else 
	{  
		top++;  
		st[top]=val; 
	} 
}  

char pop(char st[]) 
{ 
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

void display(char aa[])
{
	int i;
	for(i=0;i<sizeof(aa);i++)
	{
		printf("%c",aa[i]);
	}
}
