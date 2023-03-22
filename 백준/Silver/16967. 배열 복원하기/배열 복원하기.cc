#include <iostream>
#include <vector>

using namespace std;
int H, W, X, Y;

void solve(vector<vector<int>>& arr) {
	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			arr[i][j] -= arr[i - X][j - Y];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> H >> W >> X >> Y;
	vector<vector<int>> arr(H + X, (vector<int>(W + Y, 0)));
	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> arr[i][j];
		}
	}
	solve(arr);
	return 0;
}