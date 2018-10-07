#include<iostream>
#include<string>
#include<vector>
using namespace std;

string str, ans;
void solve(int k)
{
	if (k == str.length())
	{
		cout << ans << endl;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		int j;
		for (j = 0; j < k; ++j)
		{
			if (ans[j] == str[i])
				break;
		}
		if (j == k)
		{
			ans[k] = str[i];
			solve(k + 1);
		}
	}
}
int main()
{
	cin >> str;
	ans.resize(str.length());
	solve(0);
	return 0;
}