/*
Problem: 0-1 Knapsack Problem
Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n*W)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n + n*W)

class Solution {
  public:
    int solve(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if (W==0 || i==val.size()){
            return 0;
        }
        
        if (dp[i][W] != -1)
            return dp[i][W];
        
        int take=0, notTake=0;
        
        if (wt[i] <= W)
            take = val[i] + solve(i+1, W-wt[i], val, wt, dp);
            
        notTake = solve(i+1, W, val, wt, dp);
        
        return dp[i][W] = max(take, notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(W+1, -1));
        return solve(0, W, val, wt, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*W)

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    
        for (int i=0; i<W+1; i++){  // out of bound case
            dp[n][i] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int j=W; j>=0; j--){
                int take=0;
                if (wt[i] <= j)
                    take = val[i] + dp[i+1][j-wt[i]];
                int notTake = dp[i+1][j];
                dp[i][j] = max(take, notTake);
            }
        }
    
        return dp[0][W];
    }
};

// Optimized 1D DP Solution