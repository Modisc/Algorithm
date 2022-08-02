// 주어진 행렬에서 -1은 벽
// 0은 게이트
// INT_MAX 는 빈 공간 일 때 빈 공간에서 가장 가까운 게이트까지 가는
// 최단 경로를 구하시오
// BFS(게이트에서부터 빈 공간으로 진행하며 +1씩 진행)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0)  return;
        int n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == GATE) {
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            int first = q.front().first, second = q.front().second;
            q.pop();
            for (auto dir : DIRECTIONS) {
                int x = first + dir.first;
                int y = second + dir.second;
                if (x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] != EMPTY)  continue;
                rooms[x][y] = rooms[first][second] + 1;
                q.emplace(x, y);
            }
        }
    }
private:
    queue<pair<int, int>> q;
    int EMPTY = INT_MAX;
    int GATE = 0;
    vector<pair<int, int>> DIRECTIONS = { {1,0}, {0,1}, {-1,0}, {0,-1} };
};