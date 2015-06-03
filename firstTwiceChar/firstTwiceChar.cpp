#include<iostream>
#include <hash_map>
using namespace std;
char Firstoccur2times(char* ch)
{
	char w = '\0';
	if (ch==NULL)
		return w;
	size_t length = strlen(ch);
	hash_map<char, int> hashmap;
	for (int i = 0;i<length;++i)
	{
		hash_map<char, int>::iterator itr=hashmap.find(ch[i]);
		if (itr==hashmap.cend())
			hashmap.insert(make_pair(ch[i], 1));
		else
		{
			w=itr->first;
			break;
		}
	}
	return w;
}
int main(int argc,char** argv)
{
	char s[]="qywyer23tdd";
	char ch=Firstoccur2times(s);
	if(ch!='/0')
		cout << "first char occured 2 times is "<<ch<<endl;
	else
		cout << "no char occured 2 times  "<<endl;
	return 1;
}