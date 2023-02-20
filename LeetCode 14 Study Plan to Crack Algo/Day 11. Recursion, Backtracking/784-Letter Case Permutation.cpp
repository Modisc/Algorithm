/*
* Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
* Return a list of all possible strings we could create. Return the output in any order.
* 
* Example 1:
*	Input: s = "a1b2"
*	Output: ["a1b2","a1B2","A1b2","A1B2"]
* 
* Example 2:
*	Input: s = "3z4"
*	Output: ["3z4","3Z4"]
* 
* Constraints:
*	1 <= s.length <= 12
*	s consists of lowercase English letters, uppercase English letters, and digits.
*/

class Solution {
public:
    void trans(string& s, int i, int n, vector<string>& result)
    {
        if (i == n)
        {
            result.push_back(s);
            return;
        }

        if (isalpha(s[i]))
        {
            s[i] = toupper(s[i]);
            trans(s, i + 1, n, result);
            s[i] = tolower(s[i]);
            trans(s, i + 1, n, result);
        }
        else
        {
            trans(s, i + 1, n, result);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        trans(s, 0, s.size(), result);
        return result;
    }
};

/*
* Result
* Time: 3 ms (96.22%), Space: 9.4 MB (92.6%)
*/