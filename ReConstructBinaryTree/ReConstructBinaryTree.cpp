#include<iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
/**********************************************************************
/*	�ں���ConstructCore�У��������ȸ���ǰ��������еĵ�һ�����ִ���
/*	���ڵ㣬����������������������ҵ����ڵ��λ�ã��������Ǿ���ȷ��
/*	��������������������ǰ���������������������л�������������
/*	����ֵ֮�����ǾͿ��Եݹ���ú���ConstructCore��ȥ�ֱ𹹽�����
/*	����������
************************************************************************/
BinaryTreeNode* ConstructCore(int* startDLR,int* endDLR,int* startLDR,int* endLDR)
{
	//ǰ������ĵ�һ�������Ƕ��������ڵ��ֵ
	int rootValue=startDLR[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->m_nValue=rootValue;
	root->m_pLeft=NULL;
	root->m_pRight=NULL;
	//û��������
	if(startDLR==endDLR)
	{
		if(startLDR==endLDR && *startDLR==*startLDR)
			return root;
		else
			throw exception("Invalid Value.");
	}
	//������������ҵ����ڵ��ֵ
	int* rootLDR=startLDR;
	while(rootLDR<=endLDR&& *rootLDR!=rootValue)
		rootLDR++;
	//û��������
	if(rootLDR==endLDR&& *rootLDR!=rootValue)
		throw exception("Invalid Value.");

	int leftLen=rootLDR-startLDR;
	int* leftDLREnd=startDLR+leftLen;
	//�����������ȴ����㣬����������������������� 
	if(leftLen>0)
	{
		//����������
		root->m_pLeft=ConstructCore(startDLR+1,leftDLREnd,startLDR,rootLDR-1);
	}
	//������������С���ܳ��ȣ������������������������ 
	if(leftLen<endDLR-startDLR)
	{
		//����������
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
	cout<<"���������֤�� ";
	PrintBinaryTree(root);
	cout<<endl;
	return 0;
}