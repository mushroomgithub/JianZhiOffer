#include<iostream>
#include<ctime>
using namespace std;

//��������ṹ
typedef struct ListNode{
	int value;
	struct ListNode* next;
}ListNode,pListNode;

//β�巨����������
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

//�ϲ�������������
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	ListNode* pMergedHead = NULL;

	/**********************************************************************/
	/*�������1��ͷ����ֵС������2ͷ����ֵ��������1��ͷ���
	/*���Ǻϲ��������ͷ���.
	/*��ʣ��Ľ���У��������2��ͷ���ֵС������1ͷ����ֵ����
	/*����2��ͷ�����ʣ�����ͷ��㣬���������֮ǰ�Ѿ��ϲ���
	/*�������β�����������.
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

//��ӡ��������
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
	pMergeHead=Merge(head1->next,head2->next);//�ֱ�ָ�����������һ��Ԫ�ص�ָ�봫�ݸ�Merge����
	//end=clock();
	cout<<"Merge Finsh!"<<endl;
	//cout<<"������ "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<" Seconds ʱ��"<<endl;
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