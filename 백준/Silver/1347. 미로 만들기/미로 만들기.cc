#include <iostream>
#include <vector>

using namespace std;

int N;
vector<char> moveRecord;
int xDir[] = {1, -1, 0, 0};
int yDir[] = {0, 0, 1, -1};
int map[101][101] = { 0, };
int sx = 101, sy = 101, lx = 0, ly = 0;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char tmp; cin >> tmp;
		moveRecord.push_back(tmp);
	}
}

int ChangeDirection(char record, int dir)
{
	if (record == 'R')
	{
		switch (dir)
		{
		case 0:
			dir = 2;
			break;
		case 1:
			dir = 3;
			break;
		case 2:
			dir = 1;
			break;
		case 3:
			dir = 0;
			break;
		}
	}
	else
	{
		switch (dir)
		{
		case 0:
			dir = 3;
			break;
		case 1:
			dir = 2;
			break;
		case 2:
			dir = 0;
			break;
		case 3:
			dir = 1;
			break;
		}
	}

	return dir;
}

void SetRange()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1)
			{
				if (i < sy)	sy = i;
				if (i > ly) ly = i;
				if (j < sx)	sx = j;
				if (j > lx)	lx = j;
			}

		}
	}
}

void Output()
{
	for (int i = sy; i <= ly; i++)
	{
		for (int j = sx; j <= lx; j++)
		{
			if (map[i][j] == 1)
				cout << ".";
			else
				cout << "#";
		}

		cout << "\n";
	}
}

void Solve()
{
	int xPosition = 50;
	int yPosition = 50;
	int dir = 2; // 처음 시작시 남쪽방향
	map[yPosition][xPosition] = 1;

	for (int i = 0; i < N; i++)
	{
		if (moveRecord[i] == 'F')
		{
			xPosition += xDir[dir];
			yPosition += yDir[dir];
			map[yPosition][xPosition] = 1;
		}

		else if (moveRecord[i] == 'R' || moveRecord[i] == 'L')
		{
			dir = ChangeDirection(moveRecord[i], dir);
		}
	}

	SetRange();

	Output();
}

int main()
{
	Input();
	Solve();

	return 0;


}