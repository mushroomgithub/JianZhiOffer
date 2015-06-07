#include<iostream>
using namespace std;
/***********************************************************
	Author:		mushroom
	算法思想：翻转句子单词顺序，主要采用的方法是，首先
	将整个句子翻转，之后依次翻转每个单词，在翻转每个单词
	时需要定位每个单词的开始和结束为止.
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
	//首先翻转整个句子
	Reverse(pBegin,pEnd);
	//依次翻转每个单词
	pBegin=pEnd=str;
	while(*pBegin!='\0')
	{
		/*if(*pBegin==' ')
		{//移动并查找每个单词的开始位置
			pBegin++;
			pEnd++;
			continue;
		}
		else if(*pEnd==' '||*pEnd=='\0')
		{//翻转每个单词
			Reverse(pBegin,--pEnd);
			pBegin=++pEnd;
		}
		else//移动并查找单词结尾
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