/*
Problem: 63. Unique Paths II
Link: https://leetcode.com/problems/unique-paths-ii/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(m*n) 
Note:
    
*/

// Recursive Memoization, Space Complexity: O(m*n + m*n)

class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        return true;
    }
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (i==grid.size()-1 && j==grid[0].size()-1 && grid[i][j] != 1)
            return 1;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = 0, down = 0;

        if (isValid(i, j+1, grid) && grid[i][j+1] != 1)
            right = solve(i, j+1, grid, dp);
        
        if (isValid(i+1, j, grid) && grid[i+1][j] != 1)
            down = solve(i+1, j, grid, dp);

        if (right == 0)
            return down;
        
        if (down == 0)
            return right;
        
        return dp[i][j] = right+down;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
    }
};

// DP Tabulation, Space Complexity: O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[m-1][n-1] = 1;

        for (int i=m-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if ((i==m-1 && j==n-1) || grid[i][j] == 1)
                    continue;

                long long right=0, down=0;

                if (j+1 < n)
                    right = dp[i][j+1];

                if (i+1 < m)
                    down = dp[i+1][j];

                dp[i][j] = right + down;
            }
        }

        return (int) dp[0][0];
    }
};