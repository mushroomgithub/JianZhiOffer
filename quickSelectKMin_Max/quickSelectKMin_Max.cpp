#include<iostream>
using namespace std;
/*****************************************************************
/*	Author:	mushroom
/*	Note：
/*a[] - 要排序的数组
/*start - 要排序的子区间的开始索引
/*end - 要排序的子区间的结束索引
/*len 是数组的长度
/*k - 求出排序后第k个数
******************************************************************/
/*****************************************************************/
/*     快速查找无序数组中第K大的数
		算法思想：一趟快排之后，判断找到的哨兵pivot应该插入的位置
		low与len-k之间的关系，如果len-k=low,则返回a[low]的值，a[low]
		的值就是我们要查找数组额第k大的数；如果len-k>low,说明第k大的数在
		在low的右侧，否则如果len-k<low，说明第k大的数在low的左侧。
*****************************************************************/
int quickselectKMax(int a[], int start, int end,int len, int k){
	int low= start ;
	int high = end;
	int pivot= a[low];
	while(low<high){
		while(low<high&&pivot<a[high]) high--;
		a[low]=a[high];
		while(low<high&&a[low] <=pivot) low++;
		a[high]=a[low];
		//swap(a[low], a[high]);
	}
	a[low]=pivot;
	if(len-k==low)
		return a[low];
	else if(len-k>low)
		return quickselectKMax(a, low + 1, end,len,k);
	else
		return quickselectKMax(a, start, low - 1, len,k);
}
/*****************************************************************/
/*     快速查找无序数组中第K小的数
		算法思想：一趟快排之后，判断找到的哨兵pivot应该插入的位置
		low与k-1之间的关系，如果k-1=low,则返回a[low]的值，a[low]
		的值就是我们要查找数组额第k小的数；如果k-1>low,说明第k小的数在
		在low的右侧，否则如果k-1<low，说明第k大的数在low的左侧。
*****************************************************************/
int quickselectKMin(int a[], int start, int end, int k){
	int low = start;
	int high= end;
	int pivot= a[low];
	while(low<high){
		while(low<high&&pivot<a[high]) high--;
		a[low]=a[high];
		while(low<high&&a[low] <=pivot) low++;
		a[high]=a[low];
		//swap(a[low], a[high]);
	}
	a[low]=pivot;
	if(k - 1 == low)
		return a[low];
	else if(k - 1 > low)
		return quickselectKMin(a, low + 1, end, k);
	else
		return quickselectKMin(a, start, low - 1, k);
}
int main()
{
	int a[]={3,10,1,4,7,5,9,2,6};
	int len=sizeof(a)/sizeof(int);
	int k;
	cout<<"输入要查找的第K大数："<<endl;
	cin>>k;
	int numKMax=quickselectKMax(a,0,len-1,len,k);
	cout<<"无序数组中第"<<k<<"大的数是:"<<numKMax<<endl;
	cout<<endl;

	int n;
	cout<<"输入要查找的前n个最大的数个数："<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int numKMax=quickselectKMax(a,0,len-1,len,i);
		cout<<"无序数组中第"<<i<<"大的数是:"<<numKMax<<endl;
	}
	cout<<endl;

	int m;
	cout<<"输入要查找的前m个最小的数个数："<<endl;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int numKMin=quickselectKMin(a,0,len-1,i);
		cout<<"无序数组中第"<<i<<"小的数是:"<<numKMin<<endl;
	}
	return 0;
}