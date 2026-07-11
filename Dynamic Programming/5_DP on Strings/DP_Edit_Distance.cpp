/*
Problem: 72. Edit Distance
Link: https://leetcode.com/problems/edit-distance/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*m)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*m + n+m)

class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if (j==word2.size())
            return word1.size() - i;

        if (i==word1.size())
            return word2.size() - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i+1, j+1, word1, word2, dp);
        
        int opInsert = solve(i, j+1, word1, word2, dp);
        int opDelete = solve(i+1, j, word1, word2, dp);
        int opReplace = solve(i+1, j+1, word1, word2, dp);

        return dp[i][j] = 1 + min(opInsert, min(opDelete, opReplace));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*m)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for (int i=0; i<n+1; i++)
            dp[i][m] = n - i;

        for (int j=0; j<m+1; j++)
            dp[n][j] = m - j;

        // dp[n][m] = 0;    // redundant here

        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }
                int opInsert = dp[i][j+1];
                int opDelete = dp[i+1][j];
                int opReplace = dp[i+1][j+1];
                
                dp[i][j] = 1 + min(opInsert, min(opDelete, opReplace));
            }
        }

        return dp[0][0];
    }
};