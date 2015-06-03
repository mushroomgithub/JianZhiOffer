#include<iostream>
#include<string>
using namespace std;
int binary_search(int s[],int start,int end,int key)
{
	if(start==end)
	{
		if(s[start]==key)
			return start;
		else 
			return -1;
	}
	int mid=start+(end-start)/2;
	if(s[mid]==key)
		return mid;
	else if(key>s[mid])
		return binary_search(s,mid+1,end,key);
	else
		return binary_search(s,start,mid-1,key);
}
int main(int argc,char** argv)
{
	int L[7]={1,3,4,6,8,9,11};
	int key=9;
	int index=binary_search(L,0,7-1,key);
	if(-1==index)
		cout<<"The search key is not found!"<<endl;
	else
		cout<<"the index of key="<<index<<endl;
	return 1;
}