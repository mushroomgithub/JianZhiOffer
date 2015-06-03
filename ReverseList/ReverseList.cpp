#include<iostream>
#include<iomanip>
using namespace std;

typedef struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
}ListNode;
//初始化一个无头结点的单链表
ListNode* InitList()
{
	int value;
	cin>>value;
	ListNode*Head=new ListNode;
	Head->m_nValue=value;
	ListNode*pNode=NULL;
	pNode=Head;
	while(cin>>value)
	{
		if(-1==value)	break;
		ListNode*pCur=new ListNode;
		pCur->m_nValue=value;
		pCur->m_pNext=NULL;
		pNode->m_pNext=pCur;
		pNode=pCur;
	}
	return Head;
}
//打印所有链表结点
void PrintListNode(ListNode*Head)
{
	ListNode*p=Head;
	while(p)
	{
		cout<<p->m_nValue<<setw(4);
		p=p->m_pNext;
	}
	cout<<endl;
}

ListNode* ReverseList(ListNode*Head)
{
	if(!Head)
		return NULL;

	ListNode* pReversedHead=NULL;
	ListNode* pNode=Head;
	//反转链表第一个结点时，前驱为NULL
	ListNode* pPrev=NULL;
	while(pNode!=NULL)
	{
		//设置要反转结点的后继
		ListNode* pNext=pNode->m_pNext;
		if(pNext==NULL)	//表示链表只有一个节点
			pReversedHead=pNode;
		//保证反转链表之后不会出现断裂
		pNode->m_pNext=pPrev;
		//设置结点要反转结点的前驱
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}
int main(int argc,char** argv)
{
	cout<<"初始化链表："<<endl;
	ListNode*pHead=InitList();
	cout<<"打印反转链表之前的链表结点："<<endl;
	PrintListNode(pHead);
	cout<<"反转单链表："<<endl;
	pHead=ReverseList(pHead);
	cout<<"打印反转链表之后的链表结点："<<endl;
	PrintListNode(pHead);
	return 0;
}