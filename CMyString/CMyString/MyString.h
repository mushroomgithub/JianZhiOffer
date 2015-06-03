#pragma once
#include<iostream>
class CMyString{
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString& str);
	char* GetData();
	~CMyString(void);
private:
	char* m_pData;
};