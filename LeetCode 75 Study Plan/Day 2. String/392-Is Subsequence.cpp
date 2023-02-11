/*
* Given two strings sand t, return true if s is a subsequence of t, or false otherwise.
* A subsequence of a string is a new string that is formed from the original string by deleting some(can be none) of the characters
* without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
* 
* Example 1:
*	Input: s = "abc", t = "ahbgdc"
*	Output: true
*
* Example 2:
*	Input: s = "axc", t = "ahbgdc"
*	Output: false
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subsequenceCount = 0;
        int sCount = 0;
        for (int i = 0; i < t.length(); ++i)
        {
            if (s[sCount] == t[i])
            {
                ++sCount;
                ++subsequenceCount;
            }
        }

        return (subsequenceCount == s.length());
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 6.4 MB (73.70%)
*/