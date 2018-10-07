#include<iostream>
#include<vector>
using namespace std;


vector<int> beCatched;

void BinaryInsert(int n)
{
	int l = 0, r = beCatched.size();
	if (beCatched.empty() || beCatched.back() >= n)
	{
		beCatched.push_back(n);
		return;
	}
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (beCatched[mid] < n)
			r = mid;
		else
			l = mid + 1;
	}
	beCatched[l] = n;
	return;
}

int main()
{
	int k, missile;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> missile;
		BinaryInsert(missile);
	}
	cout << beCatched.size() << endl;
}