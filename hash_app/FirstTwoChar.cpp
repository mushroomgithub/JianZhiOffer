#include<iostream>
#include <string>
#include<vector>
using namespace std;
int main(int argc,char** argv)
{
	string str="qywyer23tdd";
	int *hash=new int(256);
	for(int j=0;j<str.length();j++)
	{
		hash[str[j]]+=1;
	}
	int i,index;
	for(i=0;i<str.length();i++)
		{
			if(2==hash[str[i]])
				index=i;
		}
	cout<<"the first two char two occur is:"<<str[index]<<endl;
	return 1;
}