#include<stdio.h>

void out_nLX(int n)
{
	int i, j, k;
	for(i=0;i<=n/2;i++)
	{
		for(j=0; j<=n/2-i-1;j++)
			printf(" ");
		for(k=0; k<=2*i;k++)
			printf("*");
		printf("\n");
	}
	for(i=0; i<=2;i++)
	{	
		for(j=0; j<=i;j++)
			printf(" ");
		for(k=0; k<=n/2-2*i+1;k++)
			printf("*");
		printf("\n");
	}
}
int  main(int argc,char** argv)
{
	int n;
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("Pls Input an ji shu:\n");
		return -1;
	}
	out_nLX(n);
	return 0;
}