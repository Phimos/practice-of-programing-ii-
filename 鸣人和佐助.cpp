#include<iostream>
#include<queue>
using namespace std;

char maze[210][210];
int m, n, t;
int steps[210][210][11];
int power[210][210];
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

struct status
{
	int x, y, c;
	status(int x, int y, int c) : x(x), y(y), c(c) {}
	status() {}
};

int main()
{
	cin >> m >> n >> t;
	int sx, sy;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> maze[i][j];
			if (maze[i][j] == '@')
			{
				sx = i;
				sy = j;
			}
			for (int k = 0; k <= t; ++k)
			{
				steps[i][j][k] = -1;
			}
			power[i][j] = -1;
		}
	}
	queue<status> path;
	steps[sx][sy][t] = 0;
	path.push(status(sx, sy, t));
	bool Catch = false;
	while (!path.empty() && !Catch)
	{
		status temp = path.front();
		path.pop();
		int x = temp.x;
		int y = temp.y;
		int chakra = temp.c;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx <= m && ny <= n)
			{
				if (maze[nx][ny] == '*' && chakra > power[nx][ny])
				{
					path.push(status(nx, ny, chakra));
					steps[nx][ny][chakra] = steps[x][y][chakra] + 1;
					power[nx][ny] = chakra;
				}
				else if (maze[nx][ny] == '#' && chakra > (power[nx][ny] + 1))
				{
					path.push(status(nx, ny, chakra - 1));
					steps[nx][ny][chakra - 1] = steps[x][y][chakra] + 1;
					power[nx][ny] = chakra - 1;
				}
				else if (maze[nx][ny] == '+')
				{
					Catch = true;
					cout << steps[x][y][chakra] + 1 << endl;;
					break;
				}
			}
		}
	}
	if (!Catch)
		cout << -1 << endl;
	return 0;
}