#include<iostream>
#include<stack>
using namespace std;
/**************************************************************
/*   Author: mushroom
/*   Note:  将stk1视作队尾，每次从尾部插入元素都是
/*              将新元素入stk1栈，将stk2视作队头，每次删除
/*              队首元素都是从stk2顶部弹出栈顶元素
/*              删除操作时，如果stk2为空，则先将stk1中的元素
/*              的栈顶元素依次弹出到stk2中，这样可以保证先入
/*              队的元素先出队。
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
	cout<<"从队列尾部插入数据："<<endl;
	while(cin>>n)
	{
		if(-1==n) break;
		cout<<n<<"从队列尾部入队."<<endl;
		queue.appendTail(n);
	}
	cout<<endl;

	cout<<"从队列头部删除数据："<<endl;
	int qsize=queue.GetSize();
	while(qsize)
	{
		int head=queue.deleteHead();
		cout<<head<<"从队列头部出队."<<endl;
		qsize--;
	}
	return 0;
}