/*
Problem: 64. Minimum Path Sum
Link: https://leetcode.com/problems/minimum-path-sum/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(m*n)
Note:
    
*/


// Recursive Memoization, Space Complexity: O(m+n + m*n)

class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        return true;
    }
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if (i==grid.size()-1 && j==grid[0].size()-1)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right=-1, down=-1;
        if (isValid(i, j+1, grid)){
            right = solve(i, j+1, grid, dp);
        }

        if (isValid(i+1, j, grid)){
            down = solve(i+1, j, grid, dp);
        }

        if (right == -1)
            return dp[i][j] = grid[i][j] + down;
        if (down == -1)
            return dp[i][j] = grid[i][j] + right;

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};

// DP Tabulation, Space Complexity: O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[m-1][n-1] = grid[m-1][n-1];
        
        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (i==m-1 && j==n-1)
                    continue;

                int right = INT_MAX, down = INT_MAX;

                if (i + 1 < m)
                    down = dp[i+1][j];

                if (j + 1 < n)
                    right = dp[i][j+1];

                dp[i][j] = grid[i][j] + min(right, down);
            }
        }

        return dp[0][0];
    }
};