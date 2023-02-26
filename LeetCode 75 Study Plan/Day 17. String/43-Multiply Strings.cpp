/*
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
* Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
* 
* Example 1:
*	Input: num1 = "2", num2 = "3"
*	Output: "6"
* 
* Example 2:
*	Input: num1 = "123", num2 = "456"
*	Output: "56088"
* 
* Constraints:
*	1 <= num1.length, num2.length <= 200
*	num1 and num2 consist of digits only.
*	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")    return "0";

        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> sum(size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--)
        {
            for (int j = size2 - 1; j >= 0; j--)
            {
                sum[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                sum[i + j] += sum[i + j + 1] / 10;
                sum[i + j + 1] %= 10;
            }
        }

        int pointer = 0;
        while (pointer < sum.size() && sum[pointer] == 0)
            pointer++;

        string ans = "";
        while (pointer < sum.size())
            ans.push_back(sum[pointer++] + '0');

        return ans;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 6.8 MB (44.93%)
*/