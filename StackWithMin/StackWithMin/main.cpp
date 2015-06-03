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
	cout<<"当前栈中最小元素是： "<<stkMin.Min()<<endl;
	stkMin.push(1);
	cout<<"当前栈中最小元素是： "<<stkMin.Min()<<endl;
	stkMin.pop();
	cout<<"当前栈中最小元素是： "<<stkMin.Min()<<endl;
	stkMin.pop();
	cout<<"当前栈中最小元素是： "<<stkMin.Min()<<endl;
	stkMin.push(0);
	cout<<"当前栈中最小元素是： "<<stkMin.Min()<<endl;
	return 0;
}