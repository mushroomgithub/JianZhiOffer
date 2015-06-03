#include<iostream>
#include<stack>
using namespace std;

typedef struct BTreeNode{
	int m_Data;
	struct BTreeNode* m_pLeft;
	struct BTreeNode* m_pRight;
}BTreeNode;
//初始化二叉树
BTreeNode* CreateBinaryTreeNode()
{
	BTreeNode* root=new BTreeNode;
	int data;
	cin>>data;
	if(-1==data)
		return NULL;
	else
	{
		root->m_Data=data;
		root->m_pLeft=CreateBinaryTreeNode();
		root->m_pRight=CreateBinaryTreeNode();
	}
	return root;
}
//先序递归遍历二叉树
void PreOrder(BTreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->m_Data<<"  ";
	PreOrder(root->m_pLeft);
	PreOrder(root->m_pRight);
}
//先序非递归遍历二叉树
void InRecPreOrderBTree(BTreeNode*p)
{
	//采用模拟栈方法
	/*BTreeNode* stk[100];
	int top=-1;
	while(p!=NULL||top!=-1)
	{
		while(p!=NULL)
		{
			cout<<p->m_Data<<"  ";
			top++;
			stk[top]=p;
			p=p->m_pLeft;
		}
		p=stk[top];
		top--;
		p=p->m_pRight;
	}*/
	//采用系统栈方法
	stack<BTreeNode*> stk;
	while(p!=NULL||!stk.empty())
	{
		while(p!=NULL)//如果结点不为空，则先序是先打印该结点，之后入栈该节点的左子树
		{
			cout<<p->m_Data<<"  ";
			stk.push(p);
			p=p->m_pLeft;
		}
		//结点为空时，弹栈，入栈该节点的右子树，不论右子树是否为空都入栈，第二层while循环负责判断入栈结点是否为空
		p=stk.top();
		stk.pop();
		p=p->m_pRight;
	}
}
//中序非递归遍历二叉树
void InRecInOrderBTree(BTreeNode*p)
{
	//采用模拟栈方法
	/*BTreeNode* stk[100];
	int top=-1;
	while(p!=NULL||top!=-1)
	{
		while(p!=NULL)
		{
			top++;
			stk[top]=p;
			p=p->m_pLeft;
		}
		p=stk[top];
		top--;
		cout<<p->m_Data<<"  ";
		p=p->m_pRight;
	}*/
	//采用系统栈方法
	stack<BTreeNode*> stk;
	while(p!=NULL||!stk.empty())
	{
		while(p!=NULL)	//如果结点不为空，中序遍历是先入栈左子树
		{
			stk.push(p);
			p=p->m_pLeft;
		}
		//结点为空时，先弹栈，之后打印弹栈结点的值，之后入栈该节点的右子树
		p=stk.top();
		stk.pop();
		cout<<p->m_Data<<"  ";
		p=p->m_pRight;
	}
}
//后序非递归遍历二叉树
void InRecPostOrderBTree(BTreeNode *p)
{
	//采用模拟栈方法
	/*BTreeNode* stk1[100];
	int stk2[100];
	int top=-1;
	int flag=0;
	while (p!=NULL||top!=-1)
	{
		while(p!=NULL)
		{
			top++;
			stk1[top]=p;
			stk2[top]=0;
			p=p->m_pLeft;
		}
		p=stk1[top];
		flag=stk2[top];
		--top;
		if(flag==0)
		{
			top++;
			stk1[top]=p;
			stk2[top]=1;
			p=p->m_pRight;
		}
		else
		{
			cout<<p->m_Data<<"  ";
			p=NULL;
		}
	}*/
	//采用系统栈方法
	stack<BTreeNode*>stk1;	//声明一个节点栈
	stack<int>stk2;	//声明一个标志栈，标志为0时表示访问左子树，标志位1表示访问右子树，不为0也不为1时，打印节点值
	int flag=0;
	while(p!=NULL||!stk1.empty())
	{
		while(p!=NULL)	//后序遍历时，结点栈先入栈左子树，标志栈入栈标志0
		{
			stk1.push(p);
			stk2.push(0);
			p=p->m_pLeft;
		}
		//结点为空时，先分别弹出结点栈和标志栈的栈顶元素
		p=stk1.top();
		flag=stk2.top();
		stk1.pop();
		stk2.pop();
		//判断标志栈弹出标志是否为0，如果为0，说明还没访问弹出结点的右子树，此时入栈结点右子树，同时，设置标志栈为1
		if(flag==0)
		{
			stk1.push(p);
			stk2.push(1);
			p=p->m_pRight;
		}
		//当访问过结点的左子树和右子树之后，说明这是第三次访问到该节点，打印该节点值，同时设置该节点为NULL，使得第二层虚幻不合法，弹出该节点
		else
		{
			cout<<p->m_Data<<"  ";
			p=NULL;
		}
	}
}

int main(int argc,char** argv)
{
	cout<<"创建二叉树："<<endl;
	BTreeNode* root=CreateBinaryTreeNode();
	cout<<"先序递归打印二叉树结点："<<endl;
	PreOrder(root);
	cout<<endl;
	cout<<"先序非递归打印二叉树结点："<<endl;
	InRecPreOrderBTree(root);
	cout<<endl;
	cout<<"中序非递归打印二叉树结点："<<endl;
	InRecInOrderBTree(root);
	cout<<endl;
	cout<<"后序非递归打印二叉树结点："<<endl;
	InRecPostOrderBTree(root);
	cout<<endl;
	system("pause");
	return 0;
}
