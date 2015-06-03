#include<iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
/**********************************************************************
/*	在函数ConstructCore中，我们是先根据前序遍历序列的第一个数字创建
/*	根节点，接下来在中序遍历序列中找到根节点的位置，这样我们就能确定
/*	左、右子树结点的数量。在前序遍历和中序遍历的序列中划分了左、右子树
/*	结点的值之后，我们就可以递归调用函数ConstructCore，去分别构建它的
/*	左右子树。
************************************************************************/
BinaryTreeNode* ConstructCore(int* startDLR,int* endDLR,int* startLDR,int* endLDR)
{
	//前序遍历的第一个数字是二叉树根节点的值
	int rootValue=startDLR[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=rootValue;
	root->m_pLeft=NULL;
	root->m_pRight=NULL;
	//没有左子树
	if(startDLR==endDLR)
	{
		if(startLDR==endLDR && *startDLR==*startLDR)
			return root;
		else
			throw exception("Invalid Value.");
	}
	//在中序遍历中找到根节点的值
	int* rootLDR=startLDR;
	while(rootLDR<=endLDR&& *rootLDR!=rootValue)
		rootLDR++;
	//没有右子树
	if(rootLDR==endLDR&& *rootLDR!=rootValue)
		throw exception("Invalid Value.");

	int leftLen=rootLDR-startLDR;
	int* leftDLREnd=startDLR+leftLen;
	//若左子树长度大于零，则存在左子树，构建左子树 
	if(leftLen>0)
	{
		//构造左子树
		root->m_pLeft=ConstructCore(startDLR+1,leftDLREnd,startLDR,rootLDR-1);
	}
	//若左子树长度小于总长度，则存在右子树，构建右子树 
	if(leftLen<endDLR-startDLR)
	{
		//构造右子树
		root->m_pRight=ConstructCore(leftDLREnd+1,endDLR,rootLDR+1,endLDR);
	}
	return root;
}

BinaryTreeNode* ReConstructBinaryTree(int DLR[],int LDR[],int len)
{
	if(DLR==NULL||LDR==NULL||len<0)
		return NULL;
	return ConstructCore(DLR,DLR+len-1,LDR,LDR+len-1);
}

void PrintBinaryTree(BinaryTreeNode* root)
{
	/*if(NULL!=root)
	{
		if(root->m_pLeft!=NULL)
		PrintBinaryTree(root->m_pLeft);
		if(root->m_pRight!=NULL)
		PrintBinaryTree(root->m_pRight);
		cout<<root->m_nValue<<" ";
	}*/
	if(root==NULL)
		return;
	PrintBinaryTree(root->m_pLeft);
	PrintBinaryTree(root->m_pRight);
	cout<<root->m_nValue<<" ";
}

int main(int argc,char** argv)
{
	//int DLR[]={1,2,4,7,3,5,6,8};
	//int LDR[]={4,7,2,1,5,3,8,6};
	int DLR[]={1,2,3,4,5};
	int LDR[]={1,2,3,4,5};
	int len=sizeof(DLR)/sizeof(int);
	BinaryTreeNode* root=ReConstructBinaryTree(DLR,LDR,len);
	cout<<"后序遍历验证： ";
	PrintBinaryTree(root);
	cout<<endl;
	return 0;
}