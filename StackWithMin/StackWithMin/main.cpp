#include<iostream>
#include <stack>
#include "StackWithMin.h"
using namespace std;

int main(int argc,char** argv)
{
	StackWithMin stkMin;
	stkMin.push(3);
	stkMin.push(4);
	stkMin.push(2);
	cout<<"��ǰջ����СԪ���ǣ� "<<stkMin.Min()<<endl;
	stkMin.push(1);
	cout<<"��ǰջ����СԪ���ǣ� "<<stkMin.Min()<<endl;
	stkMin.pop();
	cout<<"��ǰջ����СԪ���ǣ� "<<stkMin.Min()<<endl;
	stkMin.pop();
	cout<<"��ǰջ����СԪ���ǣ� "<<stkMin.Min()<<endl;
	stkMin.push(0);
	cout<<"��ǰջ����СԪ���ǣ� "<<stkMin.Min()<<endl;
	return 0;
}