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
bool DoTree1HaveTree2(BinaryTreeNode* root1,BinaryTreeNode* root2)//判断tree1是否包含子结构tree2
{
	if(NULL==root2)//先判断tree2是否为空，如果为空，表示是子结构
		return true;
	if(NULL==root1)//之后再判断tree1是否为空，如果为空，表示不是子结构
		return false;
	
	if(root1->m_nValue!=root2->m_nValue) //如果tree1和tree2的根节点值不同，则以root1为跟结点的字数和以root2为根节点的字数一定不具有相同的结点
		return false;
	//如果value值相同,依次判断以root1和root2为根的树的左子树和右子树是否具有相同的结点
	return DoTree1HaveTree2(root1->m_pLeft,root2->m_pLeft)&&DoTree1HaveTree2(root1->m_pRight,root2->m_pRight);

}
bool isSubTree(BinaryTreeNode* root1,BinaryTreeNode* root2)
{//假设以root1为根的树是树A，以root2为根的树是树B
	bool isSub=false;
	if(root1!=NULL&&root2!=NULL)//如果两棵树不为空
	{
		if(root1->m_nValue==root2->m_nValue)////首先看树A的某一个结点的值与树B的根节点值是否相同，如果相同,判断以这个结点为根的字数是否含有和树B一样的子树
			isSub=DoTree1HaveTree2(root1,root2);
		if(!isSub)//如果这个结点的值不等于树B根节点的值，则判断这个结点左子树上是否包含此子结构
			isSub=isSubTree(root1->m_pLeft,root2);
		if(!isSub)//如果这个结点的值不等于树B根节点的值，则判断这个结点右子树上是否包含此子结构
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