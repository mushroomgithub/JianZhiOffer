//�ַ���ģ������  
#include<stdio.h>
#include<iostream>
using namespace std;  

//�ַ���ģ��ӷ�  
bool Increment(char* number)  
{  
	//����ж�  
	bool isOverFlow = false;  
	//��λ  
	int nTakeOver = 0;  
	//����  
	int nLength = strlen(number);  

	for(int i = nLength - 1; i >= 0; i--)  
	{  
		//��nλ��ֵ���ڵ�nλ��ĸ��ascii��ȥ 0 ��ascii �ټӵ�n+1λ�Ľ�λ  
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
//��ӡ�ַ�����ʾ������  
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
			cout<<"�������룡"<<endl;
			break;
		}
		cout<<"��ӡ��1������"<<n<<"λ����"<<endl;
		Print1ToNDigits(n);
		cout<<endl;
		cout<<"Pls Input the total bits of Number:"<<endl;
	}
	system("pause");
	return 0; 
}  