/*
Problem: 115. Distinct Subsequences
Link: https://leetcode.com/problems/distinct-subsequences/description/
Difficulty: Hard
Approach: DP
Time Complexity: O(n*m)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*m + n)

class Solution {
public:
    int n;
    int m;
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if (j == m)
            return 1;

        if (i == n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take=0, skip=0;

        if (s[i] == t[j])
            take = solve(i+1, j+1, s, t, dp);

        skip = solve(i+1, j, s, t, dp);

        return dp[i][j] = take+skip;
    }
    int numDistinct(string s, string t) {
        this->n = s.size();
        this->m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};

// DP Tabulation, O(n*m)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));

        for (int i=0; i<n+1; i++)
            dp[i][m] = 1;
        
        for (int j=0; j<m+1; j++)
            dp[n][j] = 0;
        
        dp[n][m] = 1;

        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (j > i) continue;

                long long take=0, skip=0;

                if (s[i] == t[j])
                    take = dp[i+1][j+1];

                skip = dp[i+1][j];

                dp[i][j] = take + skip;
            }
        }

        return (int) dp[0][0];
    }
};

// Space Optimization, Space Complexity: O(m)

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