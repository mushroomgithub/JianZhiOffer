#include <iostream>  
using namespace std;  
void main()  
{  
	int array[]={1,-2,3,10,-4,7,2,-5};  
	int len=sizeof(array)/sizeof(int);

	int max=0;//保存最大和  
	int curSum=0;//保存当前和  
	int curStart=0;//当前和的起始位置  
	int start=0;//最大和的起始位置  
	int end=0;//最大和的终止位置  

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
			curSum=0;//与负数相加，和会减小，所以抛弃以前的和  
			curStart=i;  
		}  
		//最大值已经被保存下来，所以请大胆的继续往前加  
		curSum += array[i];  
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
		cout<<array[i]<<" ";  
	}  
	cout<<"] = "<<max<<endl;  
	system("pause");
}  