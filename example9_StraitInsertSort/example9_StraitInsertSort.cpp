#include<iostream>
using namespace std;

/************************************************************/
/*									ֱ�Ӳ�������
/*		Note��	�����ڵ�ǰ������R[1..i-1]�в���R[i]����ȷ
/*					����λ��k(1��k��i-1)��Ȼ��R[k����i-1]��
/*					�ļ�¼������һ��λ�ã��ڳ�kλ���ϵĿ�	
/*					�����R[i]����R[i]�Ĺؼ��ִ��ڵ���R[1����i-1]
/*					�����м�¼�Ĺؼ��֣���R[i]���ǲ���ԭλ�á�
***************************************************************/
void StraightInsetSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=a[i];
		int k=i;	//a[i]��ʼ��λ��Ϊ��ǰ����������һλ
		if(a[i]<a[i-1])		//�����������һ��Ԫ��С�����������һ��Ԫ��
		{
			for(int j=i-1;j>=0;j--)		//������������a[i]����ȷ����λ��k
				if(temp<a[j])
					k=j;
			for(int m=i-1;m>=k;m--)		//��a[k...i-1]֮��ļ�¼���κ���һλ
				a[m+1]=a[m];		
		}
		a[k]=temp;	//��a[i]���뵽��ȷ��λ��
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