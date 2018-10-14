#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class BigNum
{
	vector<int> num;
public:
	BigNum() {}
	BigNum(string s)
	{
		while (!s.empty())
		{
			num.push_back(s.back() - '0');
			s.pop_back();
		}
	}
	BigNum(vector<int> _num)
	{
		num = _num;
		if (num.size() > 1 && num.back() == 0)
			num.pop_back();
	}
	BigNum operator+(BigNum b)
	{
		int la = num.size(), lb = b.num.size();
		int t = 0, sum;
		vector<int> ans;
		for (int i = 0; i < la || i < lb || t; ++i)
		{
			sum = (i < la ? num[i] : 0) + (i < lb ? b.num[i] : 0) + t;
			ans.push_back(sum % 10);
			t = sum / 10;
		}
		return BigNum(ans);
	}
	bool operator < (const BigNum& b)const
	{
		const vector<int>& bnum = b.num;
		int la = num.size();
		int lb = bnum.size();
		if (la != lb)
			return la < lb ? true : false;
		else
		{
			for (int i = la - 1; i >= 0; --i)
			{
				if (num[i] < bnum[i])
					return true;
				else if (num[i] > bnum[i])
					return false;
			}
			return false;
		}
	}
	bool operator == (const BigNum& b)const
	{
		if (!(*this < b) && !(b < *this))
			return true;
		else
			return false;
	}
	friend ostream& operator << (ostream& out, BigNum a)
	{
		int l = a.num.size();
		for (int i = l - 1; i >= 0; --i)
		{
			out << a.num[i];
		}
		out << endl;
		return out;
	}
};

vector<vector<BigNum>> sum;
string nums;

BigNum GetMax(int m, int n)
{
	if (sum[m][n] < BigNum("0")||sum[m][n]==BigNum("0"))
	{
		BigNum MaxSum("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
		for (int k = m; k < n; ++k)
		{
			MaxSum = min(MaxSum, GetMax(m - 1, k) + BigNum(nums.substr(k, n - k)));
		}
		sum[m][n] = MaxSum;
		return MaxSum;
	}
	else
		return sum[m][n];
}

void initSum(int m, int n)
{
	sum.resize(m + 1);
	for (int i = 0; i <= m; ++i)
	{
		sum[i].resize(n + 1);
		for (int j = 0; j <= n; ++j)
			sum[i][j] = BigNum("0");
	}
	for (int j = 1; j <= n; ++j)
	{
		sum[0][j] = BigNum(nums.substr(0, j));
	}
	return;
}

int main()
{
	int m, n;
	while (cin >> m)
	{
		cin >> nums;
		n = nums.size();
		initSum(m, n);
		GetMax(m, n);
		cout << sum[m][n];
	}
}