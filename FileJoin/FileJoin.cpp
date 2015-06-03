#include <iostream>
#include<string>
#include <cctype>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc,char** argv)
{
	string strFileName1="content.txt";
	string strFileName2="words.conf";
	string strTempLine;
	char TempLine[100];
	ifstream inFile;
	ofstream outFile;
	inFile.open(strFileName2);
	outFile.open(strFileName1,ios::app);//以追加的方式打开文件
	if(inFile.is_open())
	{
		//outFile.seekp(0,ios::end);
		while(inFile.getline(TempLine,100))
		{
			strTempLine+=TempLine;
			//strTempLine+="\r\n";
			outFile.write(strTempLine.c_str(),strTempLine.length());
			strTempLine="";
		}
	}
	inFile.close();
	outFile.close();
	cout<<"Pls wait serval sencons..."<<endl;
	return 1;
}