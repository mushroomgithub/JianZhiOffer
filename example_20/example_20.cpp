#include<iostream>
#include<string>
using namespace std;
int main(int argc,const char ** argv){
	string str;
	for(int i=1;i<argc;i++){
		str+=argv[i];
		str+=' ';
	}
	cout<<"executing  "<<str<<endl;
	system(str.c_str());
	return 0;
}