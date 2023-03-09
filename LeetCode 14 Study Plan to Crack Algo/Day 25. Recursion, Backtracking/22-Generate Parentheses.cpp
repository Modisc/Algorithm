/*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* Example 1:
*	Input: n = 3
*	Output: ["((()))","(()())","(())()","()(())","()()()"]
* 
* Example 2:
*	Input: n = 1
*	Output: ["()"]
* 
* Constraints:
*	1 <= n <= 8
*/

class Solution {
public:
    void backtracking(vector<string>& ans, string& cur, int open, int close, int max)
    {
        if (cur.length() == max * 2)
        {
            ans.push_back(cur);
            return;
        }

        if (open < max)
        {
            cur.push_back('(');
            backtracking(ans, cur, open + 1, close, max);
            cur.pop_back();
        }
        if (close < open)
        {
            cur.push_back(')');
            backtracking(ans, cur, open, close + 1, max);
            cur.pop_back();
        }
    }



    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtracking(ans, cur, 0, 0, n);

        return ans;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 11.5 MB (84.34%)
*/