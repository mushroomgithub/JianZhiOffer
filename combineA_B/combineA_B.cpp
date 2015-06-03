#include<iostream>
using namespace std;
void sortA_B(int a[],int b[],int n,int m,int *&C)
{
	int i,j,k;
	int *tempc=new int[m+n];
	i=j=k=0;
	while(i<n&&j<m)
	{
		if(a[i]<=b[j])
		{
			tempc[k++]=a[i];
			i++;
		}
		else
		{
			tempc[k++]=b[j];
			j++;
		}
	}
	while(i<n)
	{
		tempc[k++]=a[i++];
	}
	while(j<m)
	{
		tempc[k++]=b[j++];
	}
	/*for(int i=0;i<k;i++)
		cout<<tempc[i]<<" ";
	cout<<endl;
	*/
	C=tempc;

}

int main(int argc,char** argv)
{
	int A[]={1,3,5,7,9,11,14,15};
	int B[]={2,4,6,8,10};
	int n=sizeof(A)/sizeof(int);
	int m=sizeof(B)/sizeof(int);
	int *C=new int[m+n];
	memset(C,0,m+n);
	sortA_B(A,B,n,m,C);
	for(int i=0;i<(m+n);i++)
		cout<<C[i]<<" ";
	cout<<endl;
	return 0;
}