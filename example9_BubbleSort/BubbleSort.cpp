#include<iostream>
#include<algorithm>
using namespace std;

void BubbleSort(int a[],int n)
{
	for(int i=1;i<=n-1;i++)	//n��������ð��������Ҫn-1������
	{
		for(int j=1;j<=n-i;j++)	//ÿһ�������ڲ�ִ�еĽ���������n-i�Σ�һ���������������Ԫ��������ĩβ
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
	}
}

void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={2,6,4,3,5,1};
	int len=sizeof(a)/sizeof(int);
	cout<<"��ʼ����ð������"<<endl;
	BubbleSort(a,len);
	cout<<"OK,���������"<<endl;
	cout<<"��ӡ����֮������飺"<<endl;
	Print(a,len);
	system("pause");
}