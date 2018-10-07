#include<iostream>
#include<vector>
using namespace std;
struct node
{
	char col;
	int row;
	node(int x, int y) : row(x), col('A' + y) {}
	node() {}
	friend ostream& operator<<(ostream&out, node p)
	{
		out << p.col << p.row;
		return out;
	}
};
int dir[8][2] = { { -1, -2 }, { 1, -2 }, { -2, -1 }, { 2, -1 }, { -2, 1 }, { 2, 1 }, { -1, 2 }, { 1, 2 } };
bool traveled[27][27];
int n, p, q;
vector<node> path;





bool check()
{
	for (int i = 1; i <= p; ++i)
		for (int j = 0; j < q; ++j)
			if (traveled[i][j] == false)
				return false;
	return true;
}
void init()
{
	for (int i = 1; i <= p; ++i)
		for (int j = 0; j < q; ++j)
			traveled[i][j] = false;
	path.clear();
}

bool dfs(int x, int y)
{
	path.push_back(node(x, y));
	traveled[x][y] = true;
	int nx, ny;
	bool all_traveled = true;
	for (int i = 0; i < 8; ++i)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx > 0 && nx <= p && ny >= 0 && ny < q && traveled[nx][ny] == false)
		{
			all_traveled = false;
			if (dfs(nx, ny))
				return true;
		}
	}
	if (all_traveled && check())
		return true;
	else
	{
		path.pop_back();
		traveled[x][y] = false;
		return false;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p >> q;
		init();
		cout << "Scenario #" << i << ':' << endl;
		if (dfs(1, 0))
		{
			for (int i = 0; i < path.size(); ++i)
			{
				cout << path[i];
			}
			cout << endl;
		}
		else
			cout << "impossible" << endl;
		cout << endl;
	}
	return 0;
}