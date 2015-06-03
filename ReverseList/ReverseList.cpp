#include<iostream>
#include<iomanip>
using namespace std;

typedef struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
}ListNode;
//��ʼ��һ����ͷ���ĵ�����
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
//��ӡ����������
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
	//��ת�����һ�����ʱ��ǰ��ΪNULL
	ListNode* pPrev=NULL;
	while(pNode!=NULL)
	{
		//����Ҫ��ת���ĺ��
		ListNode* pNext=pNode->m_pNext;
		if(pNext==NULL)	//��ʾ����ֻ��һ���ڵ�
			pReversedHead=pNode;
		//��֤��ת����֮�󲻻���ֶ���
		pNode->m_pNext=pPrev;
		//���ý��Ҫ��ת����ǰ��
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}
int main(int argc,char** argv)
{
	cout<<"��ʼ������"<<endl;
	ListNode*pHead=InitList();
	cout<<"��ӡ��ת����֮ǰ�������㣺"<<endl;
	PrintListNode(pHead);
	cout<<"��ת������"<<endl;
	pHead=ReverseList(pHead);
	cout<<"��ӡ��ת����֮��������㣺"<<endl;
	PrintListNode(pHead);
	return 0;
}