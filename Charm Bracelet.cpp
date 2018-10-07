#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> weight(n), desirability(n);
	for (int i = 0; i < n; ++i)
		cin >> weight[i] >> desirability[i];
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = m; j >= 0; --j)
		{
			if (j >= weight[i])
				dp[j] = max(dp[j], dp[j - weight[i]] + desirability[i]);
		}
	}
	cout << dp[m] << endl;
	return 0;
}