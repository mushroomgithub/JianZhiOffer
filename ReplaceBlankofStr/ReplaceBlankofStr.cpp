#include<iostream>
using namespace std;

/****************************************************************************************
/*	                       Author: mushroom
/*                         note:	    为了保证时间复杂度为O(n)，我们必须保证替换空格时每个
/*	字符只能移动一次，倘若我们从前向后替换空格，则会出现某些字符连续被移动多次
/*	这样的话，时间复杂度就不是O(n)，而是O(n^2)了，因此我采取从后向前替换空格的方式
/*	，首先先遍历一次字符串，记录字符的原始长度和包含空格数目，则替换之后的字符长度为
/*	原始字符串长度加上空格数目的二倍。我们设置两个指针numOrigin和numNew分别指示
/*	原始字符串的末尾和替换之后的字符串的末尾。从后向前开始替换，如果numOrigin指向的
/*	字符为空格，将空格视为%20,numOrigin向前移动号一个位置；然后将numNew向前移动
/*	三个位置，将%20依次拷贝进去，如果不是空格，则将numOrigin指向的字符拷贝到numNew
/*	指向的位置，之后，两者同时向前移动一个位置。这样当numOrigin=numNew时，
/*	说明原始字符串中的空格已经全部替换完了，之后，只需将numOrigin指向的字符依次拷贝
/*	到nunNew指向的位置即可完成最终的替换工作，整个过程每个字符只移动了一次，
/*	时间复杂度控制在了O(n)。
**********************************************************************************************/
char* ReplaceBlankofStr(char str[],int len)
{
	int numOrigin=0;
	int numofBlank=0;
	char *strTemp=str;
	while(*str!='\0')
	{
		numOrigin++;
		if(*str==' ')
			numofBlank++;
		str++;
	}
	int numNew=numOrigin+2*numofBlank;
	if(numNew>len)
		return NULL;
	str=strTemp;
	while(numOrigin<numNew&&numOrigin>=0)
	{
		if(str[numOrigin]==' ')
		{
			str[numNew--]='0';
			str[numNew--]='2';
			str[numNew--]='%';
		}
		else
		{
			str[numNew--]=str[numOrigin];
		}
		numOrigin--;
	}
	//memcpy(strTemp,str,numNew);
	strncpy(strTemp,str,numNew);
	return strTemp;
}

int main(int argc,char** argv)
{
	char str[20]="we are happy.";
	char *strOut=ReplaceBlankofStr(str,20);
	for(int i=0;i<strlen(strOut);i++)
		cout<<strOut[i];
		cout<<endl;
	return 1;
}