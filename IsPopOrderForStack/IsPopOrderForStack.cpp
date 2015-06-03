#include<iostream>
#include<stack>
using namespace std;
//�ж�һ�������Ƿ���ѹջ���еĵ�ջ����
bool isPopOrder(int pushOrder[],int popOrder[],int len)
{
	bool isPop=false;
	if(pushOrder==NULL||popOrder==NULL||len<=0)
		return false;
	const int* pPush=pushOrder;
	const int * pPop=popOrder;
	stack<int> stk;
	/*************************************************************
	/*		�������еĳ��ȵ������鳤��len��ѭ������������
	/*		������len˵���������п�������ȷ�ģ�
	/*		���ǻ�Ҫ�жϴ�ʱջ�Ƿ�Ϊ�գ�Ϊ����˵��������
	/*		����ȷʵ����ȷ�ģ���������ȷ�ĵ�������
	***************************************************************/
	while(pPop-popOrder<len)
	{
		/*  һ���ڲ�ѭ���ǽ���ǰҪ��ջ��Ԫ���������ջ���ͽ�ѹջ������ջ��
		ֱ��ջ��Ԫ�ص���Ҫ��ջԪ�ء���ʱ��ջѹջ���У�����ʼջΪ��ʱ��
		ѹջ������ջ��Ϊ�գ����Ǵ�ʱջ��Ԫ�ز�����Ҫ��ջԪ��ʱ��ѹջ*/
		while(stk.empty()||stk.top()!=*pPop) 
		{
			/*˵��ѹջ����ȫ���Ѿ���ջ����ʱֱ�ӽ����ڲ�ѭ�����Ժ��ٴ���Ҫ�����ѭ��ʱ��
			�����ж�ѹջ�����Ƿ��Ѿ�ȫ����ջ������ǣ�ֱ������ѭ������Ϊ��ѹջ��������Ԫ�ؿ�ѹ*/
			if(pPush-pushOrder==len)
				break;
			//���ѹջ��Ԫ�ز�������Ҫ��ջ��Ԫ�أ�һֱѹջ��ֱ�����Ϊֹ
			stk.push(*pPush);
			pPush++;
		}
		//һ���ڲ�ѭ��֮�����ջ��Ԫ�ز�����Ҫ��ջԪ�أ�˵����ջ���в���ȷ���������ѭ����
		if(stk.top()!=*pPop)
		{
			isPop=false;
			break;
		}
		//���һ���ڲ�ѭ��֮��ջ��Ԫ�ص���Ҫ��ջԪ�أ���ջ��Ԫ�ص���
		stk.pop();
		pPop++;
	}
	//����ѭ��֮�������ջ���е�����Ԫ�ض��ȽϹ����Ҵ�ʱջΪ�գ���˵����ջ������ȷ
	if(stk.empty()&&pPop-popOrder==len)
		isPop=true;

	return isPop;
}
int main(int argc,char**argv)
{
	int pushOrder[]={1,2,3,4,5};
	int len=sizeof(pushOrder)/sizeof(int);
	//int popOrder[]={4,5,3,2,1};
	int popOrder[]={4,3,5,1,2};
	bool isPop=false;
	isPop=isPopOrder(pushOrder,popOrder,len);
	if(isPop)
	{
		cout<<"popOrder is the pushOrder."<<endl;
	}
	else
	{
		cout<<"popOrder is not the pushOrder."<<endl;
	}
	system("pause");
	return 0;
}