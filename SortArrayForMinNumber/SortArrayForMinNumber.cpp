#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
/***************************************************************************
/*	Author:		mushroom
/*	�㷨˼�룺�����������ųɵ���С�����ֵĹ����У����
/*	ֱ�Ӳ�����ֵ����������������ӳɵ���С����������int
/*	�����ܱ�ʾ�ķ�Χ����������һ���������⣬Ϊ�˽����
/*	���⣬���ǿ��Խ�����ת�����ַ��������ڰ�����m��nת����
/*	�ַ���֮������ƴ�������ĵõ�mn��nm������ʽ�����ǵ�
/*	λ��һ������ͬ�ģ�Ϊ�˱Ƚ����ǵĴ�С��ֻ��Ҫ�����ַ�����С
/*	�ıȽϹ���Ϳ����ˣ��������Ƚ����������ÿ��Ԫ��ת��Ϊ�ַ���,
/*	�������ڷ���õ��ַ��������У�֮�����ǲ���qsort�����ԣ����ַ�����
/*	���򣬶���compare�ȽϺ�����������Ĺ������ж�m��n�ĸ�Ӧ������
/*	ǰ�棬�����ǽ����Ƚ����������ֵ�ֵ�ĸ�����
/*	���ƴ��֮��mn<nm����ômӦ������n��ǰ�棬��֮�����nm<mn����
/*	nӦ������m��ǰ�棬���mn=nm����m=n.
**********************************************************************************/

//����������ÿ������ת��Ϊ�ַ���֮��ÿ���ַ������Ȳ�����10λ
const int g_MaxNumberBits=10;

//�Զ���ȽϺ������ȽϹ����ǽ����������ַ������ӳ�mn��nm��ʽ���Ƚϴ�С���ж�˭Ӧ������˭ǰ��
int compare(const void* number1,const void* number2)
{
	//����ȽϺ���������ÿ���������������ַ���
	char* g_strCombine1=new char[g_MaxNumberBits*2+1];
	char* g_strCombine2=new char[g_MaxNumberBits*2+1];

	//�����������ַ������ӳ�mn��ʽ
	strcpy(g_strCombine1,*(char**)number1);
	strcat(g_strCombine1,*(char**)number2);

	//�����������ַ������ӳ�nm��ʽ
	strcpy(g_strCombine2,*(char**)number2);
	strcat(g_strCombine2,*(char**)number1);

	//�Ƚ�mn��nm˭Ӧ������ǰ�棬˭����ǰ��˭С
	return strcmp(g_strCombine1,g_strCombine2);
}
string PrintMinNumber(int*numbers,int len)
{
	if(NULL==numbers||len<=0)
		return NULL;
	//char** strNumber=(char**)(new int[len]);//����һ������������ͬ����С���ַ�������
	char** strNumber=new char*[len];
	for(int i=0;i<len;i++)//�����������е�ÿ��Ԫ��ת��Ϊ�ַ����������������
	{
		strNumber[i]=new char[11];//Ϊ�ַ��������е�ÿ���ַ�������ռ�
		sprintf(strNumber[i],"%d",numbers[i]);
	}
	//�������ַ������鰴�ձȽϺ���������Ⱥ�����������
	qsort(strNumber,len,sizeof(char*),compare);

	string strMinNumber;
	for(int i=0;i<len;i++)//�����Ⱥ�˳��������ַ��������ÿ��Ԫ�أ�������һ��
		strMinNumber+=strNumber[i];

	//���շ��丨���ڴ�ռ�
	for(int i=0;i<len;i++)
		delete [] strNumber[i];
	return strMinNumber;
}

int main(int argc,char**argv)
{
	int numbers[]={3,32,321};
	int len=sizeof(numbers)/sizeof(int);
	string MinNumber=PrintMinNumber(numbers,len);
	cout<<"�������ųɵ���С���ǣ�"<<MinNumber.c_str()<<endl;
	return 0;
}