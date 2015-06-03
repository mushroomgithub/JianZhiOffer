#include<iostream>
#include<stack>
using namespace std;
//从尾部逆序打印单链表
//创建链表结点结构体
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
		pre->next=pCur;	//将当前新节点插入到上一个结点末尾
		pre=pCur;//将上一个结点指针指向新节点，即上一个结点后移
		cin>>val;
	}
	
	pstack=pHead->next;
	while(pstack!=NULL)
	{
		node.push(pstack);
		pstack=pstack->next;
	}
	cout<<"开始从栈中逆序打印链表元素:"<<endl;
	while(!node.empty())
	{
		ListNode *pTemp=node.top();
		cout<<pTemp->value<<endl;
		node.pop();
	}
	system("pause");
	return 1;
}