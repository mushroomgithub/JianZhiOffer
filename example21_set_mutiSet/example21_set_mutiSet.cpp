#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
	int b[]={10,9,8,7,6,5,4,3,2,1};
	set<int>s(a,a+15);
	multiset<int>ms(a,a+15);
	for(set<int>::iterator iters=s.begin();iters!=s.end();++iters){
		cout<<*iters<<" "; 
	}
	cout<<endl;
	for(multiset<int>::iterator iterm=ms.begin();iterm!=ms.end();++iterm){
		cout<<*iterm<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}