#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void flip(string & password, int k)
{
	password[k] = (password[k] == '0') ? '1' : '0';
}
int check_and_count(string ori_password, string des_password)
{
	int cnt = 0, len = ori_password.length();
	for (int i = 1; i < len; ++i)
	{
		if (ori_password[i - 1] != des_password[i - 1])
		{
			flip(ori_password, i - 1);
			flip(ori_password, i);
			if (i < len - 1)
				flip(ori_password, i + 1);
			++cnt;
		}
	}
	if (ori_password[len - 1] == des_password[len - 1])
		return cnt;
	else
		return 32;
}
int main()
{
	string ori_password, des_password;
	cin >> ori_password >> des_password;
	int flip_num = 32, cnt = 0;
	flip_num = min(flip_num, check_and_count(ori_password, des_password));
	flip(ori_password, 0);
	if (ori_password.length() > 1)
		flip(ori_password, 1);
	flip_num = min(flip_num, 1 + check_and_count(ori_password, des_password));
	if (flip_num == 32)
		cout << "impossible" << endl;
	else
		cout << flip_num << endl;
	return 0;
}