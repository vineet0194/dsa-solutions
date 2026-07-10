/*
Problem: 583. Delete Operation for Two Strings
Link: https://leetcode.com/problems/delete-operation-for-two-strings/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*m)
Note:
        n = word1.size()
        m = word2.size()
*/

// Recursive Memoization, Space Complexity: O(n*m + n+m)

class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if (i==word1.size() && j==word2.size())
            return 0;

        if (i==word1.size())            // word1 depleted
            return word2.size() - j;
        
        if (j==word2.size())            // word2 depleted
            return word1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i+1, j+1, word1, word2, dp);

        int delW1 = 1 + solve(i+1, j, word1, word2, dp);
        int delW2 = 1 + solve(i, j+1, word1, word2, dp);

        return dp[i][j] = min(delW1, delW2);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1, vector<int>(word2.size()+1, -1));
        return solve(0, 0, word1, word2, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*m)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        dp[n][m] = 0;

        for (int j=0; j<m; j++)
            dp[n][j] = m-j;

        for (int i=0; i<n; i++)
            dp[i][m] = n-i;

        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }
                int delW1 = 1 + dp[i+1][j];
                int delW2 = 1 + dp[i][j+1];

                dp[i][j] = min(delW1, delW2);
            }
        }

        return dp[0][0];
    }
};