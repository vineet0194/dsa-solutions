/*
Problem: Rod Cutting
Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n^2 + n)

class Solution {
  public:
    int solve(int i, int len, vector<int>& price, vector<vector<int>>& dp){
        if (i == price.size() || len == price.size())
            return 0;
        
        if (dp[i][len] != -1)
            return dp[i][len];
        
        int take=0, notTake=0;
        
        if (len+i+1 <= price.size())
            take = price[i] + solve(i, len+i+1, price, dp);
        
        notTake = solve(i+1, len, price, dp);
        
        return dp[i][len] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
            
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, 0, price, dp);
    }
};

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for (int i=0; i<n+1; i++){
            dp[n][i] = 0;
            dp[i][n] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int len=n-1; len>=0; len--){
                int take=0, notTake=0;
                
                if (len+i+1 <= n)
                    take = price[i] + dp[i][len+i+1];
                
                notTake = dp[i+1][len];
                
                dp[i][len] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }
};