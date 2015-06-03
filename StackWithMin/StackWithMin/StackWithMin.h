#pragma once
#include <iostream>
using namespace std;

class StackWithMin{
public:
	StackWithMin(){

	}
	~StackWithMin(){

	}
	void push(int value);
	void pop();
	const int & Min() const;
public:
	stack<int>m_data;
	stack<int>m_min;
};

void StackWithMin::push(int value)
{
	cout<<"push "<<value<<" in data stack."<<endl;
	m_data.push(value);
	if(m_min.size()==0||value<m_min.top())
	{
		cout<<"push "<<value<<" in min stack."<<endl;
		m_min.push(value);
	}
	else
	{
		cout<<"push "<<m_min.top()<<" in min stack."<<endl;
		m_min.push(m_min.top());
	}
}

void StackWithMin::pop()
{
	if(m_data.size()>0&&m_min.size()>0)
	{
		cout<<m_data.top()<<" pop"<<endl;
		m_data.pop();
		cout<<m_min.top()<<" pop"<<endl;
		m_min.pop();
	}
}

const int & StackWithMin::Min()const
{
	if(m_data.size()>0&&m_min.size()>0)
		return m_min.top();
	else 
		return -1;
}