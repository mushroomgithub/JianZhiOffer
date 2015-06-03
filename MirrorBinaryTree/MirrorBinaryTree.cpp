#include<iostream>
using namespace std;
typedef struct BinaryTreeNode{
	int m_nVlaue;
	struct BinaryTreeNode* m_pleft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
//����ݹ鴴��������
BinaryTreeNode* CreateBinaryTree()
{
	int n;
	cin>>n;
	BinaryTreeNode* root=new BinaryTreeNode();
	if(-1==n)
		return NULL;
	root->m_nVlaue=n;
	root->m_pleft=CreateBinaryTree();
	root->m_pRight=CreateBinaryTree();
	return root;
}
//����ݹ��ӡ������
void PrintBinaryTree(BinaryTreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->m_nVlaue<<"  ";
	PrintBinaryTree(root->m_pleft);
	PrintBinaryTree(root->m_pRight);
}

//����ݹ龵�������
/*****************************************************************
	Author�� mushroom
	note����һ���������ľ������Ҫ����˼·�ǣ���һ�Ŷ������ľ���
	����ʵ���ǽ�����������Ҷ�ӽڵ�����������ڵ㣬������ô��֮��
	��Ȼ�ýڵ�����������ڵ㽻���ˣ��������ҽڵ��µ������Ľ�㻹��û�н���
	�����������Ҳ�������ݹ�����ķ�ʽ���ڱ�����ͬʱ������������������
	֮�����ξ������������������������
	�����жϸýڵ��ǲ���Ҷ�ӽڵ㣬�����Ҷ�ӽڵ�����Ҫ������������Ƚ����ýڵ�����ҽڵ�
	��֮��ݹ龵��ýڵ������������������
*****************************************************************/
void MirrorBinaryTree(BinaryTreeNode* root)
{
	if(root==NULL)//������ڵ�Ϊ�գ�ֱ�ӷ���
		return;
	if(root->m_pleft==NULL&&root->m_pRight==NULL) //�����ǰ�ڵ���Ҷ�ӽڵ㣬ֱ�ӷ���
		return;
	//�����ǰ��㲻��Ҷ�ӽڵ㣬�ͽ������������ӽ��
	BinaryTreeNode* pTemp=root->m_pleft;
	root->m_pleft=root->m_pRight;
	root->m_pRight=pTemp;
	//����ýڵ��������
	//if(root->m_pleft)
	MirrorBinaryTree(root->m_pleft);
	//����ý���������
	//if(root->m_pRight)
	MirrorBinaryTree(root->m_pRight);
	
}
int main(int argc,char** argv)
{
	BinaryTreeNode* root=NULL;
	cout<<"Initialize the Binary Tree:"<<endl;
	root=CreateBinaryTree();
	cout<<"Print the Binary Tree Before Mirror:"<<endl;
	PrintBinaryTree(root);
	cout<<endl;
	MirrorBinaryTree(root);
	cout<<"Print the Binary Tree After Mirror:"<<endl;
	PrintBinaryTree(root);
	cout<<endl;
	system("pause");
	return 0;
}