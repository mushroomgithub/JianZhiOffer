#include <iostream>  
using namespace std;  
void main()  
{  
	int array[]={1,-2,3,10,-4,7,2,-5};  
	int len=sizeof(array)/sizeof(int);

	int max=0;//��������  
	int curSum=0;//���浱ǰ��  
	int curStart=0;//��ǰ�͵���ʼλ��  
	int start=0;//���͵���ʼλ��  
	int end=0;//���͵���ֹλ��  

	for(int i=0;i<len;i++)  
	{  
		if(i==0)  
		{  
			curSum=max=array[i];
			start=curStart=i;
			continue;  
		}  

		if(curSum<0)  
		{  
			curSum=0;//�븺����ӣ��ͻ��С������������ǰ�ĺ�  
			curStart=i;  
		}  
		//���ֵ�Ѿ�������������������󵨵ļ�����ǰ��  
		curSum += array[i];  
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
		cout<<array[i]<<" ";  
	}  
	cout<<"] = "<<max<<endl;  
	system("pause");
}  