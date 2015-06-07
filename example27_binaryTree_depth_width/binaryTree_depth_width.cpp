// �����������ȺͿ��.cpp : �������̨Ӧ�ó������ڵ㡣    
#include <iostream>  
#include <queue>  
using namespace std;  

struct BTNode  
{  
	char m_value;  
	BTNode *m_left;  
	BTNode *m_right;  
};  

//���򴴽�������  
void CreatBTree(BTNode *&root)  
{     
	char nValue = 0;  
	cin >> nValue;  
	if ('#' == nValue)  
	{  
		return;  
	}  
	else  
	{  
		root = new BTNode();  
		root->m_value = nValue;  
		CreatBTree(root->m_left);  
		CreatBTree(root->m_right);  
	}     
}  

//������������  
int GetDepth(BTNode *pRoot)  
{  
	if (pRoot == NULL)  
	{  
		return 0;  
	}  

	//  int nLeftLength = GetDepth(pRoot->m_left);  
	//  int nRigthLength = GetDepth(pRoot->m_right);  
	//  return nLeftLength > nRigthLength ? (nLeftLength + 1) : (nRigthLength + 1);  

	return GetDepth(pRoot->m_left) > GetDepth(pRoot->m_right) ?   
		(GetDepth(pRoot->m_left) + 1) : (GetDepth(pRoot->m_right) + 1);  
}  

//��������Ŀ��  
int GetWidth(BTNode *pRoot)  
{  
	if (pRoot == NULL)  
	{  
		return 0;  
	}  

	int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��  
	int nWidth = 1;//�������Ŀ��  
	queue<BTNode *> myQueue;  
	myQueue.push(pRoot);//�����ڵ������  
	nCurLevelWidth = 1;      
	BTNode *pCur = NULL;  

	while (!myQueue.empty())//���в���  
	{  
		while (nCurLevelWidth != 0)  
		{  
			pCur = myQueue.front();//ȡ������ͷԪ��  
			myQueue.pop();//������ͷԪ�س���  

			if (pCur->m_left != NULL)  
			{  
				myQueue.push(pCur->m_left);  
			}  

			if (pCur->m_right != NULL)  
			{  
				myQueue.push(pCur->m_right);  
			}  

			nCurLevelWidth--;  
		}  

		nCurLevelWidth = myQueue.size();  
		nWidth = nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth;   
	}  
	return nWidth; 
}
int main(int argc, char** argv)  
{  
	BTNode *pRoot = NULL;     
	CreatBTree(pRoot);  
	cout << "�����������Ϊ��" << GetDepth(pRoot) << endl;  
	cout << "�������Ŀ��Ϊ��" << GetWidth(pRoot) << endl;      
	system("pause");  
	return 0;  
}  