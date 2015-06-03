#include<iostream>
using namespace std;
typedef struct BinaryTreeNode{
	int m_nVlaue;
	struct BinaryTreeNode* m_pleft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode;
//先序递归创建二叉树
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
//先序递归打印二叉树
void PrintBinaryTree(BinaryTreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->m_nVlaue<<"  ";
	PrintBinaryTree(root->m_pleft);
	PrintBinaryTree(root->m_pRight);
}

//先序递归镜像二叉树
/*****************************************************************
	Author： mushroom
	note：求一个二叉树的镜像的主要解题思路是，求一颗二叉树的镜像
	，其实就是交换二叉树非叶子节点的左右两个节点，但是这么做之后，
	虽然该节点的左右两个节点交换了，但是左右节点下的子树的结点还是没有交换
	，所以这里我采用先序递归遍历的方式，在遍历的同时交换结点的左右子树，
	之后依次镜像结点的左子树，和右子树。
	首先判断该节点是不是叶子节点，如果是叶子节点则不需要镜像，如果不是先交换该节点的左右节点
	，之后递归镜像该节点的左子树和右子树。
*****************************************************************/
void MirrorBinaryTree(BinaryTreeNode* root)
{
	if(root==NULL)//如果根节点为空，直接返回
		return;
	if(root->m_pleft==NULL&&root->m_pRight==NULL) //如果当前节点是叶子节点，直接返回
		return;
	//如果当前结点不是叶子节点，就交换它的左右子结点
	BinaryTreeNode* pTemp=root->m_pleft;
	root->m_pleft=root->m_pRight;
	root->m_pRight=pTemp;
	//镜像该节点的左子树
	//if(root->m_pleft)
	MirrorBinaryTree(root->m_pleft);
	//镜像该结点的右子树
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