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

	//��ͷ������Ԫ�أ�����������Ԫ�ظ�����ֻ�ǽ�ԭ�е�Ԫ�����κ���
	dq.push_front(6);
	dq.push_front(7);
	dq.push_front(8);
	for(int i=0;i<8;i++)
		cout<<dq[i]<<" ";
	cout<<endl;
	return 1;
}