#include<iostream>
#include <algorithm>
using namespace std;
/************************************************************/
/*							��������
/*	note��	ÿ�ο��Ž��������ĵ�һ��Ԫ����Ϊpivot
/*				�����low<high,��Ӻ���ǰ�ж����
/*				a[high]>=pivot��high--,ֱ���ҵ�һ��
/*				a[high]<pivot��������ʱa[low]��a[high]��ֵ
/*				Ȼ�����low<high������pivot>a[low],��low++
/*				ֱ���ҵ�һ��a[low]>pivot��������ʱa[low]��
/*				a[high]��ֵ�����ҽ���low=highʱ��һ�����������
/*				����Ľ���Ǳ�pivotС��Ԫ�ط���pivot����࣬
/*				��pivot���Ԫ������pivot���Ҳ�
*****************************************************************/
int partition(int a[],int low,int high)	//һ�˿�������
{
	int pivot=a[low];
	while(low<high)//low=high�ǽ�������
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
	if(low<high)	//����������low=high
	{
		int pivotLoc=partition(a,low,high);  //һ�˿��Ž�ԭ���зֳ�ǰ��������
		QuickSort(a,low,pivotLoc-1);	//��ǰ�벿�ֽ��п�������
		QuickSort(a,pivotLoc+1,high);		//�Ժ�벿�ֽ��п�������
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