#include<iostream>
using namespace std;
/*********************************************************
	Author:		mushroom
	算法思想：将字符串循环左移n位的方法，一般采用经典
	三翻转方式，首先将字符串前n为翻转，之后翻转后面的字符
	串，最后再翻转整个字符串，最终的结果就是循环左移n
	位之后的字符串了。
***********************************************************/
void Reverse(char*pBegin,char*pEnd)
{
	if(pBegin==NULL||pEnd==NULL)
		return;

	while(pBegin<pEnd)
	{
		char temp=*pBegin;
		*pBegin=*pEnd;
		*pEnd=temp;
		pBegin++;
		pEnd--;
	}
}
char* leftRotateString(char* str,int n)
{
	if(str==NULL||n<0)
		return NULL;

	int len=strlen(str);
	if(n>len)
		return NULL;
	if(n==0||n==len)
		return str;

	char*pBegin,*pEnd;
	pBegin=str;
	pEnd=str+n-1;
	Reverse(pBegin,pEnd);

	pBegin=str+n;
	pEnd=str+len-1;
	Reverse(pBegin,pEnd);

	pBegin=str;
	pEnd=str+len-1;
	Reverse(pBegin,pEnd);

	return str;
}

int main(int argc,char* argv)
{
	char str[]="abcdefg";
	int n;
	cout<<"Pls Input LeftRotate bits:"<<endl;
	cin>>n;
	cout<<"LeftRotate "<<n<<" bits"<<endl;
	char*pStr=leftRotateString(str,n);
	cout<<"Output string after LeftRotate "<<n<<" bits"<<endl;
	if(pStr)
		cout<<pStr<<endl;
	else 
		cout<<"Left Rotate Failed"<<endl;
	return 0;
}