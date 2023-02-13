/*
* Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespaceand initial word order.
* 
* Example 1:
*	Input: s = "Let's take LeetCode contest"
*	Output: "s'teL ekat edoCteeL tsetnoc"
* 
* Constraints:
*    1 <= s.length <= 5 * 104
*    s contains printable ASCII characters.
*    s does not contain any leading or trailing spaces.
*    There is at least one word in s.
*    All the words in s are separated by a single space.
*/

class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        int end = 0;
        for (int start = 0; start < s.size(); start++) {
            if (s[start] != ' ') {
                idx = start;
                end = start;
                while (end < s.size() && s[end] != ' ') s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        return s;
    }
};


/*
* Result
* Time: 7 ms (98.26%), Space: 9.7 MB (50.77%)
*/
