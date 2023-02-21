/*
* Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
* An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
* 
* Example 1:
*	Input: s = "cbaebabacd", p = "abc"
*	Output: [0,6]
*	Explanation:
*	The substring with start index = 0 is "cba", which is an anagram of "abc".
*	The substring with start index = 6 is "bac", which is an anagram of "abc".
* 
* Example 2:
*	Input: s = "abab", p = "ab"
*	Output: [0,1,2]
*	Explanation:
*	The substring with start index = 0 is "ab", which is an anagram of "ab".
*	The substring with start index = 1 is "ba", which is an anagram of "ab".
*	The substring with start index = 2 is "ab", which is an anagram of "ab".
* 
* Constraints:
*	1 <= s.length, p.length <= 3 * 104
*	s and p consist of lowercase English letters.
*/

class Solution {
public:
    bool IsDuplicated(const char(&map_s)[26], const char(&map_p)[26], int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (map_s[i] != map_p[i])    return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        char map_s[26] = { 0, };
        char map_p[26] = { 0, };
        int left = 0;
        int right = 0;

        if (s.length() < p.length())     return {};

        for (auto v : p)
        {
            map_p[v - 'a']++;
        }

        while (right < s.length())
        {
            map_s[s[right] - 'a']++;

            if (right - left + 1 == p.length())
            {
                if (IsDuplicated(map_s, map_p, 26))
                {
                    result.push_back(left);
                }
                map_s[s[left] - 'a']--;
                left++;
            }
            right++;

        }

        return result;
    }
};

/*
* Result
* Time: 7 ms (97.70%), Space: 8.7 MB (41.90%)
*/