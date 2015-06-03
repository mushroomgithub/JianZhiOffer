#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n,m=1;
	cin>>n;   //表示输入的测试用例个数
	char s[20];
	while(m<=n&&cin>>s)
	{
		int hash[256]={0};
		for(char ch='a';ch<='z';ch++)	//将小写字母从a~z分别散列到1~26
		{
			hash[ch]=ch-'a'+1;
		}
		int k=0;		//保存输入字符串按题目约束的字符总数。即大写字母算两个字符长度
		int temp=0;	//输入字符串中没有重复字符的对应散列值之和
		for(int i=0;i<strlen(s);i++)  //统计输入字符串按题目约束的字符总数，并将大写字符转化为小写字符
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				int cn=1;
				k+=2*cn;
				s[i]=s[i]+32;
			}
			else k++;
		}
       /**************************************************************************************/
	    /*		将转换为没有大写字母的字符串对应的hash值，存放到set容器中，
		 /*		这样就可以去除重复字符的hash值，便于统计字符串总hash值
		/*************************************************************************************/
		set<int>st;
		set<int>::iterator it;
		for(int j=0;j<strlen(s);j++)
		{
			st.insert(hash[s[j]]);
		}
		for(it=st.begin();it!=st.end();it++)
			temp+=*it;
		cout<<k*k*temp<<endl;
		m++;
	}
	return 0;
}

