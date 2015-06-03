#include<iostream>
using namespace std;

/************************************************************/
/*									直接插入排序
/*		Note：	首先在当前有序区R[1..i-1]中查找R[i]的正确
/*					插入位置k(1≤k≤i-1)；然后将R[k．．i-1]中
/*					的记录均后移一个位置，腾出k位置上的空	
/*					间插入R[i]；若R[i]的关键字大于等于R[1．．i-1]
/*					中所有记录的关键字，则R[i]就是插入原位置。
***************************************************************/
void StraightInsetSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int k=i;	//a[i]初始化位置为当前有序区的下一位
		if(a[i]<a[i-1])		//如果无序区第一个元素小于有序区最后一个元素
		{
			for(int j=i-1;j>=0;j--)		//在有序区查找a[i]的正确插入位置k
				if(temp<a[j])
					k=j;
			for(int m=i-1;m>=k;m--)		//将a[k...i-1]之间的纪录依次后移一位
				a[m+1]=a[m];		
		}
		a[k]=temp;	//将a[i]插入到正确的位置
	}
}

void PrintArray(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc,char** argv)
{
	int a[]={2,6,4,3,5,1};
	int len=sizeof(a)/sizeof(int);
	StraightInsetSort(a,len);
	PrintArray(a,len);
	system("pause");
	return 1;
}