#include<iostream>
using namespace std;

/********************************************
/*	返回1，表示字符串1大于字符串2
/*	返回-1，表示字符串1小于字符串2
/*	返回0，表示字符串1等于字符串2
*********************************************/
int compare(char *str1, char *str2, int *hash)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;
	int j = 0;
	while (i < len1&&j < len2)
	{
		if (hash[str1[i]] < hash[str2[j]])	//表示str[i]表示的字符在str[j]表示字符的给定字母序列之前
		{
			return 1;
		}
		else if (hash[str1[i]] > hash[str2[j]])
		{
			return -1;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i == len1&&j == len2)	//表示两个字符串字母序列完全相同
	{
		return 0;
	}
	else if (i == len1)	//表示前半部分字母序列相同，但是后者字母序列别前者长度大
	{
		return -1;
	}
	else if (j == len2)	////表示前半部分字母序列相同，但是后者字母序列别前者长度短
	{
		return 1;
	}
}


void print(char **s, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%s ", *(s+i));
	}
}


int main(int argc,char** argv)
{
	char *s[4] = { "bed", "dog", "dear", "eye" };
	char *h = "dgecfboa";	//给定的字符序列
	int i;
	int j;
	int cnt = 0;
	int len = strlen(h);
	int hash[256];
	while (*h != '\0')
	{
		hash[*h] = cnt++;		//给定字母序列中在前的hash值小
		h++;
	}
	for (i = 0; i < 3; i++)
	{
		int max = i;
		for (j = i+1; j < 4; j++)
		{
			if (compare(s[max], s[j], hash) == -1) //s[max]<s[j]
			{
				max = j;
			}
		}
		char *t = s[i];
		s[i] = s[max];
		s[max] = t;
	}
	print(s, 4);
	system("pause");
	return 0;
}