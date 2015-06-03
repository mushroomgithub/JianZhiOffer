#include <iostream>  
using namespace std;  
//在找到最大子数组和的同时，记录该子数组的开始位置和结束位置
void FindGreatestSumOfSubArray(int *ary,int len)
{
	int max=0;//保存最大和  
	int curSum=0;//保存当前和  
	int curStart=0;//当前和的起始位置  
	int start=0;//最大和的起始位置  
	int end=0;//最大和的终止位置  

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
			curSum=0;//与负数相加，和会减小，所以抛弃以前的和  
			curStart=i;  
		}  
		//最大值已经被保存下来，所以请大胆的继续往前加  
		curSum += ary[i];  
		//当前和被保存为最大值，记录下它的起始位置和结束位置  
		if(curSum>max)  
		{  
			max=curSum;  
			start=curStart;  
			end=i;  
		}  
	}  

	cout<<"和最大的子数组为："<<endl;
	cout<<"[ ";
	for(int i=start;i<=end;i++)  
	{  
		cout<<ary[i]<<" ";  
	}  
	cout<<"] = "<<max<<endl;  
}
//单纯的只是找到最大的子数组的和
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
	cout<<"求得最大子数组和是："<<Greastest<<endl;
}
void main()  
{  
	int ary[]={1,-2,3,10,-4,7,2,-5};  
	int len=sizeof(ary)/sizeof(int);
	//GreatestSumOfSubArray(ary,len);
	FindGreatestSumOfSubArray(ary,len);
	system("pause");
}  