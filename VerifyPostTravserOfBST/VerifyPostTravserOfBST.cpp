#include<iostream>
using namespace std;

bool VerifyPostTravserOfBST(int*squence,int len)
{
	if(squence==NULL||len<=0)
		return false;

	int root=squence[len-1];
	//在二叉搜索树中左子树的结点小于根节点
	int i=0;
	for(;i<len-1;i++)//是小于len-1,而不是len
	{
		if(squence[i]>root)//找到左右子树的边界
			break;
	}
	//找到边界之后，判断边界对应根节点的右子树中是否有元素小于跟元素，
	//如果有，则该序列一定不是二叉搜索树的后序遍历序列，可以直接返回false
	int j=i;
	for(;j<len-1;j++)
	{
		if(squence[j]<root)
			return false;
	}
	bool left=true;
	//判断左子树是否是二叉搜索树
	if(i>0)
		left=VerifyPostTravserOfBST(squence,i);

	bool right=true;
	//判断左子树是否是二叉搜索树
	if(i<len-1)
		right=VerifyPostTravserOfBST(squence+i,len-1-i);

	return (left&&right);
}

void print(int *squence,int len)
{
	for(int i=0;i<len;i++)
		cout<<squence[i]<<" ";
	cout<<endl;
}
int main(int argc,char**argv)
{
	int squence[]={5,7,6,9,10,11,8};
	//int squence[]={7,4,6,5};
	//int squence[]={3};
	int len=sizeof(squence)/sizeof(int);
	cout<<"要判断是否为二叉搜索树后序遍历的序列是："<<endl;
	print(squence,len);
	bool isPostOrder=false;
	isPostOrder=VerifyPostTravserOfBST(squence,len);
	cout<<"验证的结果是："<<endl;
	if(isPostOrder)
		cout<<"the squence is the post order Travser of BST."<<endl;
	else
		cout<<"the squence not is the post order Travser of BST."<<endl;
	return 0;
}