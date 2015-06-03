//��ת�������С����
#include<iostream>
using namespace std;
int MinArrayNum(int array[],int len)
{
	int n=sizeof(array)/sizeof(int);
	if(array==NULL || len<=0)
		throw exception("�Ƿ�����");
	int low,high;
	low=0;
	high=len-1;
	while(low<high)
	{
		//��������׸�Ԫ��С�����һ��Ԫ�ء�����������Ѿ�����
		if(array[low]<array[high])
			return low;
		//���ָ��low��high����ʱ������highָ�����������СԪ�ص��±�
		if(1==(high-low))
			return high;

		int mid=low+(high-low)/2;
		if(array[mid]==array[low]&&array[mid]==array[high])
		{
			//�������Ŀ�ʼ�ͽ�βԪ�غ��м�Ԫ��ֵ��С��ȣ������б���СԪ�����м�Ԫ�ص���һ�ֻ࣬�ܲ���˳�����
				int indexTemp=low;
				for(int j=low+1;j<high;j++)
				{
					if(array[j]<array[indexTemp])
						indexTemp=j;
				}
				return indexTemp;
		}
		if(array[mid]>array[low])
		{
			//����м�Ԫ�ش����׸���ʼԪ�أ�˵���м�Ԫ��λ��ǰ��Σ�����СԪ��Ӧ�����м�Ԫ�ص��Ҳ�
			low=mid;
		}
		else if(array[mid]<array[high])
		{
			//����м�Ԫ�ش���ĩβԪ�أ���˵���м�Ԫ���ں��Σ�����СԪ��Ӧ�����м�Ԫ�ص����
			high=mid;
		}
	}
	return -1;
}

int main(int argc,char** argv)
{
	//int array[]={3,4,5,1,2};
	//int array[]={1,1,1,0,1};
	int array[]={0,1,1,1,1};
	int len=sizeof(array)/sizeof(int);
	int index=MinArrayNum(array,len);
	cout<<"��ת�������СԪ�ص������±�Ϊ�� "<<index<<endl;
	cout<<"��ת�������СԪ�ص�����ֵΪ��"<<array[index]<<endl;
	system("pause");
	return 1;
}
/*#include<iostream>
using namespace std;

int min(int arry[],int len)//������С��������
{
	if(arry==NULL||len<=0)
		return -1;

	int start=0;
	int end=len-1;
	while(start<end)
	{
		//����׸�Ԫ��С�����һ��Ԫ�أ���������������ġ�
		if(arry[start]<arry[end])
			return start;

		//��startָ���endָ����ڵ�ʱ�򣬷���endָ�������СԪ�ص�����
		if(end-start==1)
			return end;
		int mid=(start+end)/2;
		//���arry[mid],arry[start]��arry[end]��������ȣ���ֻ��ʹ��˳�����
		if(arry[mid]==arry[start]&&arry[mid]==arry[end])
		{
			int index=start;
			for(int i=start+1;i<=end;i++)
			{
				if(arry[i]<arry[index])
					index=i;
			}
			return index;
		}

		//����м�Ԫ��С��ĩβԪ�أ���ô�����м�Ԫ���ں��������У��޸�endָ��
		if(arry[mid]<arry[end])
		{
			end=mid;
		}
		//����м�Ԫ�ش�����Ԫ�أ���ô�����м�Ԫ����ǰ��������У��޸�startָ��
		else if(arry[mid]>arry[start])
		{
			start=mid;
		}
	}
	return -1;
}

int minNum(int arry[],int len)//������С����ֵ
{
	if(arry==NULL||len<=0)
		throw exception("�Ƿ�����");

	int start=0;
	int end=len-1;
	while(arry[start]>=arry[end])
	{
		if(end-start==1)//���start��end���1�򷵻�arry[end]
			return arry[end];

		int mid=(start+end)/2;
		//���arry[mid],arry[start]��arry[end]��������ȣ���ֻ��ʹ��˳�����
		if(arry[mid]==arry[start]&&arry[mid]==arry[end])
		{
			int result=arry[start];
			for(int i=start+1;i<=end;i++)
			{
				if(arry[i]<result)
					result=arry[i];
			}
			return result;
		}

		if(arry[mid]>=arry[start])//����м�Ԫ�ش�����Ԫ�أ����ƶ���ָ��
		{
			start=mid;
		}
		else if(arry[mid]<=arry[end])
		{
			end=mid;
		}
	}
	return arry[start];//���һ��ʼarry[start]<arry[end]�����������������飬����arry[start]
}

void main()
{
	//int arry[]={1,0,1,1,1};
	int arry[]={3,4,5,1,2};
	int len=sizeof(arry)/sizeof(int);

	int index=min(arry,len);
	int minnum=minNum(arry,len);

	cout<<"��С���������е�λ�ã�"<<index<<endl;
	cout<<"��С����ֵ��"<<minnum<<endl;

	system("pause");
}
*/