#include<iostream>
using namespace std;

/********************************************
/*	����1����ʾ�ַ���1�����ַ���2
/*	����-1����ʾ�ַ���1С���ַ���2
/*	����0����ʾ�ַ���1�����ַ���2
*********************************************/
int compare(char *str1, char *str2, int *hash)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;
	int j = 0;
	while (i < len1&&j < len2)
	{
		if (hash[str1[i]] < hash[str2[j]])	//��ʾstr[i]��ʾ���ַ���str[j]��ʾ�ַ��ĸ�����ĸ����֮ǰ
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
	if (i == len1&&j == len2)	//��ʾ�����ַ�����ĸ������ȫ��ͬ
	{
		return 0;
	}
	else if (i == len1)	//��ʾǰ�벿����ĸ������ͬ�����Ǻ�����ĸ���б�ǰ�߳��ȴ�
	{
		return -1;
	}
	else if (j == len2)	////��ʾǰ�벿����ĸ������ͬ�����Ǻ�����ĸ���б�ǰ�߳��ȶ�
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
	char *h = "dgecfboa";	//�������ַ�����
	int i;
	int j;
	int cnt = 0;
	int len = strlen(h);
	int hash[256];
	while (*h != '\0')
	{
		hash[*h] = cnt++;		//������ĸ��������ǰ��hashֵС
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