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
		cout<<"��һ��ֻ����һ�ε��ַ��ǣ�"<<firstAppearOnceChar<<endl;
	else
		cout<<"�ַ����������ַ������ֲ�ֹһ�Σ�"<<endl;
	return 0;
}