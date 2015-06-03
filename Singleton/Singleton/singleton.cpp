#include"singleton.h"
#include<iostream>

Singleton* Singleton::pInstance=NULL;
Singleton* Singleton::GetInstance()
{
	if(pInstance==NULL)
	{
		pInstance=new Singleton();
	}
	return pInstance;
}