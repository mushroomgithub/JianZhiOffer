#include<iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

/**********************************************************************
/*note:	对于此类问题,可以发现如下规律:
/*          首先选取数组
/*
/**************************************************************************/
bool FindKInMatrix(int *matrix,int rows,int columns,int k)
{
	bool found=false;
	if(matrix!=NULL && rows>0 && columns>0)
	{
		int row=0;
		int column=columns-1;
		while(row<rows&&column>=0)
		{
			if(matrix[row*columns+column]==k)
			{
				found=true;
				break;
			}
			else if(matrix[row*columns+column]>k)
				column--;
			else
				row++;
		}
	}
	return found;
}

int main(int argc,char** argv)
{
	int matrix[4][4]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	bool found=FindKInMatrix(*matrix,4,4,7);
	if(found)
		cout<<"查找成功!"<<endl;
	else
		cout<<"查找失败!"<<endl;
	return 1;
}