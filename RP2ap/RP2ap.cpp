#include<iostream>
#include<vector>
using namespace std;

//дһ��������ת�����·��Ϊ����·�������磺/home/abs/../temp/new/../,���·��Ϊ��/home/temp��
int RP2AP(const char* pInStr, char* pOutStr)
{
	if (pInStr==NULL|| pOutStr==NULL) return 0;

	string str = pInStr;
	string strTemp;
	vector<string> vec_str;
	string strOut="";

	int nPos1;
	int nPos2;
	nPos1 = str.find("/", 0);

	if (nPos1<0)
	{
		return -1;
	}

	while(1)
	{
		nPos2 = str.find("/", nPos1+1);
		if (nPos2>nPos1)
		{
			strTemp = str.substr(nPos1, nPos2-nPos1);
			//�������/..���ͷ���vector��
			char *s=(char*)strTemp.c_str();
			if(strcmp("/..",s))
				vec_str.push_back(strTemp);
			else //������һ��
			{
				vec_str.pop_back();
			}
			nPos1 = nPos2;
		}
		else
		{
			break;
		}
	}

	//ѭ����ֵ�ۼ�
	for (int i=0; i<vec_str.size(); i++)
	{
		strOut +=vec_str[i];
	}
	memcpy(pOutStr, strOut.c_str(), strOut.size());
	return 1;
}


int main()    
{    
	int n = 10;       
	//char a[] = "/home/abs/../temp/new/../";
	char a[] = "/home/abs/temp/new/../"; 
	char b[256];
	memset(b, 0, 256);
	int nRet = RP2AP(a, b);
	if (nRet ==1 )
		cout << b << endl;
	system("pause");    
	return 0;    
} 