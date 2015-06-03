//旋转数组的最小数字
#include<iostream>
using namespace std;
int MinArrayNum(int array[],int len)
{
	int n=sizeof(array)/sizeof(int);
	if(array==NULL || len<=0)
		throw exception("非法输入");
	int low,high;
	low=0;
	high=len-1;
	while(low<high)
	{
		//如果数组首个元素小于最后一个元素。则表明数组已经有序
		if(array[low]<array[high])
			return low;
		//如果指针low和high相邻时，返回high指针就是数组最小元素的下标
		if(1==(high-low))
			return high;

		int mid=low+(high-low)/2;
		if(array[mid]==array[low]&&array[mid]==array[high])
		{
			//如果数组的开始和结尾元素和中间元素值大小相等，则不能判别最小元素在中间元素的哪一侧，只能采用顺序查找
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
			//如果中间元素大于首个开始元素，说明中间元素位于前半段，则最小元素应该在中间元素的右侧
			low=mid;
		}
		else if(array[mid]<array[high])
		{
			//如果中间元素大于末尾元素，则说明中间元素在后半段，则最小元素应该在中间元素的左侧
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
	cout<<"旋转数组的最小元素的数组下标为： "<<index<<endl;
	cout<<"旋转数组的最小元素的数组值为："<<array[index]<<endl;
	system("pause");
	return 1;
}
/*#include<iostream>
using namespace std;

int min(int arry[],int len)//返回最小数的坐标
{
	if(arry==NULL||len<=0)
		return -1;

	int start=0;
	int end=len-1;
	while(start<end)
	{
		//如果首个元素小于最后一个元素，表明数组是排序的。
		if(arry[start]<arry[end])
			return start;

		//当start指针和end指针隔壁的时候，返回end指针就是最小元素的坐标
		if(end-start==1)
			return end;
		int mid=(start+end)/2;
		//如果arry[mid],arry[start]和arry[end]三个数相等，就只能使用顺序查找
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

		//如果中间元素小于末尾元素，那么表明中间元素在后半段数组中，修改end指针
		if(arry[mid]<arry[end])
		{
			end=mid;
		}
		//如果中间元素大于首元素，那么表明中间元素在前半段数组中，修改start指针
		else if(arry[mid]>arry[start])
		{
			start=mid;
		}
	}
	return -1;
}

int minNum(int arry[],int len)//返回最小数的值
{
	if(arry==NULL||len<=0)
		throw exception("非法输入");

	int start=0;
	int end=len-1;
	while(arry[start]>=arry[end])
	{
		if(end-start==1)//如果start和end相差1则返回arry[end]
			return arry[end];

		int mid=(start+end)/2;
		//如果arry[mid],arry[start]和arry[end]三个数相等，就只能使用顺序查找
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

		if(arry[mid]>=arry[start])//如果中间元素大于首元素，则移动首指针
		{
			start=mid;
		}
		else if(arry[mid]<=arry[end])
		{
			end=mid;
		}
	}
	return arry[start];//如果一开始arry[start]<arry[end]表明数组是排序数组，返回arry[start]
}

void main()
{
	//int arry[]={1,0,1,1,1};
	int arry[]={3,4,5,1,2};
	int len=sizeof(arry)/sizeof(int);

	int index=min(arry,len);
	int minnum=minNum(arry,len);

	cout<<"最小数在数组中的位置："<<index<<endl;
	cout<<"最小数的值："<<minnum<<endl;

	system("pause");
}
*/