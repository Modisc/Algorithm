/*
* Given an integer n, return true if it is a power of two. Otherwise, return false.
* An integer n is a power of two, if there exists an integer x such that n == 2x.
*
* Example 1:
*	Input: n = 1
*	Output: true
*	Explanation: 2^0 = 1
* 
* Example 2:
*	Input: n = 16
*	Output: true
*	Explanation: 2^4 = 16
* 
* Example 3:
*	Input: n = 3
*	Output: false
* 
* Constraints:
*	-2^31 <= n <= 2^31 - 1
*
* Follow up: Could you solve it without loops/recursion?
*/

// Bitwise operators
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)    return false;
        return   (n & (-n)) == n; // (n & (n-1)) == 0;
    }
};

/* Loops
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)    return false;
        if(n==1)    return true;
        u_int32_t tmp = 1;
        while(tmp<n)
        {
            tmp<<=1;
            if(tmp == n)    return true;
        }
        return false;
    }
};*/

/*
* Result
* Time: 0 ms (100%), Space: 5.8 MB (84.9%)
*/