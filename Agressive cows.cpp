#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool check(int barns[], int distance, int n, int c)
{
	int pos = barns[0];
	--c;
	for (int i = 1; i<n; ++i)
	{
		if (!c)
			break;
		if (barns[i] - pos >= distance)
		{
			pos = barns[i];
			--c;
		}
	}
	return !c;
}

int main()
{
	int n, c;
	cin >> n >> c;
	int* barns = new int[n];
	for (int i = 0; i<n; ++i)
		cin >> barns[i];
	sort(barns, barns + n - 1);
	int min_d = 1, max_d = (barns[n - 1] - barns[0]) / (c - 1), mid, ans;
	while (min_d <= max_d)
	{
		mid = min_d + (max_d - min_d) / 2;
		if (check(barns, mid, n, c))
		{
			ans = mid;
			min_d = mid + 1;
		}
		else
		{
			max_d = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}