/*
* You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
* Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
* You may assume that you have an infinite number of each kind of coin.
* 
* Example 1:
*	Input: coins = [1,2,5], amount = 11
*	Output: 3
*	Explanation: 11 = 5 + 5 + 1
* 
* Example 2:
*	Input: coins = [2], amount = 3
*	Output: -1
* 
* Example 3:
*	Input: coins = [1], amount = 0
*	Output: 0
* 
* Constraints:
*	1 <= coins.length <= 12
*	1 <= coins[i] <= 2^31 - 1
*	0 <= amount <= 10^4
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxAmount = amount + 1;
        vector<int> dp(maxAmount, maxAmount);
        dp[0] = 0;
        for (int i = 1; i < maxAmount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                // 현재 coins[j]에서 i를 뺀 i-coins[j] 원의 값은
                // 앞에서 이미 만들어뒀기 때문에 쉽게 구할 수 있다.
                // +1을 한 이유는 현재의 coins[j] 도 횟수에 포함시켜야 하기 때문
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == maxAmount ? -1 : dp[amount];
    }
};

/* Brute Force. Time Limit Exceeded
class Solution {
public:
    void backtracking(vector<int>& coins, vector<int>& instance, vector<int>& ans, int amount, int start)
    {
        if(amount == 0)
        {
            ans.push_back(instance.size());
            return;
        }

        if(amount < 0)
            return;

        for(int i = start; i < coins.size(); i++)
        {
            instance.push_back(coins[i]);
            backtracking(coins, instance, ans, amount - coins[i], i);
            instance.pop_back();
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> instance;
        vector<int> ans;

        backtracking(coins, instance, ans, amount, 0);

        int minCount = INT_MAX;
        for(int i = 0; i<ans.size(); i++)
            minCount = (minCount > ans[i])  ?   ans[i] : minCount;

        return (minCount == INT_MAX) ? -1 : minCount;
    }
};*/

/*
* Result
* Time: 113 ms (51.29%), Space: 14.5 MB (62.35%)
*/