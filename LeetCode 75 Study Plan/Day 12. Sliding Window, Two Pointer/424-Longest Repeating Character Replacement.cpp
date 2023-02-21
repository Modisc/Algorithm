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

// left = 0, right = 0 ���� �ΰ�
// right�� 1�� ������Ű�鼭 map[26] �� ���� map[s[right]]++; �� �Ѵ�.
// ���� �������� ���̿��� �ִ� �ߺ��� ���� ���� ���� ġȯ�ؾ� �ϴ� ������ ���� ���´�.
// ġȯ�ؾ� �ϴ� ������ ���� k���� �۴ٸ� ��� ������ ũ�⸦ �ø��鼭 �����Ѵ�.
// ġȯ�ؾ� �ϴ� ������ ���� k���� ũ�ٸ� left�� �ִ� ���� �ϳ� ���� left�� ������Ų��.
// ������ ���̿� ���� ���� ���̸� ���ؼ� ���� �ִ´�.
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
