#include<iostream>
#include<vector>
using namespace std;
typedef struct BinaryTreeNode{
	int m_nVlaue;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
//����ݹ鴴��������
BinaryTreeNode* CreateBinaryTree()
{
	int n;
	BinaryTreeNode* root=new BinaryTreeNode();
	cin>>n;
	if(-1==n)
		return NULL;
	root->m_nVlaue=n;
	root->m_pLeft=CreateBinaryTree();
	root->m_pRight=CreateBinaryTree();
	return root;
}
//����ݹ����ֵΪĳһ����ֵ������·���������ӡ����
void FindPath(BinaryTreeNode* root,int &currentSum,vector<int>path,int exceptSum)
{
	currentSum+=root->m_nVlaue;
	path.push_back(root->m_nVlaue);

	bool isLeaf=root->m_pLeft==NULL&&root->m_pRight==NULL;

	if(currentSum==exceptSum&&isLeaf)
	{
		cout<<"Find A Path:"<<endl;
		vector<int>::iterator it=path.begin();
		for(;it!=path.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}

	if(root->m_pLeft!=NULL)
		FindPath(root->m_pLeft,currentSum,path,exceptSum);
	if(root->m_pRight!=NULL)
		FindPath(root->m_pRight,currentSum,path,exceptSum);
	int temp=path.back();
	currentSum-=temp;
	path.pop_back();
}
//�жϸ��ڵ��Ƿ�Ϊ�գ�Ϊ��ֱ�ӷ��أ�����ȫ��·������ṹ
void FindPathInBinaryTree(BinaryTreeNode* root,int exceptSum)
{
	if(root==NULL)
		return;
	int currentSum=0;
	vector<int> vecPath;
	FindPath(root,currentSum,vecPath,exceptSum);
}

//����ݹ��ӡ������
void printBinaryTree(BinaryTreeNode* root)
{
	if(NULL==root)
		return;
	cout<<root->m_nVlaue<<" ";
	printBinaryTree(root->m_pLeft);
	printBinaryTree(root->m_pRight);
}

int main(int argc,char** argv)
{
	BinaryTreeNode* root=NULL;
	cout<<"Initlize a BinaryTree:"<<endl;
	root=CreateBinaryTree();
	cout<<"Print the Initlize BinaryTree:"<<endl;
	printBinaryTree(root);
	cout<<endl;
	cout<<"Find Path node In Binary Tree with A exceptSum:"<<endl;
	int exceptSum;
	cout<<"Pls Input A exceptSum which you want to find a Path in BinaryTree:"<<endl;
	cin>>exceptSum;
	FindPathInBinaryTree(root,exceptSum);
	return 0;
}