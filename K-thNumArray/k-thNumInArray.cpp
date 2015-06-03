/*#include<iostream>
using namespace std;
//查找一个数组中最小k个数
void AdjustHeap(int* const arr, const int length){
	for(int i = length / 2 - 1; i >= 0; i--){
		int temp = arr[i];
		int k = 0;
		for(int j = i * 2 + 1; j < length; j = k * 2 + 1){
			k = j;
			if(j + 1 < length)
				k = arr[j] > arr[j + 1] ? j : j + 1;

			if(arr[k] > arr[i]){
				arr[(j - 1) / 2] = arr[k];
				arr[k] = temp;
			}
			else 
				break;
		}
	}
}

int* GetKMin(int* const arr, const int length, const int K){
	if(K <= 0)
		return NULL;
	int* KMin = new int[K];
	for(int i = 0; i < length; i++){
		if(i <= K)
			KMin[i] = arr[i];
		if(i == K)
			AdjustHeap(KMin, K);
		if(i > K)
			if(arr[i] < KMin[0]){
				KMin[0] = arr[i];
				AdjustHeap(KMin, K);
			}
	}
	return KMin;
}


int main(){
	const int K = 5;
	const int B = 10;

	static int TestBase[B] = {6, 2, 20, 13, 9, 11, 7, 5, 1, 8};
	static int TestBase2[B] = {6, 2, 20, 13, 9, 11, 7, 5, 1, 6};
	int i = 0;
	for(i = 0; i < B; i++)
		cout << TestBase[i] << "  ";

	cout <<endl;
	int * KMin = GetKMin(TestBase, B, K);
	if(KMin)
		for(i = 0; i < K && i < B; i++)	
			cout << KMin[i] << "  ";

	cout << endl;
	return 0;
}
*/

//求一个无序数组的第k小的数字
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &p, int &q)
{
	int t;
	t = p;
	p = q;
	q = t;
}

int findNumberK(vector<int> &vec, int k, int s, int e)
{
	int roll = vec[s], be = 0, j = s;
	for(int i = s+1 ; i<= e ; i++)
	{
		if(vec[i] < roll)
		{
			j++;
			swap(vec[i], vec[j]);
			be++;
		}
	}

	swap(vec[s], vec[j]);

	if(be == k -1 )
		return roll;
	else if (be < k - 1)
	{
		return findNumberK(vec, k - be - 1, j + 1, e);
	}
	else
		return findNumberK(vec, k, s, j - 1);
}

int main()
{
	vector<int> a;
	int temp, k;

	cout << "input data:" << endl;
	cin >> temp;

	while(temp != -1)
	{
		a.push_back(temp);
		cin >> temp;
	}

	cout << "input K: " << endl;

	cin >> k;

	int result= findNumberK(a , k, 0 ,a.size() - 1);

	cout << "The "<<k<<" min Number of array is："  << result<< endl;
	return 0;
}