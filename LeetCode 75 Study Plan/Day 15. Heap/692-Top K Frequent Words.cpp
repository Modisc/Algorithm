/*
* Given an array of strings words and an integer k, return the k most frequent strings.
* Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
* 
* Example 1:
*	Input: words = ["i","love","leetcode","i","love","coding"], k = 2
*	Output: ["i","love"]
*	Explanation: "i" and "love" are the two most frequent words.
*	Note that "i" comes before "love" due to a lower alphabetical order.
* 
* Example 2:
*	Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
*	Output: ["the","is","sunny","day"]
*	Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
* 
* Constraints:
*	1 <= words.length <= 500
*	1 <= words[i].length <= 10
*	words[i] consists of lowercase English letters.
*	k is in the range [1, The number of unique words[i]]
* 
* Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

class Solution {
public:
    struct Comp
    {
        bool operator()(const pair<string, int> origin, const pair<string, int> newOne)
        {
            if (origin.second == newOne.second)  return origin.first > newOne.first; // 원래는 내림차순 -> pq에선 오름차순
            return origin.second < newOne.second; // 원래는 오름차순 -> pq에선 내림차순
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for (auto x : words)
        {
            um[x]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> pq;

        for (auto x : um)
        {
            pq.push(x);
        }

        vector<string> result;

        while (k--)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;

    }
};

/*
* Result
* Time: 11 ms (83.97%), Space: 12.7 MB (61.65%)
*/