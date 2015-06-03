#include<iostream>
using namespace std;
typedef struct ListNode{
	int m_nValue;
	struct ListNode* m_pNext;
}ListNode;
//初始化一个单链表
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
//打印单链表结点
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
	ListNode*Lc=NULL;//合并之后链表的头指针
	if(NULL==La)	//首先判断链表有一个为空的情况，此时只需要将另外一个链表的头指针赋值给Lc即可
	{
		Lc=Lb;
		return Lc;
	}
	if(NULL==Lb)
	{
		Lc=La;
		return Lc;
	}
	//声明三个链表指针，初始为空，其中pa,始终指向链表a最小的结点，pb始终指向b链表最小的结点，pc始终指向c链表最后一个结点
	ListNode*pa=NULL,*pb=NULL,*pc=NULL;
	if(La->m_nValue<=Lb->m_nValue)
	{
		Lc=La;//设置Lc指向两个链表中最小结点的链表头指针
		pa=La->m_pNext;//pa指向下一个结点
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
	if(pa)		//如果pa不为空，则将La剩余结点连接到Lc链表的末尾
	{
		pc->m_pNext=pa;
	}
	if(pb)	//如果pb不为空，则将Lb剩余结点连接到Lc链表的末尾
	{
		pc->m_pNext=pb;
	}
	return Lc;
}

int main(int argc,char** argv)
{
	ListNode*La,*Lb,*Lc;
	cout<<"初始化升序单链表La:"<<endl;
	La=InitList();
	cout<<"初始化升序单链表Lb:"<<endl;
	Lb=InitList();
	cout<<"打印单链表La:"<<endl;
	PrintListNode(La);
	cout<<"打印单链表Lb:"<<endl;
	PrintListNode(Lb);
	cout<<"合并两个有序单链表La，Lb，为一个有序的单链表Lc："<<endl;
	Lc=joinTwoListInOrder(La,Lb);
	cout<<"输出合并之后的单链表Lc:"<<endl;
	PrintListNode(Lc);
	return 0;
}