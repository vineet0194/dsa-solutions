/*
Problem: 516. Longest Palindromic Subsequence
Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*m)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*m + max(n,m)) [at worst, recursion stack => n+m]

class Solution {
public:
    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        if (i == text1.size() || j == text2.size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2, dp);

        int incI=0, incJ=0;

        incI = solve(i+1, j, text1, text2, dp);

        incJ = solve(i, j+1, text1, text2, dp);

        return dp[i][j] = max(incI, incJ);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, s2, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*m)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i=0; i<n+1; i++){
            dp[i][n] = 0;
            dp[n][i] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (s[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    continue;
                }
                int incI=0, incJ=0;

                incI = dp[i+1][j];
                incJ = dp[i][j+1];

                dp[i][j] = max(incI, incJ);
            }
        }

        return dp[0][0];
    }
};