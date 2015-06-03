#include <stdio.h>
#include<string.h>
char* myString()
{
	char buffer[6]={0};
	char*s="Hello World!";
	for(int i=0;i<sizeof(buffer)-1;i++)
		{
			buffer[i]=*(s+i);
	     }
	return buffer;

}
int main()
{
	char b[10]={'H','E','L','L','O','!','\0'};
	char b1[10];
	b1="HELLO!";
	char b2[10];
	strcpy(b2,"HELLO!");
	char b3[10]="HELLO!";
	printf("%s\n",b3);
	//printf("%s\n",myString());
	return 0;
}