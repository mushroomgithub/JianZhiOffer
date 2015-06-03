#include<stdio.h>
int main()
{
	int num=0;
	scanf("%d",&num);
	long long int a,b;
	int i=1;
	while (i<=num&&scanf("%d%d",&a,&b)!=EOF)
	{
		printf("Case %d:\n",i);
		printf("%d ",a); printf("+ ");printf("%d = ",b);
		printf("%d\n",a+b);
		printf("\n");
		i++;		
	}
	return 0;
}