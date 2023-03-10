/*
* You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
* For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
* You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
* Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
* 
* Example 1:
*	Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
*	Output: 2
*	Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
* 
* Example 2:
*	Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
*	Output: -1
* 
* Constraints:
*	1 <= routes.length <= 500.
*	1 <= routes[i].length <= 10^5
*	All the values of routes[i] are unique.
*	sum(routes[i].length) <= 10^5
*	0 <= routes[i][j] < 10^6
*	0 <= source, target < 10^6
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, unordered_set<int>> m;

        // making an adjacency list of  {element --> route in which it is present}
        // 버스 : 버스정류장 관계를 버스정류장 : 버스 관계로 변경해줌.
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                m[routes[i][j]].insert(i);
            }
        }
        // stores current element and no. of buses to reach that element
        // 현재 버스 정류장과 몇번째 이동인지 저장한다.
        queue<pair<int, int>> q;
        q.push({ source,0 });

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int cur_stop = p.first;
            int bus_taken = p.second;
            if (cur_stop == target) // if cur stop is the final stop we return it
                return bus_taken;
            // we go to all the routes in which cur_stop is present
            // 현재 버스정류장에 오는 모든 버스 경로를 확인한다.
            for (int route : m[cur_stop]) {
                for (int r : routes[route]) {
                    if (r != source) {
                        q.push({ r,bus_taken + 1 });
                    }
                }

                routes[route].clear();
            }
        }
        return -1;
    }
};

/*
* Result
* Time: 309 ms (36.43%), Space: 98.9 MB (12.20%)
*/