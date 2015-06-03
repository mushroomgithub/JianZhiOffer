#include<iostream>
#include<cmath>
using namespace std;

double Power(double base,int exponent)
{
	double result=1.0;
	if(exponent<0)
	{
		if(0==base)
		{
			cout<<"Invalid Input of base!"<<endl;
			exit(-1);
		}
		exponent=abs(exponent);
		for(int i=1;i<=exponent;i++)
			result*=base;
		result=1.0/result;
		return result;
	}
	if(0==exponent)
		return 1;
	else if(exponent>0)
	{
		for(int i=1;i<=exponent;i++)
			result*=base;
	}

	return result;
}

int main(int argc,char** argv)
{
	int n;
	double m;
	cout<<"Pls input the base of Power:"<<endl;
	cin>>m;
	cout<<"Pls input the exponent of Power:"<<endl;
	while(cin>>n)
	{
		if('e'==n)
			break;
		double result=Power(m,n);
		cout<<"Power("<<m<<","<<n<<") = "<<result<<endl;
	}
	return 0;
}