#pragma once
#include <iostream>
using namespace std;
//在Singleton中定义一个内部类Deleter,并且在Deleter中定义一个拥有静态Deleter成员，这个成员在离开其作用域时会自动调用其析构函数，
//负责对Singleton实例进行删除，这样程序退出时自动delete.
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
			cout<<"垃圾回收器构造完毕！"<<endl;
		};
		virtual ~Deleter()
		{
			if(Singleton::pInstance!=NULL)
			{
				delete Singleton::pInstance;
				Singleton::pInstance=NULL;
				cout<<"回收Singleton创建时分配的内存！"<<endl;
			}
		}
		//定义一个静态的Deleter实例
		static Deleter deleter;
	};
};