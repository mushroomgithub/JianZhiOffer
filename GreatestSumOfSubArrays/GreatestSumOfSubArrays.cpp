#include <iostream>  
using namespace std;  
//���ҵ����������͵�ͬʱ����¼��������Ŀ�ʼλ�úͽ���λ��
void FindGreatestSumOfSubArray(int *ary,int len)
{
	int max=0;//��������  
	int curSum=0;//���浱ǰ��  
	int curStart=0;//��ǰ�͵���ʼλ��  
	int start=0;//���͵���ʼλ��  
	int end=0;//���͵���ֹλ��  

	for(int i=0;i<len;i++)  
	{  
		if(i==0)  
		{  
			curSum=max=ary[i];
			start=curStart=i;
			continue;  
		}  

		if(curSum<0)  
		{  
			curSum=0;//�븺����ӣ��ͻ��С������������ǰ�ĺ�  
			curStart=i;  
		}  
		//���ֵ�Ѿ�������������������󵨵ļ�����ǰ��  
		curSum += ary[i];  
		//��ǰ�ͱ�����Ϊ���ֵ����¼��������ʼλ�úͽ���λ��  
		if(curSum>max)  
		{  
			max=curSum;  
			start=curStart;  
			end=i;  
		}  
	}  

	cout<<"������������Ϊ��"<<endl;
	cout<<"[ ";
	for(int i=start;i<=end;i++)  
	{  
		cout<<ary[i]<<" ";  
	}  
	cout<<"] = "<<max<<endl;  
}
//������ֻ���ҵ�����������ĺ�
void GreatestSumOfSubArray(int *a,int len)
{
	if(NULL==a||len<=0)
		return;

	int Greastest;
	int curMax=0;
	Greastest=curMax;
	for(int i=0;i<len;i++)
	{
		if(curMax<=0)
			curMax=a[i];
		else
			curMax+=a[i];

		if(curMax>Greastest)
			Greastest=curMax;
	}
	cout<<"��������������ǣ�"<<Greastest<<endl;
}
void main()  
{  
	int ary[]={1,-2,3,10,-4,7,2,-5};  
	int len=sizeof(ary)/sizeof(int);
	//GreatestSumOfSubArray(ary,len);
	FindGreatestSumOfSubArray(ary,len);
	system("pause");
}  