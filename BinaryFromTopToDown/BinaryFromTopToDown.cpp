#include<iostream>
#include<deque>//˫�˶�������
using namespace std;

typedef struct BinaryTreeNode{
	int value;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode,*pBinaryTreeNode;

//���򴴽�������
void CreateBinaryTree(BinaryTreeNode* &pRoot)
{
	int val=0;
	cin>>val;
	if(-1==val)
	{
		return;
	}
	else
	{
		pRoot=new BinaryTreeNode();
		pRoot->value=val;
		CreateBinaryTree(pRoot->m_pLeft);
		CreateBinaryTree(pRoot->m_pRight);
	}
}

//�����ӡ������
void PrintInOrder(BinaryTreeNode* pRoot)
{
	if(pRoot!=NULL)
	{
		PrintInOrder(pRoot->m_pLeft);
		cout<<pRoot->value<<" ";
		PrintInOrder(pRoot->m_pRight);
	}
}

//���϶��´�ӡ���������
void PrintBinaryFromTopToDown(BinaryTreeNode* pRoot)
{
	if(pRoot==NULL)
		return;

	deque<BinaryTreeNode*>myDeque;
	myDeque.push_back(pRoot);
	while(!myDeque.empty())
	{
		BinaryTreeNode* pTop=myDeque.front();//ÿ��ȡ��˫�˶��������еĵ�һ��Ԫ��
		cout<<pTop->value<<" ";//��ӡ˫�˶��������ĵ�һ��Ԫ��
		myDeque.pop_front();//��ǰ����˫�˶��������ĵ�һ��Ԫ��
		if(pTop->m_pLeft!=NULL)//����ýڵ�������ӽڵ�
		{
			myDeque.push_back(pTop->m_pLeft);//�򽫸ýڵ�����ӽڵ����˫�˶��������ĺ���
		}
	     if(pTop->m_pRight!=NULL)//����ýڵ�����Һ��ӽڵ�
		{
			myDeque.push_back(pTop->m_pRight);//�򽫸ýڵ���Һ��ӽڵ��ŵ�˫�˶��������ĺ���
		}
	}
}

int main(int argc,char** argv)
{
	BinaryTreeNode *pRoot=NULL;
	cout<<"����һ����������"<<endl;
	CreateBinaryTree(pRoot);
	cout<<"�����ӡ�����õĶ�������"<<endl;
	PrintInOrder(pRoot);
	cout<<endl;
	cout<<"���϶��´�ӡ��������㣺"<<endl;
	PrintBinaryFromTopToDown(pRoot);
	cout<<endl;
	system("pause");
	return 1;
}