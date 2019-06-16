//Binary search
#include<stdio.h>
main()
{
	int list[10],key,found,num,i;
	int low,high,mid;
	printf("\n enter the max no.of elements\n");
	scanf("%d",&num);
	printf("\n enter the elements one by one in sorted order\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&list[i]);
	}
	printf("enter the value to be searched");
	scanf("%d",&key);
	low=0;
	high=num-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==list[mid])
		{
			printf("search is successful");
			printf("\n the elemnts %d is in position %d\n",list[mid], mid);
			found=1;
			break;
		}
		else if(key<list[mid])
		{
			high=mid-1;
		}
		else if(key>list[mid])
		{
			low=mid+1;
		}
	}
	if(found!=1)
		printf("seach is unsuccessful");
	getch();
}
