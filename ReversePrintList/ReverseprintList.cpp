#include<iostream>
#include<stack>
using namespace std;

typedef struct ListNode{
	int m_value;
	struct ListNode *next;
}ListNode;

ListNode* CreateList()
{
	ListNode* Head=new ListNode();
	Head->m_value=0;
	Head->next=NULL;
	ListNode* pHead=Head;
	int n;
	while(cin>>n)
	{
		if(-1==n)
			break;
		ListNode *pCur=new ListNode();
		pCur->m_value=n;
		pCur->next=NULL;
		Head->next=pCur;
		Head=pCur;
	}
	return pHead;
}

void ReversePrintList(ListNode* pHead)
{
	stack<ListNode*> stk;
	ListNode*p1,*pNode;
	if(pHead==NULL)
		return;
	p1=pHead->next;
	while(p1)
	{
		stk.push(p1);
		p1=p1->next;
	}
	while(!stk.empty())
	{
		pNode=stk.top();
		cout<<pNode->m_value<<" ";
		stk.pop();
	}
	cout<<endl;
}

int main(int argc,char** argv)
{
	cout<<"初始化创建单链表："<<endl;
	ListNode *pHead=CreateList();
	cout<<"逆序打印单链表："<<endl;
	ReversePrintList(pHead);
	return 0;
}