/*
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
* 
* Example 1:
*	Input: strs = ["flower","flow","flight"]
*	Output: "fl"
* 
* Example 2:
*	Input: strs = ["dog","racecar","car"]
*	Output: ""
*	Explanation: There is no common prefix among the input strings.
* 
* Constraints:
*	1 <= strs.length <= 200
*	0 <= strs[i].length <= 200
*	strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();

        if (size == 1)    return strs[0];
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[size - 1];
        string ans = "";

        int firstLength = first.length();
        for (int i = 0; i < firstLength; i++)
        {
            if (first[i] == last[i])
            {
                ans += first[i];
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 9.2 MB (54.9%)
*/