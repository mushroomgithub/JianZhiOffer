#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	int flag;
};
typedef TreeNode *TreePtr;

TreePtr CreateTree()
{
	TreePtr root =new TreeNode;
	int n;
	cin>>n;
	if(n ==-1)
	{
		return NULL;
	}
	else
	{
		root->data = n;
		root->flag =0;
		root->left = CreateTree();
		root->right = CreateTree();
	}
	return root;
}

void PreOrderRecursion(TreePtr p)
{
	if(p ==NULL)
	{
		return;
	}
	cout<<p->data<<" ";
	PreOrderRecursion(p->left);
	PreOrderRecursion(p->right);
}

void InOrderRecursion(TreePtr p)
{
	if(p ==NULL)
	{
		return;
	}
	InOrderRecursion(p->left);
	cout<<p->data<<" ";
	InOrderRecursion(p->right);
}

void PostOrderRecursion(TreePtr p)
{
	if(p ==NULL)
	{
		return;
	}
	PostOrderRecursion(p->left);
	PostOrderRecursion(p->right);
	cout<<p->data<<" ";
}

void PreOrderNoRecursion(TreePtr p)
{
	cout<<"PreOrderNoRecursion\n";

	stack<TreeNode> stk;
	TreeNode t =*p;
	stk.push(t);
	while(!stk.empty())
	{
		t = stk.top();
		stk.pop();
		cout<<t.data<<" ";
		if(t.right!=NULL)
		{
			stk.push((*t.right));
		}
		if(t.left!=NULL)
		{
			stk.push((*t.left));
		}
	}
}
void InOrderNoRecursion(TreePtr p)
{
	cout<<"InOrderNoRecursion\n";

	stack<TreeNode> stk;
	TreeNode t =*p;
	stk.push(t);
	while(!stk.empty())
	{
		if(stk.top().flag==0)
		{
			stk.top().flag++;
			if(stk.top().left!=NULL)
			{
				stk.push(*(stk.top().left));
			}
		}
		else
		{
			t = stk.top();
			stk.pop();
			cout<<t.data<<" ";
			if(t.right!=NULL)
			{
				stk.push(*(t.right));
			}
		}
	}
}
void PostOrderNoRecursion(TreePtr p)
{
	cout<<"PostOrderNoRecursion\n";

	stack<TreeNode> stk;
	TreeNode t =*p;
	stk.push(t);
	while(!stk.empty())
	{
		if(stk.top().flag==0)
		{
			stk.top().flag++;
			if(stk.top().left!=NULL)
			{
				stk.push(*(stk.top().left));
			}
		}
		else if(stk.top().flag==1)
		{
			stk.top().flag++;
			if(stk.top().right!=NULL)
			{
				stk.push(*(stk.top().right));
			}
		}
		else
		{
			cout<<stk.top().data<<" ";
			stk.pop();
		}
	}
}
int main()
{
	cout<<"input the data :\n";
	TreePtr t = CreateTree();
	cout<<"PreOrderRecursion\n";
	PreOrderRecursion(t);
	cout<<"\n";
	cout<<"InOrderRecursion\n";
	InOrderRecursion(t);
	cout<<"\n";
	cout<<"PostOrderRecursion\n";
	PostOrderRecursion(t);
	cout<<"\n";

	PreOrderNoRecursion(t);
	cout<<"\n";

	InOrderNoRecursion(t);
	cout<<"\n";

	PostOrderNoRecursion(t);
	cout<<"\n";
}