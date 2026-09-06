/*
Problem: 115. Distinct Subsequences
Link: https://leetcode.com/problems/distinct-subsequences/?envType=daily-question&envId=2026-09-06
Difficulty: Hard
Approach: DP
Time Complexity: O(n*m)
Note:
    
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));

        vector<long long> prev(m+1, -1);
        vector<long long> curr(m+1, -1);

        for (int j=0; j<m+1; j++){
            prev[j] = 0;
            curr[j] = 0;
        }

        prev[m] = 1;
        curr[m] = 1;

        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (j > i) continue;

                long long take=0, skip=0;

                if (s[i] == t[j])
                    take = prev[j+1];

                skip = prev[j];

                curr[j] = take + skip;
            }
            prev = curr;
        }

        return (int) prev[0];
    }
};