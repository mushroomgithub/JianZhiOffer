#include<iostream>
using namespace std;

typedef struct BinaryTreeNode{
	int m_nValue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;

BinaryTreeNode*InitBinaryTree()
{
	int n;
	cin>>n;
	BinaryTreeNode* root=new BinaryTreeNode();
	if(-1==n)
		return NULL;
	else
	{
		root->m_nValue=n;
		root->m_pLeft=InitBinaryTree();
		root->m_pRight=InitBinaryTree();
	}
	return root;
}

void PreTravserBinaryTree(BinaryTreeNode* root)
{
	if(NULL==root)
		return;
	cout<<root->m_nValue<<"  ";
	PreTravserBinaryTree(root->m_pLeft);
	PreTravserBinaryTree(root->m_pRight);
}
bool DoTree1HaveTree2(BinaryTreeNode* root1,BinaryTreeNode* root2)//�ж�tree1�Ƿ�����ӽṹtree2
{
	if(NULL==root2)//���ж�tree2�Ƿ�Ϊ�գ����Ϊ�գ���ʾ���ӽṹ
		return true;
	if(NULL==root1)//֮�����ж�tree1�Ƿ�Ϊ�գ����Ϊ�գ���ʾ�����ӽṹ
		return false;
	
	if(root1->m_nValue!=root2->m_nValue) //���tree1��tree2�ĸ��ڵ�ֵ��ͬ������root1Ϊ��������������root2Ϊ���ڵ������һ����������ͬ�Ľ��
		return false;
	//���valueֵ��ͬ,�����ж���root1��root2Ϊ�����������������������Ƿ������ͬ�Ľ��
	return DoTree1HaveTree2(root1->m_pLeft,root2->m_pLeft)&&DoTree1HaveTree2(root1->m_pRight,root2->m_pRight);

}
bool isSubTree(BinaryTreeNode* root1,BinaryTreeNode* root2)
{//������root1Ϊ����������A����root2Ϊ����������B
	bool isSub=false;
	if(root1!=NULL&&root2!=NULL)//�����������Ϊ��
	{
		if(root1->m_nValue==root2->m_nValue)////���ȿ���A��ĳһ������ֵ����B�ĸ��ڵ�ֵ�Ƿ���ͬ�������ͬ,�ж���������Ϊ���������Ƿ��к���Bһ��������
			isSub=DoTree1HaveTree2(root1,root2);
		if(!isSub)//����������ֵ��������B���ڵ��ֵ�����ж����������������Ƿ�������ӽṹ
			isSub=isSubTree(root1->m_pLeft,root2);
		if(!isSub)//����������ֵ��������B���ڵ��ֵ�����ж����������������Ƿ�������ӽṹ
			isSub=isSubTree(root1->m_pRight,root2);
	}
	return isSub;
}

int main(int argc,char**argv)
{
	BinaryTreeNode* root1=NULL,*root2=NULL;
	cout<<"Initialize the Tree1:"<<endl;
	root1=InitBinaryTree();
	cout<<"Pre Order Print the Tree1:"<<endl;
	PreTravserBinaryTree(root1);
	cout<<endl;
	cout<<"Initialize the Tree1:"<<endl;
	root2=InitBinaryTree();
	cout<<"Pre Order Print the Tree2:"<<endl;
	PreTravserBinaryTree(root2);
	cout<<endl;
	bool isSubStru=false;
	isSubStru=isSubTree(root1,root2);
	if(isSubStru)
	{
		cout<<"Tree2 is a Sub Structure of Tree1."<<endl;
	}
	else
	{
		cout<<"Tree2 is not a Sub Structure of Tree1."<<endl;
	}
	return 0;
}