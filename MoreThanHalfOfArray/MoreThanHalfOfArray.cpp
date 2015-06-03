#include<iostream>
using namespace std;
//方案一
/*int CheckMoreThanHalfOfArray(int *a,int len)
{
	if(NULL==a||len<=0)
		return -1;
	int res=-1;
	int hash[256]={0};
	int i;
	for(i=0;i<len;i++)
		hash[a[i]]++;
	for(i=0;i<len;i++)
	{
		if(hash[a[i]]>len/2)
		{
			res=a[i];
			break;
		}
	}
	return res;
}*/

//方案二
int partition(int *a,int low,int high)
{
	if(a==NULL)
		return -1;
	int pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=pivot)
			high--;
		a[low]=a[high];
		while(low<high&&a[low]<pivot)
			low++;
		a[high]=a[low];
		//swap(a[low],a[high]);
	}
	a[low]=pivot;
	return low;
}
int CheckMoreThanHalfOfArray(int *a,int len)
{
	if(a==NULL||len<=0)
		return -1;

	int res=-1;
	int mid=len>>1;
	int low=0;
	int high=len-1;
	int index=partition(a,low,high);
	while(index!=mid)
	{
		if(index<mid)
		{
			low=index+1;
			index=partition(a,low,high);
		}
		if(index>mid)
		{
			high=index-1;
			index=partition(a,low,high);
		}
	}
	//默认当到下标为len/2位置时，已经取到出现次数大于数组一半的数字
	res=a[index];

	//验证得到的位置数字是否是出现次数大于数组一半的数
	int count=0;
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<len;i++)
	{
		if(res==a[i])
			count++;
	}
	if(count*2<=len)
		res=-1;

	return res;
}
int main(int argc,char**argv)
{
	int a[]={1,2,3,2,2,2,5,4,2};
	int len=sizeof(a)/sizeof(int);
	int result=CheckMoreThanHalfOfArray(a,len);
	if(-1!=result)
	cout<<"The num appear More Than Half Of Array is: "<<result<<endl;
	else
		cout<<"No More than Half of Array in the Array!"<<endl;
	system("pause");
	return 0;
}