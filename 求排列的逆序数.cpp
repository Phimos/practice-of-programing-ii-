#include<iostream>
#include<cstdio>
using namespace std;

int nums[100005], temp[100005];
long long cnt;

void MergeAndCount(int array[], int start, int mid, int end, int temp[])
{
	int i = start, j = mid+1, k = start;
	while (i<=mid&&j <= end)
	{
		if (array[i]<array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			cnt += (mid - i+1);
			temp[k++] = array[j++];
		}
	}
	if (i <= mid)
		while (i <= mid)
			temp[k++] = array[i++];
	else
		while (j <= end)
			temp[k++] = array[j++];
	for (int i = start; i <= end; ++i)
		array[i] = temp[i];
}

void UsefulMergeSort(int array[], int start, int end, int temp[])
{
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	UsefulMergeSort(array, start, mid , temp);
	UsefulMergeSort(array, mid+1, end, temp);
	MergeAndCount(array, start, mid, end, temp);
}

int main()
{
	int n;
	scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i<n; ++i)
		scanf("%d", nums + i);
	UsefulMergeSort(nums, 0, n - 1, temp);
	cout << cnt << endl;
}