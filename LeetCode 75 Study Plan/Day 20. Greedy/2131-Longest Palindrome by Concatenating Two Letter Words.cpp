/*
* You are given an array of strings words. Each element of words consists of two lowercase English letters.
* Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
* Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
* A palindrome is a string that reads the same forward and backward.
* 
* Example 1:
*	Input: words = ["lc","cl","gg"]
*	Output: 6
*	Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
*	Note that "clgglc" is another longest palindrome that can be created.
* 
* Example 2:
*	Input: words = ["ab","ty","yt","lc","cl","ab"]
*	Output: 8
*	Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
*	Note that "lcyttycl" is another longest palindrome that can be created.
* 
* Example 3:
*	Input: words = ["cc","ll","xx"]
*	Output: 2
*	Explanation: One longest palindrome is "cc", of length 2.
*	Note that "ll" is another longest palindrome that can be created, and so is "xx".
* 
* Constraints:
*	1 <= words.length <= 10^5
*	words[i].length == 2
*	words[i] consists of lowercase English letters.
*/

// 2D Counter Array, Time : O(n), Space : O(1) (상수 공간만을 필요로 하므로 O(1) 추정)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int size = words.size();
        vector<vector<int>> count(26, vector<int>(26, 0));
        int first = 0, second = 0;
        int ans = 0;

        for (auto s : words)
        {
            first = s[0] - 'a';
            second = s[1] - 'a';

            if (count[second][first])
            {
                ans += 4;
                count[second][first]--;
            }
            else    count[first][second]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i][i])
            {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};

/* HashMap, Time: O(n), Space: O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        int mid = 0;
        string reverseString = "";
        int ans = 0;

        for(auto s : words)     map[s]++;

        for(auto [s, v] : map)
        {
            reverseString = s;
            reverse(reverseString.begin(), reverseString.end());
            if(map.count(reverseString))
            {
                if(s != reverseString) // words의 원소가 aa, bb 와 같이 앞뒤가 같은 꼴이 아닐 때
                {
                    ans += min(map[s], map[reverseString]);
                }
                else
                {
                    ans += v;
                    if(v & 1) // v가 홀수일 때
                    {
                        mid = 1;
                        ans -= 1;
                    }
                }
            }
        }

        ans += mid;

        return ans * 2;
    }
};*/

/*
* Result
* Time: 288 ms (90.27%), Space: 168.3 MB (20.77%)
*/