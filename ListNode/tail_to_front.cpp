#include<iostream>
#include<stack>
using namespace std;
//��β�������ӡ������
//����������ṹ��
typedef struct ListNode{
	int value;
	struct ListNode *next;
}ListNode,*pListNode;

int main(int argc,char** argv)
{
	ListNode *pHead,*pre;
	int val;
	pHead=new ListNode();
	pre=pHead;
	stack<ListNode*> node;
	ListNode *pstack;
	cin>>val;
	while(val!=-1)
	{
		ListNode *pCur=new ListNode();
		pCur->value=val;
		pCur->next=NULL;
		pre->next=pCur;	//����ǰ�½ڵ���뵽��һ�����ĩβ
		pre=pCur;//����һ�����ָ��ָ���½ڵ㣬����һ��������
		cin>>val;
	}
	
	pstack=pHead->next;
	while(pstack!=NULL)
	{
		node.push(pstack);
		pstack=pstack->next;
	}
	cout<<"��ʼ��ջ�������ӡ����Ԫ��:"<<endl;
	while(!node.empty())
	{
		ListNode *pTemp=node.top();
		cout<<pTemp->value<<endl;
		node.pop();
	}
	system("pause");
	return 1;
}