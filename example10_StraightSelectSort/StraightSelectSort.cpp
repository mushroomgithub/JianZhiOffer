#include<iostream>
#include <algorithm>
using namespace std;
/**************************************************/
/*						直接选择排序
/*			note:		程序执行n-1趟选择排序，每次
/*						选择排序查找数组中的最小的元素
/*						的下标，然后交换，n-1趟排序之
/*						后，数组就拍好序了
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