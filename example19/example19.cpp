#include<iostream>
#include<string>
#include<cctype>
#include<deque>
using namespace std;

string decode(string str)
{
	deque<char> dq;
	int count=0;
	string strdq,strTemp;
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			if(i==0)
				dq.push_back(' ');

			for(int j=0;j<dq.size();j++)
				strdq+=dq[j];
			dq.clear();

			count=str[i]-'0';
			while(count--)
				strTemp+=strdq;
			strdq="";
		}
		else
		{
			dq.push_back(str[i]);
		}
	}
	return strTemp;
}

int main(int argc,char** argv)
{
	string str="a20bc3d1";
	//string str="2a4bcd2 3ef3g1";
	string strOut=decode(str);
	cout<<strOut.c_str()<<endl;
	system("pause");
	return 0;
}