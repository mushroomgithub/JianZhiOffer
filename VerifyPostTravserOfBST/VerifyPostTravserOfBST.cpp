#include<iostream>
using namespace std;

bool VerifyPostTravserOfBST(int*squence,int len)
{
	if(squence==NULL||len<=0)
		return false;

	int root=squence[len-1];
	//�ڶ������������������Ľ��С�ڸ��ڵ�
	int i=0;
	for(;i<len-1;i++)//��С��len-1,������len
	{
		if(squence[i]>root)//�ҵ����������ı߽�
			break;
	}
	//�ҵ��߽�֮���жϱ߽��Ӧ���ڵ�����������Ƿ���Ԫ��С�ڸ�Ԫ�أ�
	//����У��������һ�����Ƕ����������ĺ���������У�����ֱ�ӷ���false
	int j=i;
	for(;j<len-1;j++)
	{
		if(squence[j]<root)
			return false;
	}
	bool left=true;
	//�ж��������Ƿ��Ƕ���������
	if(i>0)
		left=VerifyPostTravserOfBST(squence,i);

	bool right=true;
	//�ж��������Ƿ��Ƕ���������
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
	cout<<"Ҫ�ж��Ƿ�Ϊ������������������������ǣ�"<<endl;
	print(squence,len);
	bool isPostOrder=false;
	isPostOrder=VerifyPostTravserOfBST(squence,len);
	cout<<"��֤�Ľ���ǣ�"<<endl;
	if(isPostOrder)
		cout<<"the squence is the post order Travser of BST."<<endl;
	else
		cout<<"the squence not is the post order Travser of BST."<<endl;
	return 0;
}