/*
Problem: 2904. Shortest and Lexicographically Smallest Beautiful String
Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/description/?envType=daily-question&envId=2026-08-26
Difficulty: Medium
Approach: Brute Force Enumeration
Time Complexity: O(n^3 logn)
Note:
    
*/

// BF

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> substrings;

        int n = s.size();
        for (int i=0; i<n; i++){
            string temp = "";
            for (int j=i; j<n; j++){
                temp += s[j];
                substrings.emplace_back(temp);
            }
        }

        sort(substrings.begin(), substrings.end());

        int minLen = INT_MAX;
        string ans = "";

        for (auto& ss : substrings){
            int count = 0;
            for (auto& ch : ss){
                if (ch == '1')
                    count++;
            }
            if (count == k){
                if (ss.size() < minLen){
                    minLen = ss.size();
                    ans = ss;
                }
            }
        }

        return minLen == INT_MAX ? "" : ans;
    }
};