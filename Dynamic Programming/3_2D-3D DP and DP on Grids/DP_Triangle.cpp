/*
Problem: 120. Triangle
Link: https://leetcode.com/problems/triangle/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n² + n)

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if (i==triangle.size())
            return 0;

        if (dp[i][j] != 1e5)
            return dp[i][j];

        // j (curr pos)
        int takeJ = triangle[i][j] + solve(i+1, j, triangle, dp);
        
        // j+1 (curr pos + 1)
        int takeJ1 = triangle[i][j] + solve(i+1, j+1, triangle, dp);

        return dp[i][j] = min(takeJ, takeJ1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e5));

        return solve(0, 0, triangle, dp);
    }
};

// DP Tabulation, Space Complexity: O(n²)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i=0; i<triangle[n-1].size(); i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for (int i=n-2; i>=0; i--){
            for (int j=triangle[i].size()-1; j>=0; j--){
                int takeJ = triangle[i][j] + dp[i+1][j];
                int takeJ1 = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(takeJ, takeJ1);
            }
        }

        return dp[0][0];
    }
};