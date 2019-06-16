#include<stdio.h>
#include<conio.h>
#define MAX 20
int q[MAX],top=-1,front=-1,rear=-1,a[MAX][MAX],vis[MAX],stack[MAX];
int dequeue();
void enqueue(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void main()
{ 
	int n,i,s,ch,j;
	char c,dummy;
	printf("\n\t\t\tDFS and BFS implementation !");
	printf("\nEnter the Number of Nodes in Graph: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=n;j++)
		{ 
			printf("\nEnter 1 if %d has a NODE with %d else 0 ",i,j);
			scanf("%d",&a[i][j]);
		}		
	}
	printf("\n\n\t\tTheAdjecency Matrix is: ");
	for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=n;j++)
		{ 
			printf(" %d",a[i][j]);
		}
		printf("\n");
	} 
	do
	{ 
		for(i=1;i<=n;i++)
		vis[i]=0;
		printf("\n\nMENU");
		printf("\n1) B.F.S (Breadth First Search)");
		printf("\n2) D.F.S (Depth First Search)");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\nEnter source VERTEX:");
		scanf("%d",&s);
		switch(ch)
		{
			case 1:
				bfs(s,n);
				break;
			case 2:
				dfs(s,n);
				break;
		} 
		printf("\n\nWould you like to continue ?\n\n Yes(Y) or No (N): ");
		scanf("%c",&dummy);
		scanf("%c",&c);
	}while((c=='y')||(c=='Y'));
} 
void bfs(int s,int n)
{ 
	int p,i;
	enqueue(s);
	vis[s]=1;
	p=dequeue();
	if(p!=0)
		printf(" %d",p);
	while(p!=0)
	{ 
		for(i=1;i<=n;i++)
			if((a[p][i]!=0)&&(vis[i]==0))
			{ 
				enqueue(i);
				vis[i]=1;
			}
		p=dequeue();
		if(p!=0)
			printf(" %d ",p);
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			bfs(i,n);
}

void enqueue(int item)
{ 
	if(rear==MAX-1)
		printf("\n\nQUEUE is FULL!");
	else
	{ 
		if(rear==-1)
		{ 
			rear=0;
			front=0;
			q[rear]=item;
		}
		else
		{
			rear=rear+1;
			q[rear]=item;
		}
	}
}

int dequeue()
{ 
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else
	{ 
		k=q[front];
		front=front+1;
		return(k);
	}
}
void dfs(int s,int n)
{ 
	int i,k;
	push(s);
	vis[s]=1;
	k=pop();
	if(k!=0)
		printf(" %d ",k);
	while(k!=0)
	{ 
		for(i=1;i<=n;i++)
			if((a[k][i]!=0)&&(vis[i]==0))
			{ 
				push(i);
				vis[i]=1;
			}
		k=pop();
		if(k!=0)
			printf(" %d ",k);
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			dfs(i,n);
}

void push(int item)
{ 
	if(top==MAX-1)
		printf("\n\nStackoverflow.com");
	else
		stack[++top]=item;
}
int pop()
{ 
	int k;
	if(top==-1)
		return(0);
	else
	{ 
		k=stack[top--];
		return(k);
	}
}

