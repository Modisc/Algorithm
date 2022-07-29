// 입력으로 주어지는 그래프의 첫번째 노드에서 마지막 노드까지 가는 모든 경로 찾기
// DFS 알고리즘
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