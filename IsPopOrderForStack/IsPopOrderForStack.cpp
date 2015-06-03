#include<iostream>
#include<stack>
using namespace std;
//判断一个序列是否是压栈序列的弹栈序列
bool isPopOrder(int pushOrder[],int popOrder[],int len)
{
	bool isPop=false;
	if(pushOrder==NULL||popOrder==NULL||len<=0)
		return false;
	const int* pPush=pushOrder;
	const int * pPop=popOrder;
	stack<int> stk;
	/*************************************************************
	/*		弹出序列的长度等于数组长度len是循环结束条件，
	/*		当等于len说明弹出序列可能是正确的，
	/*		但是还要判断此时栈是否为空，为空则说明，弹出
	/*		序列确实是正确的，否则不是正确的弹出序列
	***************************************************************/
	while(pPop-popOrder<len)
	{
		/*  一次内层循环是将当前要弹栈的元素如果不在栈顶就将压栈序列入栈，
		直到栈顶元素等于要弹栈元素。何时入栈压栈序列，当开始栈为空时，
		压栈，或者栈不为空，但是此时栈顶元素不等于要弹栈元素时，压栈*/
		while(stk.empty()||stk.top()!=*pPop) 
		{
			/*说明压栈序列全部已经入栈，此时直接结束内层循环，以后再次需要进入该循环时，
			首先判断压栈序列是否已经全部入栈，如果是，直接跳出循环，因为无压栈序列已无元素可压*/
			if(pPush-pushOrder==len)
				break;
			//如果压栈的元素不等于需要弹栈的元素，一直压栈，直到相等为止
			stk.push(*pPush);
			pPush++;
		}
		//一次内层循环之后，如果栈顶元素不等于要弹栈元素，说明弹栈序列不正确，结束外层循环，
		if(stk.top()!=*pPop)
		{
			isPop=false;
			break;
		}
		//如果一次内层循环之后，栈顶元素等于要弹栈元素，则将栈顶元素弹出
		stk.pop();
		pPop++;
	}
	//两层循环之后，如果弹栈序列的所有元素都比较过，且此时栈为空，则说明弹栈序列正确
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