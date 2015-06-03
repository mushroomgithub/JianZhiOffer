#include<iostream>
#include<stack>
using namespace std;

typedef struct BTreeNode{
	int m_Data;
	struct BTreeNode* m_pLeft;
	struct BTreeNode* m_pRight;
}BTreeNode;
//��ʼ��������
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
//����ݹ����������
void PreOrder(BTreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->m_Data<<"  ";
	PreOrder(root->m_pLeft);
	PreOrder(root->m_pRight);
}
//����ǵݹ����������
void InRecPreOrderBTree(BTreeNode*p)
{
	//����ģ��ջ����
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
	//����ϵͳջ����
	stack<BTreeNode*> stk;
	while(p!=NULL||!stk.empty())
	{
		while(p!=NULL)//�����㲻Ϊ�գ����������ȴ�ӡ�ý�㣬֮����ջ�ýڵ��������
		{
			cout<<p->m_Data<<"  ";
			stk.push(p);
			p=p->m_pLeft;
		}
		//���Ϊ��ʱ����ջ����ջ�ýڵ���������������������Ƿ�Ϊ�ն���ջ���ڶ���whileѭ�������ж���ջ����Ƿ�Ϊ��
		p=stk.top();
		stk.pop();
		p=p->m_pRight;
	}
}
//����ǵݹ����������
void InRecInOrderBTree(BTreeNode*p)
{
	//����ģ��ջ����
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
	//����ϵͳջ����
	stack<BTreeNode*> stk;
	while(p!=NULL||!stk.empty())
	{
		while(p!=NULL)	//�����㲻Ϊ�գ��������������ջ������
		{
			stk.push(p);
			p=p->m_pLeft;
		}
		//���Ϊ��ʱ���ȵ�ջ��֮���ӡ��ջ����ֵ��֮����ջ�ýڵ��������
		p=stk.top();
		stk.pop();
		cout<<p->m_Data<<"  ";
		p=p->m_pRight;
	}
}
//����ǵݹ����������
void InRecPostOrderBTree(BTreeNode *p)
{
	//����ģ��ջ����
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
	//����ϵͳջ����
	stack<BTreeNode*>stk1;	//����һ���ڵ�ջ
	stack<int>stk2;	//����һ����־ջ����־Ϊ0ʱ��ʾ��������������־λ1��ʾ��������������Ϊ0Ҳ��Ϊ1ʱ����ӡ�ڵ�ֵ
	int flag=0;
	while(p!=NULL||!stk1.empty())
	{
		while(p!=NULL)	//�������ʱ�����ջ����ջ����������־ջ��ջ��־0
		{
			stk1.push(p);
			stk2.push(0);
			p=p->m_pLeft;
		}
		//���Ϊ��ʱ���ȷֱ𵯳����ջ�ͱ�־ջ��ջ��Ԫ��
		p=stk1.top();
		flag=stk2.top();
		stk1.pop();
		stk2.pop();
		//�жϱ�־ջ������־�Ƿ�Ϊ0�����Ϊ0��˵����û���ʵ�����������������ʱ��ջ�����������ͬʱ�����ñ�־ջΪ1
		if(flag==0)
		{
			stk1.push(p);
			stk2.push(1);
			p=p->m_pRight;
		}
		//�����ʹ�������������������֮��˵�����ǵ����η��ʵ��ýڵ㣬��ӡ�ýڵ�ֵ��ͬʱ���øýڵ�ΪNULL��ʹ�õڶ�����ò��Ϸ��������ýڵ�
		else
		{
			cout<<p->m_Data<<"  ";
			p=NULL;
		}
	}
}

int main(int argc,char** argv)
{
	cout<<"������������"<<endl;
	BTreeNode* root=CreateBinaryTreeNode();
	cout<<"����ݹ��ӡ��������㣺"<<endl;
	PreOrder(root);
	cout<<endl;
	cout<<"����ǵݹ��ӡ��������㣺"<<endl;
	InRecPreOrderBTree(root);
	cout<<endl;
	cout<<"����ǵݹ��ӡ��������㣺"<<endl;
	InRecInOrderBTree(root);
	cout<<endl;
	cout<<"����ǵݹ��ӡ��������㣺"<<endl;
	InRecPostOrderBTree(root);
	cout<<endl;
	system("pause");
	return 0;
}
