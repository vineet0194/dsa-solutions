/*
Problem: 1081. Smallest Subsequence of Distinct Characters
Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19
Difficulty: Medium
Approach: Monotonic Stack Traversal
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> last(26);
        vector<bool> taken(26, false);

        for (int i=0; i<n; i++)
            last[s[i]-'a'] = i;
        
        string res = "";
        for (int i=0; i<n; i++){
            char ch = s[i]-'a';

            if (taken[ch])  continue;

            else {
                while (res.size() > 0 && res.back()-'a' > ch && last[res.back()-'a'] > i){
                    taken[res.back()-'a'] = false;
                    res.pop_back();
                }
                res.push_back(ch+'a');
                taken[ch] = true;
            }
        }

        return res;
    }
};