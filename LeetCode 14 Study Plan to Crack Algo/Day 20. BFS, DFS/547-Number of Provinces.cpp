/*
* There are n cities. Some of them are connected, while some are not.
* If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
* A province is a group of directly or indirectly connected cities and no other cities outside of the group.
* You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
* Return the total number of provinces.
* 
* Example 1:
*	Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
*	Output: 2
* 
* Example 2:
*	Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
*	Output: 3
* 
* Constraints:
*	1 <= n <= 200
*	n == isConnected.length
*	n == isConnected[i].length
*	isConnected[i][j] is 1 or 0.
*	isConnected[i][i] == 1
*	isConnected[i][j] == isConnected[j][i]
*/

class Solution {
public:
    void CheckNum(vector<vector<int>>& isConnected, int row, int col, int size)
    {
        if (row < 0 || col < 0 || row >= size || col >= size)
            return;

        isConnected[row][col] = 0;

        for (int i = 0; i < size; i++)
        {
            if (isConnected[row][i] == 1)
            {
                isConnected[row][i] = 0;

                CheckNum(isConnected, i, row, size);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ans++;
                    isConnected[i][j] = 0;

                    CheckNum(isConnected, j, i, size);
                }
            }
        }

        return ans;
    }
};

/* Union Find 코드 자체는 이해했지만 방식이 너무 어려움. Union Find 자체 공부가 필요.
class Solution {
public:

    vector<int> v;

    int parent(int x)
    {
        if(v[x]==-1) return x;
        return v[x]=parent(v[x]);
    }

    void _union(int a,int b)
    {
        int p_a=parent(a),p_b=parent(b);

        if(p_a==p_b) return;

        v[p_a]=p_b;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        v=vector<int> (n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])
                {
                    _union(i,j);
                }
            }
        }
        int c=0;

        for(int i=0;i<n;i++)
        {
            if(v[i]==-1) c++;
        }
        return c;
    }
};*/

/*
* Result
* Time: 27 ms (60.21%), Space: 13.9 MB (58.48%)
*/