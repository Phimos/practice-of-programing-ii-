#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#define PI 3.141592653589
using namespace std;

bool check(vector<double>& cakes, int num, double size)
{
	int can_serve = 0, n = cakes.size();
	for (int i = 0; i<n; ++i)
	{
		can_serve += (int)(cakes[i] / size);
		if (can_serve >= num)
			return true;
	}
	return false;
}
int main()
{
	int n, friends;
	cin >> n >> friends;
	vector<double> cakes(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> cakes[i];
		cakes[i] *= cakes[i];
	}
	sort(cakes.begin(), cakes.end());
	double max_size = cakes[n - 1], min_size = 0, mid_size, min_difference = 1e-6;
	while (max_size - min_size >= min_difference)
	{
		mid_size = (min_size + max_size) / 2;
		if (check(cakes, friends + 1, mid_size))
			min_size = mid_size;
		else
			max_size = mid_size;
	}
	cout << fixed << setprecision(3) << min_size * PI << endl;
	return 0;
}