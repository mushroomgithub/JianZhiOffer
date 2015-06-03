#include<iostream>
#include <algorithm>
using namespace std;
/*******************************************************/
/*						ϣ������
/*				note:������a��һ��ϣ��������ʵ���Ƕ�
/*						ֱ�Ӳ��������һ���Ľ�.
/*				��Ҫ�Ľ���
/*					1��ǰ���¼λ�õ���������1����d��
/*					2��j<=0ʱ����ʾ����λ�����ҵ�
*********************************************************/
void shellInsert(int a[],int n,int d)
{
	for(int i=d;i<n;i++)
	{
		int temp=a[i];
		int k=i;
		if(a[i]<a[i-d])
		{
			for(int j=i-d;j>=0;j-=d)
				if(temp<a[j])
					k=j;
			for(int m=i-d;m>=k;m-=d)
				a[m+d]=a[m];
		}
		a[k]=temp;
	}
}
//ʹ���������������a����dlen��ϣ������
void shellSort(int a[],int n,int d[],int dlen)
{
	for(int i=0;i<dlen;i++)
		shellInsert(a,n,d[i]);
}
void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={49,38,65,97,76,13,27,49,55,4};
	int d[]={5,3,1};	//�����ݼ����飬���һ��������1����ʾ������a��������ʱ���ٶ�����a�������һ��ϣ������
	int len=sizeof(a)/sizeof(int);
	int dlen=sizeof(d)/sizeof(int);
	shellSort(a,len,d,dlen);
	print(a,len);
	system("pause");
	return 1;
}