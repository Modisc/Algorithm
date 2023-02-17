/*
* Given a string s, find the length of the longest substring without repeating characters.
* 
* Example 1:
*	Input: s = "abcabcbb"
*	Output: 3
*	Explanation: The answer is "abc", with the length of 3.
* 
* Example 2:
*	Input: s = "bbbbb"
*	Output: 1
*	Explanation: The answer is "b", with the length of 1.
*
* Example 3:
*	Input: s = "pwwkew"
*	Output: 3
*	Explanation: The answer is "wke", with the length of 3.
*	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
* Constraints:
*	0 <= s.length <= 5 * 10^4
*	s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map 보단 char map[128] 로 설정하는게
        // 공간을 더 적게 차지함.
        //unordered_map<char, int> map;
        char map[128] = { 0 };

        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length())
        {
            map[s[right]]++;
            while (map[s[right]] > 1)
            {
                map[s[left]]--;
                left++;

            }
            result = max(result, (right - left + 1));
            right++;
        }

        return result;
    }
};

/*
* Result
* Time: 7 ms (92.3%), Space: 7 MB (92.84%)
*/