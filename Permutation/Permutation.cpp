#include<iostream>
#include<iomanip>
using namespace std;
#define N 4	//初始化字符数组大小
//在[nBegin,nEnd)区间中是否有字符与下标为pEnd的字符相等，有相等字符时返回false，否则返回true
bool IsSwap(char* pBegin , char* pEnd)
{  
	char *p;  
	for(p = pBegin ; p < pEnd ; p++)  
	{  
		if(*p == *pEnd)  
			return false;  
	}  
	return true;  
}  
void Permutation(char* pStr,char* pBegin)
{
	if(pStr==NULL)
		return;

	if(*pBegin=='\0')
	{
		cout<<pStr;
		cout<<setw(8);
	}
	else
	{
		for(char* pCh=pBegin;*pCh != '\0';++pCh)
		{
			if(IsSwap(pBegin,pCh))//当[nBegin,pCh)区间中没有有字符与下标为pCh的字符相等时交换
			{
				swap(*pCh,*pBegin);
				Permutation(pStr,pBegin+1);
				swap(*pCh,*pBegin);
			}
		}
	}
}


int main(int argc,char** argv)
{
	char str[N];
	cout<<"Pls Input the string what you want to test:"<<endl;
	gets(str);
	cout<<"输入字符串"<<str<<"的所有排列组合是："<<endl;
	Permutation(str,str);
	cout<<endl;
	system("pause");
	return 0;
}