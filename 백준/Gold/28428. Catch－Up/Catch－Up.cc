#include "iostream"

using namespace std;

int main()
{
	int sx, sy, mx, my;
	float dm, ds;
	cin >> sx >> sy >> mx >> my;

	dm = static_cast<float>(my) / mx;

	ds = static_cast<float>(sy) / sx;

	if (dm > 1)
	{
		if (ds > 1)	cout << "YES";
		else	cout << "NO";
	}

	else if (dm < 1)
	{
		if (ds < 1)	cout << "YES";
		else	cout << "NO";
	}

	else
	{
		if (ds == 1)	cout << "YES";
		else	cout << "NO";
	}

	return 0;
}
