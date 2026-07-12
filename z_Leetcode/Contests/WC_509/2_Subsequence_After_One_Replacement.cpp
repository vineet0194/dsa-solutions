/*
Problem: Subsequence After One Replacement
Link: https://leetcode.com/contest/weekly-contest-509/problems/subsequence-after-one-replacement/description/
Difficulty: Medium
Approach: Prefix-Suffix Matching
Time Complexity: O(n+m)
Note:
    
*/

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<int> pref(n, -1), suff(n, -1);

        // Prefix matches
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) break;
            pref[i] = j;
            j++;
        }

        // Already a subsequence
        if (pref[n - 1] != -1) return true;

        // Suffix matches
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            suff[i] = j;
            j--;
        }

        // Try replacing each position
        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? -1 : pref[i - 1];
            int right = (i == n - 1) ? m : suff[i + 1];

            if (left == -1 && i != 0) continue;
            if (right == -1 && i != n - 1) continue;

            if (right > left + 1)
                return true;
        }

        return false;
    }
};©leetcode