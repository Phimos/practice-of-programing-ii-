#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct status
{
	int potA, potB;
	status(int a, int b) : potA(a), potB(b) {}
	status() {}
};
void printop(int opNum)
{
	switch (opNum / 2)
	{
	case 0:
		cout << "FILL(" << (opNum & 1) + 1 << ')' << endl;
		break;
	case 1:
		cout << "DROP(" << (opNum & 1) + 1 << ')' << endl;
		break;
	case 2:
		cout << "POUR(" << (opNum & 1) + 1 << ',' << (!(opNum & 1)) + 1 << ')' << endl;
		break;
	default: cout << "Something Wrong" << endl;
	}
}
int steps[104][104];
int lastop[104][104];
status laststatus[104][104];
int A, B, C;

void op(int& pA, int& pB, int opNum)
{
	switch (opNum / 2)
	{
	case 0:
		if (opNum & 1)
			pB = B;
		else
			pA = A;
		return;
	case 1:
		if (opNum & 1)
			pB = 0;
		else
			pA = 0;
		return;
	case 2:
		if (opNum & 1) //B->A
		{
			if (pA + pB <= A)
			{
				pA = pA + pB;
				pB = 0;
			}
			else
			{
				pB = pA + pB - A;
				pA = A;
			}
		}
		else
		{
			if (pA + pB <= B)
			{
				pB = pA + pB;
				pA = 0;
			}
			else
			{
				pA = pA + pB - B;
				pB = B;
			}
		}
		return;
	default:
		cout << "WRONG OP!" << endl;
	}
	return;
}


int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i <= A; ++i)
		for (int j = 0; j <= B; ++j)
			steps[i][j] = -1;
	steps[0][0] = 0;
	queue<status> solution;
	bool impossible = true;
	status start(0, 0);
	status res;
	solution.push(start);
	while (!solution.empty())
	{
		status temp = solution.front();
		solution.pop();
		for (int i = 0; i < 6; ++i)
		{
			int pa = temp.potA;
			int pb = temp.potB;
			op(pa, pb, i);
			if (steps[pa][pb] == -1)
			{
				solution.push(status(pa, pb));
				steps[pa][pb] = steps[temp.potA][temp.potB] + 1;
				lastop[pa][pb] = i;
				laststatus[pa][pb] = temp;
				if (pa == C || pb == C)
				{
					impossible = false;
					res = status(pa, pb);
					goto PRINT_PART;
				}
			}
		}
	}
PRINT_PART:
	if (impossible)
		cout << "impossible" << endl;
	else
	{
		stack<int> ops;
		cout << steps[res.potA][res.potB] << endl;
		while (res.potA != 0 || res.potB != 0)
		{
			int pa = res.potA;
			int pb = res.potB;
			ops.push(lastop[pa][pb]);
			res = laststatus[pa][pb];
		}
		while (!ops.empty())
		{
			printop(ops.top());
			ops.pop();
		}
	}
}