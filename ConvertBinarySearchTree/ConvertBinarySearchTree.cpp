#include <iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nVlaue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
//先序创建一刻二叉搜索树
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
/*	算法思想：
/*	中序递归调整二叉搜索树为双向链表，中序遍历算法的特点是按照从小到大的顺序
/*	遍历二叉树的每一个结点。当遍历到根节点的时候，把树看成三部分：根节点，根节点的
/*	左子树，根节点的右子树，根据排序链表的定义，根节点将和他左子树上最大的一个节点
/*	链接起来，同时还将和右子树最小的结点链接起来，首先将左右子树转换成排序的双向链表，
/*	之后再和根节点链接起来，整棵二叉搜索树也就转换成了排序的双向链表了。按照中序遍历的特点，
/*	当遍历到根节点时，他的左子树已经转换成了排序的链表了，并且链表中最后一个节点是当前值
/*	最大的结点，然后将左子树的最后一个节点和根节点链接起来，此时链表中值为最大的结点就是根节点了，
/*	接着去遍历转换右子树，并把根节点和右子树中最小的结点链接起来。这样就将整棵二叉搜索树转换成
/*	排序的双向链表了。
****************************************************************************************************/
void ConvertBinaryTreeNode(BinaryTreeNode*pNode,BinaryTreeNode**pLastNode)
{
	if(NULL==pNode)
		return;
	BinaryTreeNode* pCur=pNode;
	if(pCur->m_pLeft!=NULL)//遍历转换左子树
		ConvertBinaryTreeNode(pCur->m_pLeft,pLastNode);

	//将二叉搜索树结点链接成排序链表的过程
	pCur->m_pLeft=*pLastNode;//当前节点指向前一个节点
	if(*pLastNode!=NULL)//如果*pLastNode不为NULL，说明前面的节点不是链表的头结点
		(*pLastNode)->m_pRight=pCur;//前一个节点的右指针指向当前节点
	*pLastNode=pCur;//前一个节点向前移动一个位置，指向当前节点

	if(pCur->m_pRight!=NULL)//遍历转换右子树
		ConvertBinaryTreeNode(pCur->m_pRight,pLastNode);
}

BinaryTreeNode* ConvertBinarySearchTree(BinaryTreeNode*root)
{
	if(NULL==root)
		return NULL;

	BinaryTreeNode* pLastNode=NULL;//转换为双向链表的头指针的左指针为NULL
	ConvertBinaryTreeNode(root,&pLastNode);//递归的方式将二叉搜索树转换为双向链表，pLastNode始终指向链表的最后一个节点
	//找到双向链表的头指针，然后返回
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