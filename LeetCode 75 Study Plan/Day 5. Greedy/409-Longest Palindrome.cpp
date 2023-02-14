/*
* Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
* Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
* 
* Example 1:
*	Input: s = "abccccdd"
*	Output: 7
*	Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
*
* Example 2:
*	Input: s = "a"
*	Output: 1
*	Explanation: The longest palindrome that can be built is "a", whose length is 1.
* 
* Constraints:
*	1 <= s.length <= 2000
*	s consists of lowercase and/or uppercase English letters only.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int result = 0;;
        for (int i = 0; i < s.length(); ++i)
        {
            ++mp[s[i]];
            if (mp[s[i]] % 2 == 0) result += 2;
        }
        for (auto v : mp)
        {
            if (v.second % 2 == 1)
            {
                ++result;
                break;
            }
        }
        return result;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 6.7 MB (20.32%)
*/