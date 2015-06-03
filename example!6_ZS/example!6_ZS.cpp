#include <stdio.h>
#include <math.h>
void out_ZS(int n)
{
	int flag,count=0;
	for (int i=2;i<=n;i++) 
	{ 
		flag=0; 
		for (int k=2;k<=sqrt(i/1.0);k++) 
		{
			if (!(i %k) )
			{ 
				flag=1; 
				break; 
			} 
		}
		if (flag==0)
		{
			count++;
			printf("%4d",i); 
			if(count%5==0)
				printf("\n");
		}
	} 
}

int main(int argc,char** argv)
{
	int n;
	printf("Pls Input  a number:\n");
	scanf("%d",&n);
	out_ZS(n);
	getchar();
	return 0;
}