// 주어진 행렬에서 1은 육지, 0은 바다라고 생각하고
// 1로 이루어진 섬이 몇개인지 구하라.
// BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m <= 0)    return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    visited[i][j] = true;
                    q.emplace(i, j);
                    count++;
                    cout << count << endl;
                    while (!q.empty()) {
                        int first = q.front().first, second = q.front().second;
                        q.pop();
                        for (auto dir : DIRECTIONS) {
                            int x = first + dir.first;
                            int y = second + dir.second;
                            if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || grid[x][y] != '1') continue;
                            visited[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return count;
    }
private:
    queue<pair<int, int>> q;
    vector<pair<int, int>> DIRECTIONS = { {1,0}, {0,1}, {-1,0}, {0,-1} };
};