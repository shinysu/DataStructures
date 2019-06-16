//Linear Search
#include<stdio.h>
int main()
{
	int list[10],key,found,num,i;
//	clrscr();
	printf("Enter no. of elements : ");
	scanf("%d",&num);
	printf("Enter %d elements\n",num);
	for(i=0;i<num;i++)
		scanf("%d",&list[i]);
	printf("\n enter the value to be searched \n");
	scanf("%d",&key);
	for(i=0;i<num;i++)
	{
		if(key==list[i])
		{
			printf("\n %d element is found at location%d",list[i],i+1);
			found=1;
		}
	}
	if(found!=1)
	{
		printf("search is unsucessful");
	}
	getch();
}

