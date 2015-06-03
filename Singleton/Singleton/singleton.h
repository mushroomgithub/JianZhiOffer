#pragma once
#include <iostream>
using namespace std;
//��Singleton�ж���һ���ڲ���Deleter,������Deleter�ж���һ��ӵ�о�̬Deleter��Ա�������Ա���뿪��������ʱ���Զ�����������������
//�����Singletonʵ������ɾ�������������˳�ʱ�Զ�delete.
class Singleton{
private:
	Singleton() {
		cout<<"Singleton constructor...!"<<endl;
	};
	static Singleton *pInstance;
	virtual ~Singleton(){
		cout<<"Singleton Destroy!"<<endl;
	};
public:
	static Singleton* GetInstance();
	//....other Member or Funtions
	int a;
private:
	class Deleter{
	public:
		Deleter(){
			cout<<"����������������ϣ�"<<endl;
		};
		virtual ~Deleter()
		{
			if(Singleton::pInstance!=NULL)
			{
				delete Singleton::pInstance;
				Singleton::pInstance=NULL;
				cout<<"����Singleton����ʱ������ڴ棡"<<endl;
			}
		}
		//����һ����̬��Deleterʵ��
		static Deleter deleter;
	};
};