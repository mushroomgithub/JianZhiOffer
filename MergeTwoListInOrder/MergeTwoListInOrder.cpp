#include<iostream>
using namespace std;
typedef struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
}ListNode;
//��ʼ��һ��������
ListNode* InitList()
{
	ListNode*pHead,*p;
	int value;
	p=new ListNode;
	cin>>value;
	if(-1==value)
		return NULL;
	p->m_nValue=value;
	pHead=p;
	while(cin>>value)
	{
		if(-1==value) break;
		ListNode*pCur=new ListNode;
		pCur->m_nValue=value;
		p->m_pNext=pCur;
		p=pCur;
	}
	p->m_pNext=NULL;
	return pHead;
}
//��ӡ��������
void PrintListNode(ListNode*p)
{
	if(!p)	return;
	while(p!=NULL)
	{
		cout<<p->m_nValue<<"  ";
		p=p->m_pNext;
	}
	cout<<endl;
}
ListNode* joinTwoListInOrder(ListNode*La,ListNode*Lb)
{
	ListNode*Lc=NULL;//�ϲ�֮�������ͷָ��
	if(NULL==La)	//�����ж�������һ��Ϊ�յ��������ʱֻ��Ҫ������һ�������ͷָ�븳ֵ��Lc����
	{
		Lc=Lb;
		return Lc;
	}
	if(NULL==Lb)
	{
		Lc=La;
		return Lc;
	}
	//������������ָ�룬��ʼΪ�գ�����pa,ʼ��ָ������a��С�Ľ�㣬pbʼ��ָ��b������С�Ľ�㣬pcʼ��ָ��c�������һ�����
	ListNode*pa=NULL,*pb=NULL,*pc=NULL;
	if(La->m_nValue<=Lb->m_nValue)
	{
		Lc=La;//����Lcָ��������������С��������ͷָ��
		pa=La->m_pNext;//paָ����һ�����
		pb=Lb;
	}
	else
	{
		Lc=Lb;
		pb=Lb->m_pNext;
		pa=La;
	}
	pc=Lc;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->m_nValue<=pb->m_nValue)
		{
			pc->m_pNext=pa;
			pc=pa;
			pa=pa->m_pNext;
		}
		else
		{
			pc->m_pNext=pb;
			pc=pb;
			pb=pb->m_pNext;
		}
	}
	if(pa)		//���pa��Ϊ�գ���Laʣ�������ӵ�Lc�����ĩβ
	{
		pc->m_pNext=pa;
	}
	if(pb)	//���pb��Ϊ�գ���Lbʣ�������ӵ�Lc�����ĩβ
	{
		pc->m_pNext=pb;
	}
	return Lc;
}

int main(int argc,char** argv)
{
	ListNode*La,*Lb,*Lc;
	cout<<"��ʼ����������La:"<<endl;
	La=InitList();
	cout<<"��ʼ����������Lb:"<<endl;
	Lb=InitList();
	cout<<"��ӡ������La:"<<endl;
	PrintListNode(La);
	cout<<"��ӡ������Lb:"<<endl;
	PrintListNode(Lb);
	cout<<"�ϲ�������������La��Lb��Ϊһ������ĵ�����Lc��"<<endl;
	Lc=joinTwoListInOrder(La,Lb);
	cout<<"����ϲ�֮��ĵ�����Lc:"<<endl;
	PrintListNode(Lc);
	return 0;
}