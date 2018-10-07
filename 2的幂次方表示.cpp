#include<iostream>
#include<string>
using namespace std;

string transfer(int k)
{
	if (k == 0)
		return "0";
	string ans = "";
	for (int i = 0; k; k>>=1,++i)
	{
		if (k&1)
		{
			if (ans != "")
				ans = '+' + ans;
			if (i == 1)
				ans = "2" + ans;
			else
				ans = "2(" +transfer(i)+ ')'+ans;
		}
	}
	return ans;
}

int main()
{
	int k;
	cin >> k;
	cout << transfer(k) << endl;
	return 0;
}