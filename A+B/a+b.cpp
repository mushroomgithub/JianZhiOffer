#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string,int> mp;
	mp["zero"]=0;
	mp["one"]=1;
	mp["two"]=2;
	mp["three"]=3;
	mp["four"]=4;
	mp["five"]=5;
	mp["six"]=6;
	mp["seven"]=7;
	mp["eight"]=8;
	mp["nine"]=9;
	string str1,str2;
	int a,b;
	do 
	{
		a=b=0;
		while(cin>>str1&&str1!="+")
			a=a*10+mp[str1];
		while(cin>>str2&&str2!="=")
			b=b*10+mp[str2];
		if((a+b)!=0)
			cout<<a+b<<endl;
	} while ((a+b)!=0);
	return 0;
}