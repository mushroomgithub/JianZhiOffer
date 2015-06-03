#include<iostream>
using namespace std;

/****************************************************************************************
/*	                       Author: mushroom
/*                         note:	    Ϊ�˱�֤ʱ�临�Ӷ�ΪO(n)�����Ǳ��뱣֤�滻�ո�ʱÿ��
/*	�ַ�ֻ���ƶ�һ�Σ��������Ǵ�ǰ����滻�ո�������ĳЩ�ַ��������ƶ����
/*	�����Ļ���ʱ�临�ӶȾͲ���O(n)������O(n^2)�ˣ�����Ҳ�ȡ�Ӻ���ǰ�滻�ո�ķ�ʽ
/*	�������ȱ���һ���ַ�������¼�ַ���ԭʼ���ȺͰ����ո���Ŀ�����滻֮����ַ�����Ϊ
/*	ԭʼ�ַ������ȼ��Ͽո���Ŀ�Ķ�����������������ָ��numOrigin��numNew�ֱ�ָʾ
/*	ԭʼ�ַ�����ĩβ���滻֮����ַ�����ĩβ���Ӻ���ǰ��ʼ�滻�����numOriginָ���
/*	�ַ�Ϊ�ո񣬽��ո���Ϊ%20,numOrigin��ǰ�ƶ���һ��λ�ã�Ȼ��numNew��ǰ�ƶ�
/*	����λ�ã���%20���ο�����ȥ��������ǿո���numOriginָ����ַ�������numNew
/*	ָ���λ�ã�֮������ͬʱ��ǰ�ƶ�һ��λ�á�������numOrigin=numNewʱ��
/*	˵��ԭʼ�ַ����еĿո��Ѿ�ȫ���滻���ˣ�֮��ֻ�轫numOriginָ����ַ����ο���
/*	��nunNewָ���λ�ü���������յ��滻��������������ÿ���ַ�ֻ�ƶ���һ�Σ�
/*	ʱ�临�Ӷȿ�������O(n)��
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