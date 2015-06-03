#include<iostream>
#include<iomanip>
using namespace std;

typedef struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
}ListNode;

ListNode* InitList()
{
	ListNode*Head=new ListNode;
	ListNode*pNode=NULL;
	pNode=Head;
	int value;
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

void PrintListTailKNode(ListNode**Head,int k,int &e)
{
	if(!Head||0==k)
		return;
	ListNode*p=(*Head)->m_pNext;
	int ListLength=0;
	while(p)
	{
		ListLength++;
		p=p->m_pNext;
	}
	if(ListLength<k)
	{
		cout<<"Invalid Parameter K！"<<endl;
		return;
	}
	ListNode*p1,*p2;
	p1=p2=(*Head)->m_pNext;
	while(k&&p2)
	{
		p2=p2->m_pNext;
		k--;
	}
	if(0==k)
	{
		while(p2)
		{
			p2=p2->m_pNext;
			p1=p1->m_pNext;
		}
	}
	e=p1->m_nValue;
}

void PrintListNode(ListNode*Head)
{
	ListNode*p=Head->m_pNext;
	while(p)
	{
		cout<<p->m_nValue<<setw(4);
		p=p->m_pNext;
	}
	cout<<endl;
}

int main(int argc,char** argv)
{
	ListNode* pHead;
	cout<<"初始化单链表："<<endl;
	pHead=InitList();
	cout<<"打印单链表："<<endl;
	PrintListNode(pHead);
	int kValue=0;
	int k=0;
	cout<<"Pls input the K number:"<<endl;
	while(cin>>k)
	{
		if(-1==k)	break;
		PrintListTailKNode(&pHead,k,kValue);
		if(0==k)
			cout<<"Invalid parameter K input.Pls Retry..."<<endl;
		else
		{
			cout<<"链表的倒数第"<<k<<"个结点的值是："<<kValue<<endl;
			cout<<endl;
			cout<<"Pls input the K number:"<<endl;
		}
	}
	
	system("pause");
	return 0;
}