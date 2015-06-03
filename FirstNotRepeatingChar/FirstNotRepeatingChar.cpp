#include<iostream>
using namespace std;
char FindFirstNotRepeatingChar(char* s)
{
	if(NULL==s)
		return '\0';
	int len=strlen(s);
	int hash[256]={0};
	for(int i=0;i<len;i++)
		hash[s[i]]++;
	for(int i=0;i<len;i++)
	{
		if(hash[s[i]]==1)
			return s[i];
	}
	return '\0';
}

int main(int argc,char**argv)
{
	//char *s="abaccbdedff";
	char*s="abcdef";
	char firstAppearOnceChar=FindFirstNotRepeatingChar(s);
	if(firstAppearOnceChar!='\0')
		cout<<"第一个只出现一次的字符是："<<firstAppearOnceChar<<endl;
	else
		cout<<"字符串中所有字符均出现不止一次！"<<endl;
	return 0;
}