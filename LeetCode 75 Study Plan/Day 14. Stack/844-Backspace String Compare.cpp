/*
* Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
* Note that after backspacing an empty text, the text will continue empty.
* 
* Example 1:
*	Input: s = "ab#c", t = "ad#c"
*	Output: true
*	Explanation: Both s and t become "ac".
* 
* Example 2:
*	Input: s = "ab##", t = "c#d#"
*	Output: true
*	Explanation: Both s and t become "".
* 
* Example 3:
*	Input: s = "a#c", t = "b"
*	Output: false
*	Explanation: s becomes "c" while t becomes "b".
* 
* Constraints:
*	1 <= s.length, t.length <= 200
*	s and t only contain lowercase letters and '#' characters.
* 
* Follow up: Can you solve it in O(n) time and O(1) space?
*/

// Time : O(n), Space : O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skip_S = 0, skip_T = 0;
        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#') { skip_S++; i--; }
                else if (skip_S > 0) { skip_S--; i--; }
                else break;
            }
            while (j >= 0)
            {
                if (t[j] == '#') { skip_T++; j--; }
                else if (skip_T > 0) { skip_T--; j--; }
                else break;
            }

            if (i >= 0 && j >= 0 && s[i] != t[j])    return false;
            if ((i >= 0) != (j >= 0))  return false;
            i--; j--;
        }
        return true;
    }
};

/* Stack, Time : O(n), Space : O(n)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st_s;
        stack<char> st_t;
        int length_S = s.length();
        int length_T = t.length();

        for(int i = 0; i<length_S; i++)
        {
            if(s[i] != '#')
            {
                st_s.push(s[i]);
            }
            else
            {
                if(st_s.empty())   continue;
                st_s.pop();
            }
        }

        for(int i = 0; i<length_T; i++)
        {
            if(t[i] != '#')
            {
                st_t.push(t[i]);
            }
            else
            {
                if(st_t.empty())   continue;
                st_t.pop();
            }
        }

        if(st_s.size() != st_t.size())  return false;

        while(!st_s.empty())
        {
            if(st_s.top() != st_t.top())    return false;
            st_s.pop();
            st_t.pop();
        }

        return true;
    }
};*/

/*
* Result
* Time: 0 ms (100%), Space: 6.1 MB (91.17%)
*/