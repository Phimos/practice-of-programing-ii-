#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check(vector<int>& dollars_spent, int fajo, int m)
{
	int n = dollars_spent.size(), in_one_fajo = 0;
	for (int i = 0; i<n; ++i)
	{
		if (in_one_fajo + dollars_spent[i] <= fajo)
		{
			in_one_fajo += dollars_spent[i];
		}
		else
		{
			--m;
			in_one_fajo = dollars_spent[i];
			if (m <= 0)
				return false;
		}
	}
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> dollars(n);
	int max_dollar = 0, sum_dollar = 0;
	for (int i = 0; i<n; ++i)
	{
		cin >> dollars[i];
		max_dollar = max(dollars[i], max_dollar);
		sum_dollar += dollars[i];
	}
	int min_spent = max_dollar, max_spent = sum_dollar, mid_spent, ans;
	while (min_spent <= max_spent)
	{
		mid_spent = min_spent + (max_spent - min_spent) / 2;
		if (check(dollars, mid_spent, m))
		{
			ans = mid_spent;
			max_spent = mid_spent - 1;
		}
		else
			min_spent = mid_spent + 1;
	}
	cout << ans << endl;
	return 0;
}