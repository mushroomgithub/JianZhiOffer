#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>//��������������Լ���������ڴ�ͷ�ļ���
#include<ctime>//��ȡ��ǰʱ��
#include <vector>
#include<algorithm>
#define NUM 5
using namespace std;

int main(int argc,char** argv)
{
	vector<int> arry;
	vector<int>out;
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	int temp,i=0;
	srand((unsigned int)time(0));//����һ�����������seed
	if(2!=argc)
		cout<<"���������Ŀ����ȷ"<<endl;
	/********************************************************/
	/*��argv[1]ָ�����ļ���д��NUM���������
	/*********************************************************/
	/*fstream outFile(argv[1]);
	if(outFile.is_open())
	{
		for(int j=1;j<=NUM;j++)
		{
			temp=(1+rand()%NUM);
			outFile<<temp;
			outFile<<" ";
		}
	}*/
	//�Ӹղ�д����ļ��У�����NUM���������
	ifstream inFile(argv[1]);
	cout<<"Now Pls Wait a while..."<<endl;
	while(!inFile.eof())
	{
		inFile>>temp;
		arry.push_back(temp);
	}
	arry.pop_back();//�������һ��Ԫ��
	for(i=0;i<arry.size();i++)
	{
		//cout<<arry[i]<<" ";
		if(arry[i]%3==0)
		{
				temp=arry[i];
				for(it2=arry.begin();it2!=arry.end();it2++)
				{
					int tep;
					tep=temp;
					tep+=*it2;
					out.push_back(tep);
				}
		}
		else
		{
			temp=arry[i]*2;
			out.push_back(temp);
		}
	}
	//sort(out.begin(),out.end());
	for(it1=out.begin();it1!=out.end();it1++)
		cout<<*it1<<" ";
	cout<<endl;
	cout<<"OK!"<<endl;
	system("pause");
	return 1;
}