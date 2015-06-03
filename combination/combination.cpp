#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>//随机数生成器，以及随机函数在此头文件中
#include<ctime>//获取当前时间
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
	srand((unsigned int)time(0));//生成一个随机数种子seed
	if(2!=argc)
		cout<<"程序参数数目不正确"<<endl;
	/********************************************************/
	/*向argv[1]指定的文件中写入NUM个随机数据
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
	//从刚才写入的文件中，读出NUM个随机数字
	ifstream inFile(argv[1]);
	cout<<"Now Pls Wait a while..."<<endl;
	while(!inFile.eof())
	{
		inFile>>temp;
		arry.push_back(temp);
	}
	arry.pop_back();//弹出最后一个元素
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