// 주어진 행렬에서 Provinces 찾기.
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int count = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }

    void dfs(int startPoint, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[startPoint] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (startPoint == j) {
                continue;
            }
            if (isConnected[startPoint][j] == 1 && visited[j] == false) {
                dfs(j, isConnected, visited);
            }
        }
    }
};