// ��������� ���������� ��� ã��
// ��� ������ false, �����ϸ� true
// DFS �˰���
class Solution {
public:

    bool checkIfExists(vector<vector<int>>& graph, vector<bool>& visited, int target, int current) {

        if (visited[current] == true) return false;

        if (current == target) return true;

        visited[current] = true;

        for (int i = 0; i < graph[current].size(); i++) {
            if (checkIfExists(graph, visited, target, graph[current][i])) return true;
        }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int& start, int& end) {

        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {

            int first = edges[i][0], second = edges[i][1];

            graph[first].push_back(second);
            graph[second].push_back(first);

        }

        vector<bool> visited(n, false);

        for (int i = 0; i < graph.size(); i++) {
            if (start == i && checkIfExists(graph, visited, end, i)) return true;
        }

        return false;

    }
};