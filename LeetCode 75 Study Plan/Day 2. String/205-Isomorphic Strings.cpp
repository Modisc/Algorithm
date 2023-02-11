/*
* Given two strings s and t, determine if they are isomorphic.
* Two strings s and t are isomorphic if the characters in s can be replaced to get t.
* All occurrences of a character must be replaced with another character while preserving the order of characters.
* No two characters may map to the same character, but a character may map to itself.
* 
* Example 1:
*   Input: s = "egg", t = "add"
*   Output: true
* 
* Example 2:   
*    Input: s = "foo", t = "bar"
*    Output: false
*
* Example 3:
*    Input: s = "paper", t = "title"
*    Output: true
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap, tMap;
        for (int i = 0; i < s.length(); ++i)
        {
            if (sMap[s[i]] && sMap[s[i]] != t[i]) return false;
            if (tMap[t[i]] && tMap[t[i]] != s[i]) return false;
            sMap[s[i]] = t[i];
            tMap[t[i]] = s[i];
        }
        return true;
    }
};

/*
* Result
* Time: 11 ms (43.85%), Space: 7.1 MB (47.99%)
*/

/* Constraints를 만족하면서 더 빠르고 좋은 방법
bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
}
* Result
* Time: 7 ms (73.50%), Space: 6.9 MB (92.91%)
*/

