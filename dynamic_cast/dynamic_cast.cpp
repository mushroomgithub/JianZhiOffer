/*#include<iostream>
using namespace std;
class A
{
public:
	int m;
	 virtual ~A(){}         //虚函数 多态
};
class B:public A
{
public:
	int m;         //B 成员
};
int main()
{
	A* pObjA = new A();
	B* pObjB  = NULL;
	//pObjB = static_cast<B*>(pObjA);   //基类指针转化为子类指针 成功转换
	//cout<<"对象A指针的地址： "<<pObjA<<endl;
	//cout<<"对象B指针的地址： "<<pObjB<<endl;
	//pObjB->m = 10;	//实际中pObj所指向的对象 是A类对象
	//cout<<pObjA->m<<endl;
	//如果：
	pObjB = dynamic_cast<B*>(pObjA);
	cout<<"对象A指针的地址： "<<pObjA<<endl;
	cout<<"对象B指针的地址： "<<pObjB<<endl;
	//pObjB->m = 10;	//实际中pObj所指向的对象 是A类对象
	//cout<<pObjB->m<<endl;
	return 0;
}*/

/*#include<iostream>
using namespace std;

int main()
{
	int i[2]={1073741824,-1073741824};
	int *p1=&i[0];
	char *p2=(char*)&i[0];
	float *p3=(float*)&i[0];
	printf("%d->%d\n",p1,*p1);
	printf("%d->%d\n",p2,*p2);
	printf("%d->%f\n",p3,*p3);
	p1++;
	p2++;
	p3++;
	printf("%d->%d\n",p1,*p1);
	printf("%d->%d\n",p2,*p2);
	printf("%d->%f\n",p3,*p3);

	system("pause");

}
*/

#include<iostream>
using namespace std;
int main()
{
	char *str[]={"welcome","to","Fortemedia","Nanjing"};
	char**p=str+1;
	str[0]=(*p++)+2;
	str[1]=*(p+1);
	str[2]=p[1]+3;
	str[3]=p[0]+(str[2]-str[1]);
	cout<<str[0]<<endl;
	cout<<str[1]<<endl;
	cout<<str[2]<<endl;
	cout<<str[3]<<endl;
	system("pause");
}