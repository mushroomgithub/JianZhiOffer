/*#include<iostream>
using namespace std;
class A
{
public:
	int m;
	 virtual ~A(){}         //�麯�� ��̬
};
class B:public A
{
public:
	int m;         //B ��Ա
};
int main()
{
	A* pObjA = new A();
	B* pObjB  = NULL;
	//pObjB = static_cast<B*>(pObjA);   //����ָ��ת��Ϊ����ָ�� �ɹ�ת��
	//cout<<"����Aָ��ĵ�ַ�� "<<pObjA<<endl;
	//cout<<"����Bָ��ĵ�ַ�� "<<pObjB<<endl;
	//pObjB->m = 10;	//ʵ����pObj��ָ��Ķ��� ��A�����
	//cout<<pObjA->m<<endl;
	//�����
	pObjB = dynamic_cast<B*>(pObjA);
	cout<<"����Aָ��ĵ�ַ�� "<<pObjA<<endl;
	cout<<"����Bָ��ĵ�ַ�� "<<pObjB<<endl;
	//pObjB->m = 10;	//ʵ����pObj��ָ��Ķ��� ��A�����
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