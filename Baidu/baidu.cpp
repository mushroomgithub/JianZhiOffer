#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n,m=1;
	cin>>n;   //��ʾ����Ĳ�����������
	char s[20];
	while(m<=n&&cin>>s)
	{
		int hash[256]={0};
		for(char ch='a';ch<='z';ch++)	//��Сд��ĸ��a~z�ֱ�ɢ�е�1~26
		{
			hash[ch]=ch-'a'+1;
		}
		int k=0;		//���������ַ�������ĿԼ�����ַ�����������д��ĸ�������ַ�����
		int temp=0;	//�����ַ�����û���ظ��ַ��Ķ�Ӧɢ��ֵ֮��
		for(int i=0;i<strlen(s);i++)  //ͳ�������ַ�������ĿԼ�����ַ�������������д�ַ�ת��ΪСд�ַ�
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
	    /*		��ת��Ϊû�д�д��ĸ���ַ�����Ӧ��hashֵ����ŵ�set�����У�
		 /*		�����Ϳ���ȥ���ظ��ַ���hashֵ������ͳ���ַ�����hashֵ
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

