#include<iostream>
#include<ctime>
using namespace std;

//定义链表结构
typedef struct ListNode{
	int value;
	struct ListNode* next;
}ListNode,pListNode;

//尾插法创建单链表
ListNode* CreateList(int n)
{
	ListNode* pHead,*pre;
	int val;
	pHead=new ListNode();
	pHead->next=NULL;
	pre=pHead;
	if(0==n)
	{
		cout<<"Prameters n is error"<<endl;
		return NULL;
	}
	while(n>0)
	{
		cin>>val;
		ListNode* pCur=new ListNode();
		pCur->value=val;
		pCur->next=NULL;
		pre->next=pCur;
		pre=pCur;
		n--;
	}
	return pHead;
}

//合并两个有序单链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	ListNode* pMergedHead = NULL;

	/**********************************************************************/
	/*如果链表1的头结点的值小于链表2头结点的值，则链表1的头结点
	/*就是合并后链表的头结点.
	/*在剩余的结点中，如果链表2的头结点值小于链表1头结点的值，则
	/*链表2的头结点是剩余结点的头结点，把这个结点和之前已经合并好
	/*的链表的尾结点链接起来.
	/************************************************************************/
	if(pHead1->value< pHead2->value)
	{
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}

	return pMergedHead;
}

//打印单链表结点
void Print(ListNode* pHead)
{
	ListNode* pCur;
	if(pHead==NULL)
	{
		cout<<"List is empty!"<<endl;
		return;
	}
	pCur=pHead->next;
	while(pCur)
	{
		cout<<pCur->value<<" ";
		pCur=pCur->next;
	}
	cout<<endl<<endl;
}

int main(int argc,char** argv)
{
	ListNode* head1,*head2,*pMergeHead;
	int n1,n2;

	cout<<"Pls Input two list length:"<<endl;
	cin>>n1>>n2;

	cout<<endl;
	cout<<"Create sort List one:"<<endl;
	head1=CreateList(n1);
	cout<<"Print the list one:"<<endl;
	Print(head1);
	
	cout<<"Create sort List Two:"<<endl;
	head2=CreateList(n2);
	cout<<"Print the list two:"<<endl;
	Print(head2);
	//time_t start,end;
	cout<<"Merge two sort lists:"<<endl;
	//start=clock();
	//cout<<head1->next->value<<" "<<head2->next->value<<endl;
	pMergeHead=Merge(head1->next,head2->next);//分别将指向两个链表第一个元素的指针传递给Merge函数
	//end=clock();
	cout<<"Merge Finsh!"<<endl;
	//cout<<"共消耗 "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<" Seconds 时间"<<endl;
	cout<<"Print the merge List:"<<endl;
	while(pMergeHead)
	{
		cout<<pMergeHead->value<<" ";
		pMergeHead=pMergeHead->next;
	}	
	cout<<endl;
	//Print(pMergeHead);
	return 1;
}