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

//����C++����ʦ�������յ�һ�㳣�ýⷨ
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

//�߼�C++����ʦ�������գ��÷����ǿ����쳣��ȫ�Ľⷨ
/******************************************************************************************
/*  �ýⷨ���ڸ�ֵ�������ȹ���һ����ʱʵ��mstr,���Ž�mstr.m_pData
/*  ��m_pData��һ�ν�������mstr.m_pDataָ��m_pData֮ǰָ����ڴ�
/*  ����mstr�Ǿֲ����������������е�if������ʱ���ͳ�����������Χ��
/*  �ͻ����mstr�����������Զ��ͷ�֮ǰ��ָ����ڴ���Դ������ʱmstr.m_pData
/*  ָ����ڴ���Ǹ�ֵ֮ǰ��m_pData���ڴ棬����൱�ڵ������������ͷ�ʵ�����ڴ档
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