#include<iostream>
#include<cstdio>
using namespace std;

int n, k, nums[100005];

void UsefulQuickSort(int array[], int start, int end)
{
	if (start >= end)
		return;
	int i = start, j = end;
	while (i < j)
	{
		while (i<j&&array[i] >= array[j])
			--j;
		swap(array[i], array[j]);
		while (i<j&&array[i] >= array[j])
			++i;
		swap(array[i], array[j]);
	}
	UsefulQuickSort(array, start, i - 1);
	if (i<k)
		UsefulQuickSort(array, i + 1, end);
	return;
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; ++i)
		scanf("%d", nums + i);
	scanf("%d", &k);
	UsefulQuickSort(nums, 0, n - 1);
	for (int i = 0; i<k; ++i)
		printf("%d\n", nums[i]);
}