/*
Problem: 62. Unique Paths
Link: https://leetcode.com/problems/unique-paths/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(m*n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(m*n + m*n)

class Solution {
public:
    bool isValid(int i, int j, int& m, int& n){
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }

    int solve(int i, int j, int &m, int &n, vector<vector<int>> &dp){
        if (i==m-1 && j==n-1)
            return 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int right=0, down=0;

        if (isValid(i, j+1, m, n))
            right = solve(i, j+1, m, n, dp);
        if (isValid(i+1, j, m, n))
            down = solve(i+1, j, m, n, dp);
        
        return dp[i][j] = right+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};

// DP Tabulation, Space Complexity: O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[m-1][n-1] = 1;

        for (int i=0; i<n; i++){
            dp[m][i]=0;
        }
        for (int i=0; i<m; i++){
            dp[i][n]=0;
        }

        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (i==m-1 && j==n-1)
                    continue;
                dp[i][j] = dp[i][j+1] + dp[i+1][j]; // curr = right + down
            }
        }

        return dp[0][0];
    }
};