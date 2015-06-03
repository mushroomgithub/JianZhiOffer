#include "MyString.h"
#include<iostream>

CMyString::CMyString(char* pData/* =NULL */)
{
	m_pData=new char[strlen(pData)+1];
	/*memcpy(m_pData,pData,strlen(pData));
	m_pData[strlen(pData)]='\0';*/
	strcpy(m_pData,pData);
}
CMyString::CMyString(const CMyString& str)
{
	m_pData=new char[strlen(str.m_pData)+1];
	/*memcpy(m_pData,str.m_pData,strlen(str.m_pData));
	m_pData[strlen(str.m_pData)]='\0';*/
	strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString(void)
{
	if(m_pData!=NULL)
		delete [] m_pData;
	m_pData=NULL;
}

char* CMyString::GetData()
{
	if(m_pData==NULL)
		return NULL;
	else
		return m_pData;
}

//初级C++工程师必须掌握的一般常用解法
/*CMyString& CMyString::operator=(const CMyString& str)
{
	if(this==&str)
		return *this;
	if(m_pData!=NULL)
		delete [] m_pData;
	m_pData=NULL;
	m_pData=new char[strlen(str.m_pData)+1];
	/*memcpy(m_pData,str.m_pData,strlen(str.m_pData));
	m_pData[strlen(str.m_pData)]='\0';*/
	/*strcpy(m_pData,str.m_pData);
	return *this;
}*/

//高级C++工程师必须掌握，该方法是考虑异常安全的解法
/******************************************************************************************
/*  该解法是在赋值函数中先构造一个临时实例mstr,接着将mstr.m_pData
/*  和m_pData做一次交换，让mstr.m_pData指向m_pData之前指向的内存
/*  由于mstr是局部变量，当程序运行到if的外面时，就出了其作用域范围，
/*  就会调用mstr的析构函数自动释放之前其指向的内存资源，而此时mstr.m_pData
/*  指向的内存就是赋值之前的m_pData的内存，这就相当于调用析构函数释放实例的内存。
***********************************************************************************************/
CMyString& CMyString::operator=(const CMyString &str)
{
	if(this!=&str)
	{
		CMyString mstr(str);
		char* tempStr=mstr.m_pData;
		mstr.m_pData=m_pData;
		m_pData=tempStr;
	}
	return *this;
}