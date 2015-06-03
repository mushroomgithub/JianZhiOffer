#include<iostream>
using namespace std;
typedef struct ListNode{
	int m_nKey;
	struct ListNode* m_pNext;
}ListNode;
//尾插法创建单链表
ListNode* InitList()
{
	int Key=0;
	ListNode*pHead=NULL;
	while(cin>>Key)
	{
		if(-1==Key)
			break;

		ListNode* pCur=new ListNode;
		pCur->m_nKey=Key;

		pCur->m_pNext=pHead;
		pHead=pCur;
	}
	return pHead;
}

void PrintList(ListNode*pHead)
{
	if(pHead)
	{
		ListNode* p=pHead;
		while(p)
		{
			cout<<p->m_nKey<<" ";
			p=p->m_pNext;
		}
		cout<<endl;
	}
}

void addCommonNodeToTail(ListNode*&pHead1,ListNode*&pHead2)
{
	if(pHead1==NULL||pHead2==NULL)
		return;
	ListNode*pTail1=NULL,*pTail2=NULL;
	ListNode*p1=pHead1;
	ListNode*p2=pHead2;
	while(p1->m_pNext)
	{
		p1=p1->m_pNext;
	}
	while(p2->m_pNext)
	{
		p2=p2->m_pNext;
	}
	pTail1=p1;
	pTail2=p2;
	int key;
	while(cin>>key)
	{
		if(-1==key)
			break;
		ListNode* pCur=new ListNode;
		pCur->m_nKey=key;
		pCur->m_pNext=NULL;
		pTail1->m_pNext=pCur;
		pTail2->m_pNext=pCur;
		pTail1=pCur;
		pTail2=pCur;
	}
}

int GetLength(ListNode*pHead)
{
	if(pHead==NULL)
		return 0;
	ListNode*p=pHead;
	int len=0;
	while(p)
	{
		len++;
		p=p->m_pNext;
	}
	return len;
}

ListNode* FindFirstCommonNodeInLists(ListNode*pHead1,ListNode*pHead2)
{
	if(pHead1==NULL||pHead2==NULL)
		return NULL;

	int len1=GetLength(pHead1);
	int len2=GetLength(pHead2);
	int DiffLen;
	ListNode*pListLongHead;
	ListNode*pListShortHead;
	if(len1>len2)
	{
		DiffLen=len1-len2;
		pListLongHead=pHead1;
		pListShortHead=pHead2;
	}
	else
	{
		DiffLen=len2-len1;
		pListLongHead=pHead2;
		pListShortHead=pHead1;
	}

	while(DiffLen)
	{
		pListLongHead=pListLongHead->m_pNext;
		DiffLen--;
	}
	while(pListLongHead&&pListShortHead)
	{
		if(pListShortHead==pListLongHead)
			return pListShortHead;

		pListShortHead=pListShortHead->m_pNext;
		pListLongHead=pListLongHead->m_pNext;
	}
	return NULL;
}
int main()
{
	cout<<"Initialize A List One:"<<endl;
	ListNode* Head1=InitList();
	cout<<"Print the List One:"<<endl;
	PrintList(Head1);
	cout<<"Initialize A List Two:"<<endl;
	ListNode*Head2=InitList();
	cout<<"Print the List One:"<<endl;
	PrintList(Head2);
	cout<<"Add New Common Node to List:"<<endl;
	addCommonNodeToTail(Head1,Head2);
	cout<<"Print the List One After Add New Node:"<<endl;
	PrintList(Head1);
	cout<<"Print the List Two After Add New Node:"<<endl;
	PrintList(Head2);

	int len1=GetLength(Head1);
	int len2=GetLength(Head2);
	ListNode*pCommonNode=FindFirstCommonNodeInLists(Head1,Head2);
	if(pCommonNode!=NULL)
		cout<<"两个链表第一个公共结点值是："<<pCommonNode->m_nKey<<endl;
	else
		cout<<"两个链表没有公共结点"<<endl;
	cout<<"Print all common node from the first common node in two list:"<<endl;
	PrintList(pCommonNode);
	return 0;
}