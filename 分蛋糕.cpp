#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define Int_Max 0x7fffffff;
int dp[25][25][25];//w,h,m
int w, h, m;

int CutCake(int w, int h, int n) //且n刀
{
	if (dp[w][h][n])
		return dp[w][h][n];
	else
	{
		int ans = Int_Max;
		if (w * h <= n)
		{
			dp[w][h][n] = ans;
			return ans;
		}
		if (n == 0)
		{
			dp[w][h][n] = w * h;
			return w * h;
		}
		for (int i = 1; i <= w / 2; ++i)
			for (int k = 0; k < n; ++k)
				ans = min(ans, max(CutCake(i, h, k), CutCake(w - i, h, n - 1 - k)));
		for (int i = 1; i <= h / 2; ++i)
			for (int k = 0; k < n; ++k)
				ans = min(ans, max(CutCake(w, i, k), CutCake(w, h - i, n - 1 - k)));
		dp[w][h][n] = ans;
		return ans;
	}
}

int main()
{
	for (int i = 0; i < 25; ++i)
		for (int j = 0; j < 25; ++j)
			for (int k = 0; k < 25; ++k)
				dp[i][j][k] = 0;
	while (cin >> w >> h >> m, (w || h || m))
		cout << CutCake(w, h, m - 1) << endl;
	return 0;
}