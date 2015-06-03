#include<iostream>
#include"MyString.h"
using namespace std;

int main(int argc,char** argv)
{
	CMyString mstr1("Hello!");
	cout<<mstr1.GetData()<<endl;

	CMyString mstr2(mstr1);
	cout<<mstr2.GetData()<<endl;

	CMyString mstr3="mogu!";
	mstr1=mstr2=mstr3;
	cout<<mstr1.GetData()<<endl;
	return 0;
}