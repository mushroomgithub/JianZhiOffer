#include<iostream>
#include<deque>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;

//递归先序创建二叉树
BinaryTreeNode* CreateBinaryTree()
{
	int n;
	cin>>n;
	BinaryTreeNode* root=new BinaryTreeNode;
	if(-1==n)
		return NULL;
	root->m_nValue=n;

	root->m_pLeft=CreateBinaryTree();
	root->m_pRight=CreateBinaryTree();
	return root;
}
void PreOrderTravser(BinaryTreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->m_nValue<<"  ";
	PreOrderTravser(root->m_pLeft);
	PreOrderTravser(root->m_pRight);
}
void PrintBTreeFromTopToBottom(BinaryTreeNode* root)
{
	if(root==NULL)
		return;
	deque<BinaryTreeNode*>dq;
	dq.push_back(root);
	while(!dq.empty())
	{
		BinaryTreeNode* pCur=new BinaryTreeNode;
		pCur=dq.front();
		dq.pop_front();
		cout<<pCur->m_nValue<<"  ";
		if(pCur->m_pLeft)
			dq.push_back(pCur->m_pLeft);
		if(pCur->m_pRight)
			dq.push_back(pCur->m_pRight);
	}
}
int main(int argc,char**argv)
{
	BinaryTreeNode* root=NULL;
	cout<<"Initialize a BinaryTree:"<<endl;
	root=CreateBinaryTree();
	cout<<"PreOrder Travser the BinaryTree:"<<endl;
	PreOrderTravser(root);
	cout<<endl;
	cout<<"Print the BinaryTree from top to bottom:"<<endl;
	PrintBTreeFromTopToBottom(root);
	cout<<endl;
	return 0;
}