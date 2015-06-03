#include<iostream>
#include<algorithm>
using namespace std;

//将有二个有序数列a[first...mid]和a[mid...last]合并
/****************************************************************/
/*									函数: MergeArray
/*将将二个有序数列合并。这个非常简单，只要从比较二个数列
/*的第一个数，谁小就先取谁，取了后就在对应数列中删除这个数。
/*然后再进行比较，如果有数列为空，那直接将另一个数列的
/*数据依次取出即可
****************************************************************/
void MergeArray(int a[], int first, int mid, int last, int temp[])  
{  
	int i = first, j = mid + 1;  
	int m = mid,n = last;  
	int k = 0;  
	while (i <= m && j <= n)  
	{  
		if (a[i] <= a[j])  
			temp[k++] = a[i++];  
		else  
			temp[k++] = a[j++];  
	}  
	while (i <= m)  
		temp[k++] = a[i++];  
	while (j <= n)  
		temp[k++] = a[j++];  

	for (i = 0; i < k; i++)  
		a[first + i] = temp[i];  
}

void mSort(int a[], int first, int last, int temp[])  
{  
	if (first < last)  
	{  
		int mid = (first + last) / 2;  
		mSort(a, first, mid, temp);    //左边有序  
		mSort(a, mid + 1, last, temp); //右边有序  
		MergeArray(a, first, mid, last, temp); //再将二个有序数列合并  
	}  
}  

bool MergeSort(int a[], int n)  
{  
	int *p = new int[n];  
	if (p == NULL)  
		return false;  
	mSort(a, 0, n - 1, p);  
	delete[] p;  
	return true;  
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={49,38,65,97,76,13,27};
	int len=sizeof(a)/sizeof(int);
	cout<<"开始归并排序："<<endl;
	MergeSort(a,len);
	cout<<"排序完成！"<<endl;
	cout<<"打印排序后的数组："<<endl;
	print(a,len);
	system("pause");
	return 0;
}