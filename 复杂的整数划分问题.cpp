#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> cnt;

int kSum(int n, int k)
{
	if (n < 0)
		return 0;
	if (cnt[n][k] != -1)
		return cnt[n][k];
	return kSum(n - k, k) + kSum(n, k - 1);
}

void init(int n)
{
	cnt.resize(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		cnt[i].resize(n + 1);
		for (int j = 0; j <= n; ++j)
			cnt[i][j] = -1;
	}
	for (int i = 2; i <= n; ++i)
		cnt[0][i] = 1;
	for (int i = 0; i <= n; ++i)
		cnt[i][1] = 1;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		init(n);
		cout << kSum(n - k, k) << endl;
		int nDiffSum = 0;
		for (int i = 1; (i * (i + 1)) / 2 <= n; ++i)
		{
			int used = i * (i + 1) / 2;
			nDiffSum += kSum(n - used, i);
		}
		cout << nDiffSum << endl;
		int nOddSum = 0;
		for (int i = 2 - ( n & 1); i <= n; i += 2)
			nOddSum += kSum((n - i) / 2, i);
		cout << nOddSum << endl;
	}
}