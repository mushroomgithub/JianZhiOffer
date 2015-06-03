#include<iostream>
using namespace  std;

int FibinacciN(int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	return FibinacciN(n-1)+FibinacciN(n-2);
}

int uFibinacciN(unsigned int n)
{
	int Fib[2]={0,1};
	if(n<2)
		return Fib[n];
	long long fibTwo=0;
	long long fibone=1;
	long long fibN=0;
	for(unsigned int i=2;i<=n;i++)
	{
		fibN=fibone+fibTwo;
		fibTwo=fibone;
		fibone=fibN; //���汾�μ�����м����ֵ
	}
	return fibN;
}
int main(int argc,char** argv)
{
	int n;
	unsigned int m;
	/*while(cin>>n)
	{
		if(-1==n) break;
		int FibN=FibinacciN(n);
		cout<<"��"<<n<<"��Fibonacci���е�ֵ�ǣ�"<<FibN<<endl;
	}*/
	while(cin>>m)
	{
		if(-1==m) break;
	   unsigned long long  FibN=uFibinacciN(m);
		cout<<"��"<<m<<"��Fibonacci���е�ֵ�ǣ�"<<FibN<<endl;
	}
	system("pause");
	return 0;
}