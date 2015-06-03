/*****************************************************/
/*得到一个链表倒数第k个结点的值
/*****************************************************/
#include<iostream>
using namespace std;

typedef struct ListNode{
	int value;
	struct ListNode* next;
}ListNode,*pListNode;

//查找链表中倒数第K个结点
pListNode findLastKNode(ListNode* pHead,int k)
{
	if(pHead->next==NULL)
		return NULL;
	ListNode *p1,*p2;
	p1=p2=pHead;
	while(k>0&&p2->next!=NULL)
	{
		p2=p2->next;
		k--;
	}
	if(k==0)
	{
		while(p2!=NULL)
		{
			p1=p1->next;
			p2=p2->next;
		}
		return p1;
	}
	else
	{
		cout<<"The number of List less K"<<endl;
		return NULL;
	}
}

//创建一个单链表，当输入-1时结束链表创建
ListNode* CreateList()
{
	ListNode* pHead,*pre;
	int val;
	pHead=new ListNode();
	pre=pHead;
	cin>>val;
	while(val!=-1)
	{
		ListNode* pCur=new ListNode();
		pCur->value=val;
		pCur->next=NULL;
		pre->next=pCur;
		pre=pCur;
		cin>>val;
	}
	return pHead;
}

int main(int argc,char** argv)
{

	pListNode head,KNode;
	int k;
	cout<<"Create a List..."<<endl;
	head=CreateList();
	cout<<"Input the K value:"<<endl;
	cin>>k;
	KNode=findLastKNode(head,k);
	if(KNode==NULL)
	{
		cout<<"The last k Node is not found!"<<endl;
		return -1;
	}
	else
	{
		cout<<"The last K node Value of the List is: "<<KNode->value<<endl;
	}
	return 1;
}