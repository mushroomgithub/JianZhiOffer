#include<iostream>
#include<deque>
using namespace std;
int main(int argc,char** argv)
{
	deque<int> dq;
	for(int i=0;i<5;i++)
		dq.push_back(i+1);
	for(int i=0;i<5;i++)
		cout<<dq[i]<<" ";
	cout<<endl;

	//从头部插入元素，不会增加总元素个数，只是将原有的元素依次后移
	dq.push_front(6);
	dq.push_front(7);
	dq.push_front(8);
	for(int i=0;i<8;i++)
		cout<<dq[i]<<" ";
	cout<<endl;
	return 1;
}