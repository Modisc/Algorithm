/*
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
* A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
* 
* Example 1:
*	Input: digits = "23"
*	Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
* 
* Example 2:
*	Input: digits = ""
*	Output: []
* 
* Example 3:
*	Input: digits = "2"
*	Output: ["a","b","c"]
* 
* Constraints:
*	0 <= digits.length <= 4
*	digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
    map<char, vector<string>> letters_M = { {'2', {"a","b","c"}}, {'3', {"d","e","f"}},
                    {'4', {"g","h","i"}}, {'5', {"j","k","l"}}, {'6', {"m","n","o"}},
                    {'7', {"p","q","r","s"}}, {'8', {"t","u","v"}}, {'9', {"w","x","y","z"}} };

public:
    vector<string> Combine(vector<string> set1, vector<string> set2)
    {
        vector<string> ans;
        for (string s1 : set1)
        {
            for (string s2 : set2)
            {
                ans.push_back(s1 + s2);
            }
        }
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> combinations = letters_M[digits[0]];
        int length = digits.length();
        for (int i = 1; i < length; i++)
            combinations = Combine(combinations, letters_M[digits[i]]);

        return combinations;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 6.9 MB (11.18%)
*/