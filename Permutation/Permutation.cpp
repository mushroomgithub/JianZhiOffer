#include<iostream>
#include<iomanip>
using namespace std;
#define N 4	//��ʼ���ַ������С
//��[nBegin,nEnd)�������Ƿ����ַ����±�ΪpEnd���ַ���ȣ�������ַ�ʱ����false�����򷵻�true
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
			if(IsSwap(pBegin,pCh))//��[nBegin,pCh)������û�����ַ����±�ΪpCh���ַ����ʱ����
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
	cout<<"�����ַ���"<<str<<"��������������ǣ�"<<endl;
	Permutation(str,str);
	cout<<endl;
	system("pause");
	return 0;
}