// �Է����� �־����� �׷����� ù��° ��忡�� ������ ������ ���� ��� ��� ã��
// DFS �˰���
class Solution {
public:

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tmp;
        vector<vector<int>> result;

        dfs(graph, tmp, result, 0, graph.size() - 1);

        return result;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& tmp, vector<vector<int>>& result, int start, int end) {
        tmp.emplace_back(start);

        if (start == end) {
            result.emplace_back(tmp);
        }

        else {
            for (int i = 0; i < graph[start].size(); i++) {
                dfs(graph, tmp, result, graph[start][i], end);
            }
        }
        tmp.pop_back();
    }
};