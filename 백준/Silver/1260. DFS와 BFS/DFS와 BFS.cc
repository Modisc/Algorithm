#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;

void ResetVisited(vector<bool>& visited)
{
	for (int i = 0; i < N + 1; i++)
	{
		visited[i] = false;
	}
}

void dfs(vector<vector<int>>& map, vector<bool>& visited, int node)
{
	if (visited[node] == true)	return;

	visited[node] = true;

	cout << node << " ";

	for (int i = 1; i <= N; i++)
	{
		if (map[node][i] == 1 && visited[i] == false)
			dfs(map, visited, i);
	}
}

void bfs(vector<vector<int>>& map, vector<bool>& visited, int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();

		cout << tmp << " ";

		for (int i = 1; i <= N; i++)
		{
			if (map[tmp][i] == 1 && visited[i] == false)
			{
				visited[i] = true;
				q.push(i);
			}		
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<bool> visited(N + 1, false);

	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(map, visited, V);

	cout << "\n";

	ResetVisited(visited);
	bfs(map, visited, V);
}