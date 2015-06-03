#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
/***************************************************************************
/*	Author:		mushroom
/*	算法思想：在求数组能排成的最小的数字的过程中，如果
/*	直接采用数值法，最后可能造成连接成的最小数，超过了int
/*	型所能表示的范围，无疑这是一个大数问题，为了解决此
/*	问题，我们可以将数字转化成字符串，由于把数字m和n转换成
/*	字符串之后，它们拼接起来的得到mn和nm两种形式，它们的
/*	位数一定是相同的，为了比较它们的大小，只需要按照字符串大小
/*	的比较规则就可以了，我们首先将整形数组的每个元素转换为字符串,
/*	并保存在分配好的字符串数组中，之后我们采用qsort函数对，该字符数组
/*	排序，定义compare比较函数，它定义的规则是判断m和n哪个应该排在
/*	前面，而不是仅仅比较这两个数字的值哪个更大。
/*	如果拼接之后，mn<nm，那么m应该排在n的前面，反之，如果nm<mn，则
/*	n应该排在m的前面，如果mn=nm，则m=n.
**********************************************************************************/

//假设数组中每个数字转化为字符串之后每个字符串长度不超过10位
const int g_MaxNumberBits=10;

//自定义比较函数，比较规则是将两个数字字符串连接成mn和nm形式，比较大小，判断谁应该排在谁前面
int compare(const void* number1,const void* number2)
{
	//定义比较函数中用于每次连接两个数字字符串
	char* g_strCombine1=new char[g_MaxNumberBits*2+1];
	char* g_strCombine2=new char[g_MaxNumberBits*2+1];

	//将两个数字字符串链接成mn形式
	strcpy(g_strCombine1,*(char**)number1);
	strcat(g_strCombine1,*(char**)number2);

	//将两个数字字符串链接成nm形式
	strcpy(g_strCombine2,*(char**)number2);
	strcat(g_strCombine2,*(char**)number1);

	//比较mn和nm谁应该排在前面，谁排在前面谁小
	return strcmp(g_strCombine1,g_strCombine2);
}
string PrintMinNumber(int*numbers,int len)
{
	if(NULL==numbers||len<=0)
		return NULL;
	//char** strNumber=(char**)(new int[len]);//创建一个跟整形数组同样大小的字符串数组
	char** strNumber=new char*[len];
	for(int i=0;i<len;i++)//将整形数组中的每个元素转换为字符串，解决大数问题
	{
		strNumber[i]=new char[11];//为字符串数组中的每个字符串分配空间
		sprintf(strNumber[i],"%d",numbers[i]);
	}
	//对整个字符串数组按照比较函数定义的先后规则进行排序
	qsort(strNumber,len,sizeof(char*),compare);

	string strMinNumber;
	for(int i=0;i<len;i++)//将按先后顺序排序的字符串数组的每个元素，连接在一起
		strMinNumber+=strNumber[i];

	//回收分配辅助内存空间
	for(int i=0;i<len;i++)
		delete [] strNumber[i];
	return strMinNumber;
}

int main(int argc,char**argv)
{
	int numbers[]={3,32,321};
	int len=sizeof(numbers)/sizeof(int);
	string MinNumber=PrintMinNumber(numbers,len);
	cout<<"把数组排成的最小数是："<<MinNumber.c_str()<<endl;
	return 0;
}