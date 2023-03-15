/*
* Given a string s, return the longest palindromic substring in s.
* 
* Example 1:
*	Input: s = "babad"
*	Output: "bab"
*	Explanation: "aba" is also a valid answer.
* 
* Example 2:
*	Input: s = "cbbd"
*	Output: "bb"
* 
* Constraints:
*	1 <= s.length <= 1000
*	s consist of only digits and English letters.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1)  return "";
        int start = 0, end = 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            int len1 = GetPalindromicLen(s, i, i, length);
            int len2 = GetPalindromicLen(s, i, i + 1, length);
            int len = max(len1, len2);

            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    int GetPalindromicLen(string s, int left, int right, int length)
    {
        int L = left, R = right;
        while (L >= 0 && R < length && s[L] == s[R])
        {
            L--;
            R++;
        }

        return R - L - 1;
    }
};

/*
* Result
* Time: 55 ms (56.89%), Space: 159.6 MB (21.59%)
*/