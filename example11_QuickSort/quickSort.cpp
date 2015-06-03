#include<iostream>
#include <algorithm>
using namespace std;
/************************************************************/
/*							快速排序
/*	note：	每次快排将无序区的第一个元素作为pivot
/*				，如果low<high,则从后向前判断如果
/*				a[high]>=pivot，high--,直到找到一个
/*				a[high]<pivot，交换此时a[low]与a[high]的值
/*				然后如果low<high，并且pivot>a[low],则low++
/*				直到找到一个a[low]>pivot，交换此时a[low]，
/*				a[high]的值，当且仅当low=high时，一趟排序结束，
/*				排序的结果是比pivot小的元素放在pivot的左侧，
/*				比pivot大的元素排在pivot的右侧
*****************************************************************/
int partition(int a[],int low,int high)	//一趟快排排序
{
	int pivot=a[low];
	while(low<high)//low=high是结束条件
	{
		while(low<high&&pivot<=a[high]) high--;
		//swap(a[low],a[high]);
		a[low]=a[high];
		while(low<high&&pivot>a[low]) low++;
		//swap(a[low],a[high]);
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}

void QuickSort(int a[],int low,int high)
{
	if(low<high)	//结束条件是low=high
	{
		int pivotLoc=partition(a,low,high);  //一趟快排将原序列分成前后两部分
		QuickSort(a,low,pivotLoc-1);	//对前半部分进行快速排序
		QuickSort(a,pivotLoc+1,high);		//对后半部分进行快速排序
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={2,6,3,5,4,7,1};
	int len=sizeof(a)/sizeof(int);
	int low=0;
	int high=len-1;
	QuickSort(a,low,high);
	print(a,len);
	system("pause");
}