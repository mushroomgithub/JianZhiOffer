#include<iostream>
#include<stack>
using namespace std;
/**************************************************************
/*   Author: mushroom
/*   Note:  ��stk1������β��ÿ�δ�β������Ԫ�ض���
/*              ����Ԫ����stk1ջ����stk2������ͷ��ÿ��ɾ��
/*              ����Ԫ�ض��Ǵ�stk2��������ջ��Ԫ��
/*              ɾ������ʱ�����stk2Ϊ�գ����Ƚ�stk1�е�Ԫ��
/*              ��ջ��Ԫ�����ε�����stk2�У��������Ա�֤����
/*              �ӵ�Ԫ���ȳ��ӡ�
***************************************************************/
class CQueue{
public:
	CQueue(void){};
	~CQueue(void){};
	void appendTail(const int& node);
	int& deleteHead();
	int GetSize()
	{
		return stk1.size();
	}
private:
	stack<int>stk1;
	stack<int>stk2;
};

void CQueue::appendTail(const int& node)
{
	stk1.push(node);
}

int& CQueue::deleteHead()
{
	if(stk2.size()<=0)
	{
		while(stk1.size()>0)
		{
			int temp=stk1.top();
			stk1.pop();
			stk2.push(temp);
		}
	}

	if(stk2.size()==0)
		cout<<"queue is empty."<<endl;
	int head=stk2.top();
	stk2.pop();

	return head;
}

int main(int argc,char** argv)
{
	int n;
	CQueue queue;
	cout<<"�Ӷ���β���������ݣ�"<<endl;
	while(cin>>n)
	{
		if(-1==n) break;
		cout<<n<<"�Ӷ���β�����."<<endl;
		queue.appendTail(n);
	}
	cout<<endl;

	cout<<"�Ӷ���ͷ��ɾ�����ݣ�"<<endl;
	int qsize=queue.GetSize();
	while(qsize)
	{
		int head=queue.deleteHead();
		cout<<head<<"�Ӷ���ͷ������."<<endl;
		qsize--;
	}
	return 0;
}