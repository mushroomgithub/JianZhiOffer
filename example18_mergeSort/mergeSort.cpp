#include<iostream>
#include<algorithm>
using namespace std;

//���ж�����������a[first...mid]��a[mid...last]�ϲ�
/****************************************************************/
/*									����: MergeArray
/*���������������кϲ�������ǳ��򵥣�ֻҪ�ӱȽ϶�������
/*�ĵ�һ������˭С����ȡ˭��ȡ�˺���ڶ�Ӧ������ɾ���������
/*Ȼ���ٽ��бȽϣ����������Ϊ�գ���ֱ�ӽ���һ�����е�
/*��������ȡ������
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
		mSort(a, first, mid, temp);    //�������  
		mSort(a, mid + 1, last, temp); //�ұ�����  
		MergeArray(a, first, mid, last, temp); //�ٽ������������кϲ�  
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
	cout<<"��ʼ�鲢����"<<endl;
	MergeSort(a,len);
	cout<<"������ɣ�"<<endl;
	cout<<"��ӡ���������飺"<<endl;
	print(a,len);
	system("pause");
	return 0;
}