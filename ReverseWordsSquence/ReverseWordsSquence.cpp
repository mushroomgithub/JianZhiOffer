#include<iostream>
using namespace std;
/***********************************************************
	Author:		mushroom
	�㷨˼�룺��ת���ӵ���˳����Ҫ���õķ����ǣ�����
	���������ӷ�ת��֮�����η�תÿ�����ʣ��ڷ�תÿ������
	ʱ��Ҫ��λÿ�����ʵĿ�ʼ�ͽ���Ϊֹ.
************************************************************/
void Reverse(char*pBegin,char* pEnd)
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
char* ReverseWordsSquence(char* str)
{
	if(NULL==str)
		return NULL;
	int len=strlen(str);
	char*pBegin,*pEnd;
	pBegin=str;
	pEnd=str+len-1;
	//���ȷ�ת��������
	Reverse(pBegin,pEnd);
	//���η�תÿ������
	pBegin=pEnd=str;
	while(*pBegin!='\0')
	{
		/*if(*pBegin==' ')
		{//�ƶ�������ÿ�����ʵĿ�ʼλ��
			pBegin++;
			pEnd++;
			continue;
		}
		else if(*pEnd==' '||*pEnd=='\0')
		{//��תÿ������
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else//�ƶ������ҵ��ʽ�β
			pEnd++;*/
		if(*pEnd==' '||*pEnd=='\0')
		{
			Reverse(pBegin,--pEnd);
			if(*pEnd=='\0')
				break;
			pEnd+=2;
			pBegin=pEnd;
		}
		else
			pEnd++;
	}
	return str;
}
int main(int argc,char** argv)
{
	char sentence[]="My name is mushroom.";
	char* reverseSentece=ReverseWordsSquence(sentence);
	cout<<"Output the sentence,After Reverse the Squence!"<<endl;
	cout<<reverseSentece<<endl;
	system("pause");
	return 0;
}