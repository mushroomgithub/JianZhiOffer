#include<iostream>
#include <cstdlib>
#include<iomanip>
//改程序bug,适用于字符串中没有重复字符的情况
using namespace std;
void some_func(char**s,int n)
{
	int *hash=new int[256];
	memset(hash,0,256);
	char *temp1,*temp2,*temp3,*temp4;
	for(int i=0;i<n;i++)
	{
		temp1=s[i];
		while(*temp1!='\0')
		{
			hash[*temp1]++;
			temp1++;
		}
		for(int j=i+1;j<n;j++)
		{
			temp2=s[j];
			temp1=s[i];
			if(strlen(temp1)!=strlen(temp2))
				continue;
			while(*temp2!='\0')
			{
				if(hash[*temp1]!=hash[*temp2])
					break;
				else
				{
					temp1++;
					temp2++;
				}
			}
			if(*temp1=='\0')
			{
				temp3=s[i];
				temp4=s[j];
				while(*temp3!='\0')
					cout<<*temp3++;
				cout<<setw(4);
				while(*temp4!='\0')
					cout<<*temp4++;
				cout<<endl;
				delete [] hash;
			}
		}
	}
}
int main(int argc,char**argv)
{
	char*s[6]={"cafe","baidu","duiba","face","thisone","isthone"};
	int nLen=sizeof(s)/sizeof(s[0]);
	some_func(s,nLen);
	system("pause");
	return 0;
}