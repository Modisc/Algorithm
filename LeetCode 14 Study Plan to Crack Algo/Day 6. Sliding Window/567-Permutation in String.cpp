/*
* Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
* In other words, return true if one of s1's permutations is the substring of s2.
* 
* Example 1:
*	Input: s1 = "ab", s2 = "eidbaooo"
*	Output: true
*	Explanation: s2 contains one permutation of s1 ("ba").
*
* Example 2:
*	Input: s1 = "ab", s2 = "eidboaoo"
*	Output: false
*
* Constraints:
*	1 <= s1.length, s2.length <= 10^4
*	s1 and s2 consist of lowercase English letters.
*/

class Solution {
public:
    bool IsDuplication(const char(&s1)[26], const char(&s2)[26], const int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (s1[i] != s2[i])  return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        char mapS1[26] = { 0, };
        char mapS2[26] = { 0, };
        int left = 0, right = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            mapS1[s1[i] - 'a']++;
        }

        while (right < s2.length())
        {
            mapS2[s2[right] - 'a']++;

            if (right - left + 1 == s1.length())
            {
                if (IsDuplication(mapS1, mapS2, 26)) return true;
            }

            if (right - left + 1 < s1.length())
            {
                right++;
            }
            else
            {
                mapS2[s2[left] - 'a']--;
                left++;
                right++;
            }
        }

        return false;
    }
};

/*
* Result
* Time: 6 ms (84.98%), Space: 7.2 MB (93.28%)
*/