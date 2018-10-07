#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node
{
	int x, y;
	node(int x, int y) : x(x), y(y) {}
	node() {}
	friend ostream& operator<<(ostream& out, node P)
	{
		out << '(' << P.x << ", " << P.y << ')';
		return out;
	}
};

int main()
{
	int maze[5][5];
	node PreNode[5][5];
	int cnt[5][5];
	int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			cin >> maze[i][j];
			cnt[i][j] = -1;
		}
	queue<node> Nodes;
	Nodes.push(node(0, 0));
	while (!Nodes.empty())
	{
		node temp = Nodes.front();
		Nodes.pop();
		int x = temp.x, y = temp.y;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && maze[nx][ny] == 0)
			{
				Nodes.push(node(nx, ny));
				maze[nx][ny] = 1;
				PreNode[nx][ny] = (node(x, y));
			}
		}
	}
	stack<node> path;
	path.push(node(4, 4));
	while (path.top().x || path.top().y)
	{
		node temp = path.top();
		path.push(PreNode[temp.x][temp.y]);
	}
	while (!path.empty())
	{
		cout << path.top() << endl;
		path.pop();
	}
	return 0;
}