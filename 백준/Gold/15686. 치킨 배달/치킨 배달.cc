#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int N, M;
int ans = INT_MAX;
vector<int> map;
vector<pair<int, int>> housePos;
vector<pair<int, int>> chickenPos;
vector<pair<int, int>> chosenPos;
bool selected[13] = { false, };

void InputMap();

int CalcDist(pair<int, int> a, pair<int, int> b);

void GetMinDist();

void Choose(int index, int m);

int main()
{
	InputMap();

	Choose(0, 0);

	cout << ans << "\n";
}

void InputMap()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)	housePos.push_back({ i, j });
			else if (tmp == 2)	chickenPos.push_back({ i, j });
		}
	}
}

void GetMinDist()
{
	int result = 0;
	for (int i = 0; i < housePos.size(); i++) // 모든 집에 대해서
	{
		int minDist = INT_MAX;
		for (int j = 0; j < chosenPos.size(); j++) // 모든 치킨집에 대해서
		{
			minDist = min(minDist, CalcDist(housePos[i], chosenPos[j]));
		}
		result += minDist;
	}

	ans = min(ans, result);
}

void Choose(int index, int m)
{
	if (m == M)
	{
		GetMinDist();
		return;
	}

	for (int i = index; i < chickenPos.size(); i++)
	{
		if (selected[i] == true)	continue;

		selected[i] = true;
		chosenPos.push_back({ chickenPos[i].first, chickenPos[i].second });
		Choose(i, m + 1);
		selected[i] = false;
		chosenPos.pop_back();
	}
}

int CalcDist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
