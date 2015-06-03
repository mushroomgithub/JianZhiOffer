#include<iostream>
using namespace std;
/*****************************************************************
/*	Author:	mushroom
/*	Note��
/*a[] - Ҫ���������
/*start - Ҫ�����������Ŀ�ʼ����
/*end - Ҫ�����������Ľ�������
/*len ������ĳ���
/*k - ���������k����
******************************************************************/
/*****************************************************************/
/*     ���ٲ������������е�K�����
		�㷨˼�룺һ�˿���֮���ж��ҵ����ڱ�pivotӦ�ò����λ��
		low��len-k֮��Ĺ�ϵ�����len-k=low,�򷵻�a[low]��ֵ��a[low]
		��ֵ��������Ҫ����������k����������len-k>low,˵����k�������
		��low���Ҳ࣬�������len-k<low��˵����k�������low����ࡣ
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
/*     ���ٲ������������е�KС����
		�㷨˼�룺һ�˿���֮���ж��ҵ����ڱ�pivotӦ�ò����λ��
		low��k-1֮��Ĺ�ϵ�����k-1=low,�򷵻�a[low]��ֵ��a[low]
		��ֵ��������Ҫ����������kС���������k-1>low,˵����kС������
		��low���Ҳ࣬�������k-1<low��˵����k�������low����ࡣ
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
	cout<<"����Ҫ���ҵĵ�K������"<<endl;
	cin>>k;
	int numKMax=quickselectKMax(a,0,len-1,len,k);
	cout<<"���������е�"<<k<<"�������:"<<numKMax<<endl;
	cout<<endl;

	int n;
	cout<<"����Ҫ���ҵ�ǰn��������������"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int numKMax=quickselectKMax(a,0,len-1,len,i);
		cout<<"���������е�"<<i<<"�������:"<<numKMax<<endl;
	}
	cout<<endl;

	int m;
	cout<<"����Ҫ���ҵ�ǰm����С����������"<<endl;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int numKMin=quickselectKMin(a,0,len-1,i);
		cout<<"���������е�"<<i<<"С������:"<<numKMin<<endl;
	}
	return 0;
}