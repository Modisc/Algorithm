/*
* You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
* You can perform this operation at most k times.
* Return the length of the longest substring containing the same letter you can get after performing the above operations.
* 
* Example 1:
*	Input: s = "ABAB", k = 2
*	Output: 4
*	Explanation: Replace the two 'A's with two 'B's or vice versa.
* 
* Example 2:
*	Input: s = "AABABBA", k = 1
*	Output: 4
*	Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
*	The substring "BBBB" has the longest repeating letters, which is 4.
* 
* Constraints:
*	1 <= s.length <= 10^5
*	s consists of only uppercase English letters.
*	0 <= k <= s.length
*/

// left = 0, right = 0 으로 두고
// right를 1씩 증가시키면서 map[26] 에 현재 map[s[right]]++; 을 한다.
// 현재 윈도우의 길이에서 최다 중복의 문자 수를 빼면 치환해야 하는 문자의 수가 나온다.
// 치환해야 하는 문자의 수가 k보다 작다면 계속 윈도우 크기를 늘리면서 진행한다.
// 치환해야 하는 문자의 수가 k보다 크다면 left에 있는 값을 하나 빼고 left를 증가시킨다.
// 윈도우 길이와 현재 최장 길이를 비교해서 답을 넣는다.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int map[26] = { 0, };
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int result = 0;
        int windowSize = 0;

        while (right < s.length())
        {
            map[s[right] - 'A']++;
            maxCount = max(maxCount, map[s[right] - 'A']);
            windowSize = right - left + 1;
            if (windowSize - maxCount > k)
            {
                map[s[left] - 'A']--;
                left++;
            }
            else
            {
                result = max(result, windowSize);
            }
            right++;
        }

        return result;
    }
};

/*
* Result
* Time: 8 ms (82.94%), Space: 6.9 MB (98.69%)
*/
