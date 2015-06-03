#include <iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nVlaue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
//���򴴽�һ�̶���������
BinaryTreeNode* CreateBinaryTree()
{
	int value;
	cin>>value;
	BinaryTreeNode* root=new BinaryTreeNode;
	if(-1==value)
		return NULL;
	root->m_nVlaue=value;
	root->m_pLeft=CreateBinaryTree();
	root->m_pRight=CreateBinaryTree();
	return root;
}

void InOrderTravsverBTree(BinaryTreeNode* root)
{
	if(NULL==root)
		return;
	InOrderTravsverBTree(root->m_pLeft);
	cout<<root->m_nVlaue<<" ";
	InOrderTravsverBTree(root->m_pRight);
}
/********************************************************************************************
/*	Author:	mushroom
/*	�㷨˼�룺
/*	����ݹ��������������Ϊ˫��������������㷨���ص��ǰ��մ�С�����˳��
/*	������������ÿһ����㡣�����������ڵ��ʱ�򣬰������������֣����ڵ㣬���ڵ��
/*	�����������ڵ����������������������Ķ��壬���ڵ㽫����������������һ���ڵ�
/*	����������ͬʱ��������������С�Ľ���������������Ƚ���������ת���������˫������
/*	֮���ٺ͸��ڵ��������������ö���������Ҳ��ת�����������˫�������ˡ���������������ص㣬
/*	�����������ڵ�ʱ�������������Ѿ�ת����������������ˣ��������������һ���ڵ��ǵ�ǰֵ
/*	���Ľ�㣬Ȼ�������������һ���ڵ�͸��ڵ�������������ʱ������ֵΪ���Ľ����Ǹ��ڵ��ˣ�
/*	����ȥ����ת�������������Ѹ��ڵ������������С�Ľ�����������������ͽ����ö���������ת����
/*	�����˫�������ˡ�
****************************************************************************************************/
void ConvertBinaryTreeNode(BinaryTreeNode*pNode,BinaryTreeNode**pLastNode)
{
	if(NULL==pNode)
		return;
	BinaryTreeNode* pCur=pNode;
	if(pCur->m_pLeft!=NULL)//����ת��������
		ConvertBinaryTreeNode(pCur->m_pLeft,pLastNode);

	//������������������ӳ���������Ĺ���
	pCur->m_pLeft=*pLastNode;//��ǰ�ڵ�ָ��ǰһ���ڵ�
	if(*pLastNode!=NULL)//���*pLastNode��ΪNULL��˵��ǰ��Ľڵ㲻�������ͷ���
		(*pLastNode)->m_pRight=pCur;//ǰһ���ڵ����ָ��ָ��ǰ�ڵ�
	*pLastNode=pCur;//ǰһ���ڵ���ǰ�ƶ�һ��λ�ã�ָ��ǰ�ڵ�

	if(pCur->m_pRight!=NULL)//����ת��������
		ConvertBinaryTreeNode(pCur->m_pRight,pLastNode);
}

BinaryTreeNode* ConvertBinarySearchTree(BinaryTreeNode*root)
{
	if(NULL==root)
		return NULL;

	BinaryTreeNode* pLastNode=NULL;//ת��Ϊ˫�������ͷָ�����ָ��ΪNULL
	ConvertBinaryTreeNode(root,&pLastNode);//�ݹ�ķ�ʽ������������ת��Ϊ˫������pLastNodeʼ��ָ����������һ���ڵ�
	//�ҵ�˫�������ͷָ�룬Ȼ�󷵻�
	BinaryTreeNode* pHeadList=pLastNode;
	while(pHeadList!=NULL&&pHeadList->m_pLeft!=NULL)
		pHeadList=pHeadList->m_pLeft;

	return pHeadList;
}
void PintDoubleList(BinaryTreeNode*pHeadList)
{
	BinaryTreeNode* pList=pHeadList;
	while(pList)
	{
		cout<<pList->m_nVlaue<<" ";
		pList=pList->m_pRight;
	}
	cout<<endl;
}
int main(int argc,char**argv)
{
	BinaryTreeNode* root;
	cout<<"Pls Initialize a Binary search Tree:"<<endl;
	root=CreateBinaryTree();
	cout<<"InOrder Travser Binary search Tree:"<<endl;
	InOrderTravsverBTree(root);
	cout<<endl;
	cout<<"Convert Binary Search Tree to A Double List:"<<endl;
	BinaryTreeNode*pHeadList=ConvertBinarySearchTree(root);
	cout<<"Convert Successfully!"<<endl;
	cout<<"Print Double List Now:"<<endl;
	PintDoubleList(pHeadList);
	return 0;
}