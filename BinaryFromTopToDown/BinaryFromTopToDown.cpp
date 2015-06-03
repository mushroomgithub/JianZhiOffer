#include<iostream>
#include<deque>//双端队列容器
using namespace std;

typedef struct BinaryTreeNode{
	int value;
	struct BinaryTreeNode* m_pLeft;
	struct BinaryTreeNode* m_pRight;
}BinaryTreeNode,*pBinaryTreeNode;

//先序创建二叉树
void CreateBinaryTree(BinaryTreeNode* &pRoot)
{
	int val=0;
	cin>>val;
	if(-1==val)
	{
		return;
	}
	else
	{
		pRoot=new BinaryTreeNode();
		pRoot->value=val;
		CreateBinaryTree(pRoot->m_pLeft);
		CreateBinaryTree(pRoot->m_pRight);
	}
}

//中序打印二叉树
void PrintInOrder(BinaryTreeNode* pRoot)
{
	if(pRoot!=NULL)
	{
		PrintInOrder(pRoot->m_pLeft);
		cout<<pRoot->value<<" ";
		PrintInOrder(pRoot->m_pRight);
	}
}

//自上而下打印二叉树结点
void PrintBinaryFromTopToDown(BinaryTreeNode* pRoot)
{
	if(pRoot==NULL)
		return;

	deque<BinaryTreeNode*>myDeque;
	myDeque.push_back(pRoot);
	while(!myDeque.empty())
	{
		BinaryTreeNode* pTop=myDeque.front();//每次取出双端队列容器中的第一个元素
		cout<<pTop->value<<" ";//打印双端队列容器的第一个元素
		myDeque.pop_front();//从前弹出双端队列容器的第一个元素
		if(pTop->m_pLeft!=NULL)//如果该节点存在左孩子节点
		{
			myDeque.push_back(pTop->m_pLeft);//则将该节点的左孩子节点存入双端队列容器的后面
		}
	     if(pTop->m_pRight!=NULL)//如果该节点存在右孩子节点
		{
			myDeque.push_back(pTop->m_pRight);//则将该节点的右孩子节点存放到双端队列容器的后面
		}
	}
}

int main(int argc,char** argv)
{
	BinaryTreeNode *pRoot=NULL;
	cout<<"创建一个二叉树："<<endl;
	CreateBinaryTree(pRoot);
	cout<<"中序打印创建好的二叉树："<<endl;
	PrintInOrder(pRoot);
	cout<<endl;
	cout<<"自上而下打印二叉树结点："<<endl;
	PrintBinaryFromTopToDown(pRoot);
	cout<<endl;
	system("pause");
	return 1;
}