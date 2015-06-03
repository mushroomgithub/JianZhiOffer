//字符串模拟数字  
#include<stdio.h>
#include<iostream>
using namespace std;  

//字符串模拟加法  
bool Increment(char* number)  
{  
	//溢出判定  
	bool isOverFlow = false;  
	//进位  
	int nTakeOver = 0;  
	//长度  
	int nLength = strlen(number);  

	for(int i = nLength - 1; i >= 0; i--)  
	{  
		//第n位的值等于第n位字母的ascii减去 0 的ascii 再加第n+1位的进位  
		int nSum = number[i] - '0' + nTakeOver;  
		if(i == nLength - 1)
			++nSum;  
		if(nSum >= 10)  
		{  
			if(i == 0) 
				isOverFlow = true;  
			else  
			{  
				nSum -= 10;  
				nTakeOver = 1;  
				number[i] = '0' + nSum;  
			}  
		}  
		else  
		{  
			number[i] = '0' + nSum;  
			break;  
		}  
	}  
	return isOverFlow;  
}  
//打印字符串表示的数字  
void PrintNumber(char* number)  
{  
	bool isBegining0 = true;  
	int nLength = strlen(number);  

	for(int i = 0; i< nLength; ++i)  
	{  
		if(isBegining0 && number[i] != '0')  
			isBegining0 = false;  
		if(!isBegining0)  
		{  
			printf("%c",number[i]);  
		}  
	}  
	printf("\t");  
}  
 
void Print1ToNDigits(int n)  
{  
	if(n<0)   
		return;  
	char *number = new char[n+1];  
	memset(number, '0', n);  
	number[n] = '\0';  
	while(!Increment(number))  
	{  
		PrintNumber(number);  
	}  

	delete []number;  
}

int main(int argc,char** argv)
{  
	int n;
	cout<<"Pls Input the total bits of Number:"<<endl;
	while(cin>>n)
	{
		if(-1==n)	
		{
			cout<<"结束输入！"<<endl;
			break;
		}
		cout<<"打印从1到最大的"<<n<<"位数："<<endl;
		Print1ToNDigits(n);
		cout<<endl;
		cout<<"Pls Input the total bits of Number:"<<endl;
	}
	system("pause");
	return 0; 
}  