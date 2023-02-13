/*
* Write a function that reverses a string.The input string is given as an array of characters s.
* You must do this by modifying the input array in - place with O(1) extra memory.
* 
* Example 1:
*	Input: s = ["h","e","l","l","o"]
*	Output: ["o","l","l","e","h"]
* 
* Constraints:
*    1 <= s.length <= 105
*    s[i] is a printable ascii character.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;

            ++i;
            --j;
        }
    }
};

/*
* Result
* Time: 16 ms (92.66%), Space: 23.1 MB (80.39%)
*/

