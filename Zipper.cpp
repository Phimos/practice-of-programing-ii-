#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string a, b, goal;
	int la, lb;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> goal;
		la = a.length();
		lb = b.length();
		vector<vector<bool>> CanBeFormed(la + 1, vector<bool>(lb + 1, false));
		CanBeFormed[0][0] = true;

		for (int j = 0; j <= la; ++j)
		{
			for (int k = 0; k <= lb; ++k)
			{
				if ((j > 0 && CanBeFormed[j - 1][k] && a[j - 1] == goal[j + k - 1]) || (k > 0 && CanBeFormed[j][k - 1] && b[k - 1] == goal[j + k - 1]))
					CanBeFormed[j][k] = true;
			}
		}
		cout << "Data set " << i << ": " << (CanBeFormed[la][lb] ? "yes" : "no") << endl;
	}
}