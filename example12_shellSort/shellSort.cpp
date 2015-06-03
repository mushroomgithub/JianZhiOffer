#include<iostream>
#include <algorithm>
using namespace std;
/*******************************************************/
/*						希尔排序
/*				note:对数组a作一趟希尔排序，其实就是对
/*						直接插入排序的一个改进.
/*				主要改进：
/*					1、前后记录位置的增量不是1而是d；
/*					2、j<=0时，表示插入位置已找到
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
//使用增量数组对数组a进行dlen趟希尔排序
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
	int d[]={5,3,1};	//增量递减数组，最后一个必须是1，表示当数组a基本有序时，再对数组a整体进行一次希尔排序
	int len=sizeof(a)/sizeof(int);
	int dlen=sizeof(d)/sizeof(int);
	shellSort(a,len,d,dlen);
	print(a,len);
	system("pause");
	return 1;
}