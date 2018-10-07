#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

char room[22][22];
int w, h, cnt;
int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
struct node
{
	int x, y;
	node(int x, int y) : x(x), y(y) {}
	node() {}
};

int main()
{
	node StartPoint;
	while (cin >> w >> h, w || h)
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w;  ++j)
			{
				cin >> room[i][j];
				if (room[i][j] == '@')
				{
					StartPoint.x = i;
					StartPoint.y = j;
				}
			}
		}
		cnt = 0;
		queue<node> Nodes;
		Nodes.push(StartPoint);
		node temp;
		while (!Nodes.empty())
		{
			temp = Nodes.front();
			++cnt;
			Nodes.pop();
			int x = temp.x, y = temp.y;
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && room[nx][ny] == '.')
				{
					Nodes.push(node(nx, ny));
					room[nx][ny] = '#';
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}