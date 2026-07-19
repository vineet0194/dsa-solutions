/*
Problem: Transform Binary String Using Subsequence Sort©leetcode
Link: https://leetcode.com/contest/weekly-contest-511/problems/transform-binary-string-using-subsequence-sort/description/
Difficulty: Medium
Approach: Greedy + Prefix Sum
Time Complexity: O(n + m*n)
                n = length of s
                m = length of strs array
Note:
    
*/

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> pref(n);
        int totalOnes = 0;

        for (int i = 0; i < n; i++) {
            totalOnes += (s[i] == '1');
            pref[i] = totalOnes;
        }

        vector<bool> ans;

        for (string &t : strs) {
            int fixedOnes = 0;
            int q = 0;

            for (char c : t) {
                if (c == '1') fixedOnes++;
                else if (c == '?') q++;
            }

            int need = totalOnes - fixedOnes;

            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }

            int cutoff = q - need;      // first 'cutoff' ? -> 0
            int seenQ = 0;
            int prefTarget = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (t[i] == '1') {
                    prefTarget++;
                } else if (t[i] == '?') {
                    seenQ++;
                    if (seenQ > cutoff)
                        prefTarget++;
                }

                if (prefTarget > pref[i]) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};