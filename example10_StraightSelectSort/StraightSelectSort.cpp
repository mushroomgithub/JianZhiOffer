#include<iostream>
#include <algorithm>
using namespace std;
/**************************************************/
/*						ֱ��ѡ������
/*			note:		����ִ��n-1��ѡ������ÿ��
/*						ѡ��������������е���С��Ԫ��
/*						���±꣬Ȼ�󽻻���n-1������֮
/*						��������ĺ�����
****************************************************/
void StraightSelectSort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
		}
		swap(a[i],a[min]);
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={2,6,4,3,5,1};
	int len=sizeof(a)/sizeof(int);
	StraightSelectSort(a,len);
	print(a,len);
	system("pause");
	return 1;
}