/*
* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
*		F(0) = 0, F(1) = 1
*		F(n) = F(n - 1) + F(n - 2), for n > 1.
* Given n, calculate F(n).
*
* Example 1:
*	Input: n = 2
*	Output: 1
*	Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
* 
* Example 2:
*	Input: n = 3
*	Output: 2
*	Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
* 
* Example 3:
*	Input: n = 4
*	Output: 3
*	Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
* 
* Constraints:
*	0 <= n <= 30
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0)    return 0;
        if (n == 1)    return 1;

        int curr = -1;
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

/*
class Solution {
public:
    int fib(int n) {
        if(n==0)    return 0;
        if(n==1)    return 1;

        return fib(n-1) + fib(n-2);
    }
};
*/

/*
class Solution {
public:
    int fib(int n) {
        if(n==0)    return 0;
        vector<int> fibonacci((n+1), 0);

        fibonacci[1] = 1;
        for(int i = 2; i<=n; i++)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }

        return fibonacci[n];
    }
};
*/

/*
* Result
* Time: 0 ms (100%), Space: 5.8 MB (93.78%)
*/