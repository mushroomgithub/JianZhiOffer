#include<iostream>
#include"singleton.h"
using namespace std;

int main(int argc,char** argv)
{
	Singleton *Instance1=Singleton::GetInstance();
	Instance1->a=10;
	Singleton *Instance2=Singleton::GetInstance();
	cout<<Instance2->a<<endl;
	if(Instance2==Instance1)
		cout<<"ֻ�������һ��ʵ����"<<endl;
	else
		cout<<"����ģʽ����ʧ�ܣ�"<<endl;
	return 0;
}