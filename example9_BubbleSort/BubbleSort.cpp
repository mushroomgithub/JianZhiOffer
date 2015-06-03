#include<iostream>
#include<algorithm>
using namespace std;

void BubbleSort(int a[],int n)
{
	for(int i=1;i<=n-1;i++)	//n个数进行冒泡排序，需要n-1趟排序
	{
		for(int j=1;j<=n-i;j++)	//每一堂排序，内部执行的交换次数我n-i次，一趟排序结束后，最大的元素总是在末尾
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
	cout<<"开始进行冒泡排序："<<endl;
	BubbleSort(a,len);
	cout<<"OK,排序已完成"<<endl;
	cout<<"打印排序之后的数组："<<endl;
	Print(a,len);
	system("pause");
}