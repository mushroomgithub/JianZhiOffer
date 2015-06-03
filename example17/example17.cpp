#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char** argv)
{
	int x;
	srand(time(NULL));
	x=rand()%100;
	int m,count=0;
	printf("pls input your guess:\n");
	while(scanf("%d",&m)!=EOF)
	{
		if(m>x)
			printf("too biger:\n");
		else if(m<x)
			printf("too small:\n");
		else
		{
			printf("oh! yes,you get it.");
			break;
		}
		count++;
	}
	switch(count)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("the level of you is: A\n");
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		printf("the level of you is: B\n");
		break;
	default:
		printf("the level of you is: C\n");
		break;
	}
	return 0;
}