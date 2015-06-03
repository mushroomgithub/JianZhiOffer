#include<stdio.h>

void charTraverse(char s[])
{
	while(*s!='\0')
	{
		char ch=*s;
		if(ch>='A'&&ch<='Z')
			*s+=32;
		s++;
	}
}

int main(int argc,char** argv)
{
	char s[]={0};
	printf("Pls Input  a string:\n");
	gets(s);
	charTraverse(s);
	puts(s);
	getchar();
	return 0;
}