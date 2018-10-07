#include<iostream>
using namespace std;

int solve(int n, int m)//n个单位1最多分为m份
{
	if (m>n)
		return solve(n, n);
	else if (n == 0)
		return 1;
	else if (m == 0)
		return 0;
	return solve(n, m - 1) + solve(n - m, m);
}


int main()
{
	int n;
	while (cin >> n)
		cout << solve(n, n) << endl;
	return 0;
}