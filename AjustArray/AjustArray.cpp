#include<iostream>
#include<iomanip>
using namespace std;
void AjustArrayOddEven(int *a,int len)
{
	int low=0;
	int high=len-1;
	while(low<high)
	{
		while(low<high&&a[high]%2==0)
			high--;
		while(low<high&&a[low]%2!=0)
			low++;
		swap(a[low],a[high]);
	}
}

void PrintArray(int *a,int len)
{
	for(int i=0;i<len;i++)
		cout<<a[i]<<setw(4);
	cout<<endl;
}

int main(int argc,char** argv)
{
	int a[]={2,3,4,6,9,11,8,12,7};
	int len=sizeof(a)/sizeof(int);
	AjustArrayOddEven(a,len);
	PrintArray(a,len);
	return 0;
}