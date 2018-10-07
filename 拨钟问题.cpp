#include<iostream>
using namespace std;
int init_clocks[10], clocks[10];
int op[10], ans[10];
void move(int i, int op_num)
{
	clocks[i] = (init_clocks[i] + op_num) % 4;
	return;
}
bool check()
{
	for (int i = 0; i <= 9; ++i)
		if (clocks[i])
			return false;
	return true;
}
void output_ans()
{
	bool start = true;
	for (int i = 1; i <= 9; ++i)
	{
		while (ans[i])
		{
			if (start)
				start = false;
			else
				cout << ' ';
			cout << i;
			--ans[i];
		}
	}
	cout << endl;
	return;
}
int main()
{
	int sum = 40;
	for (int i = 1; i <= 9; ++i)
	{
		cin >> init_clocks[i];
	}
	for (op[1] = 0; op[1] < 4; ++op[1])
		for (op[2] = 0; op[2] < 4; ++op[2])
			for (op[3] = 0; op[3] < 4; ++op[3])
				for (op[4] = 0; op[4] < 4; ++op[4])
					for (op[5] = 0; op[5] < 4; ++op[5])
						for (op[6] = 0; op[6] < 4; ++op[6])
							for (op[7] = 0; op[7] < 4; ++op[7])
								for (op[8] = 0; op[8] < 4; ++op[8])
									for (op[9] = 0; op[9] < 4; ++op[9])
									{
										move(1, op[1] + op[2] + op[4]);
										move(2, op[1] + op[2] + op[3] + op[5]);
										move(3, op[2] + op[3] + op[6]);
										move(4, op[1] + op[4] + op[5] + op[7]);
										move(5, op[1] + op[3] + op[5] + op[7] + op[9]);
										move(6, op[3] + op[5] + op[6] + op[9]);
										move(7, op[4] + op[7] + op[8]);
										move(8, op[5] + op[7] + op[8] + op[9]);
										move(9, op[6] + op[8] + op[9]);
										if (check())
										{
											int s = 0;
											for (int i = 1; i <= 9; ++i)
												s += op[i];
											if (s < sum)
											{
												for (int i = 1; i <= 9; ++i)
													ans[i] = op[i];
												sum = s;
											}
										}
									}
	output_ans();
	return 0;
}