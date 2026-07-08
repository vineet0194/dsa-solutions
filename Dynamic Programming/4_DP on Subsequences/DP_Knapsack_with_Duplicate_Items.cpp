/*
Problem: Knapsack with Duplicate Items
Link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n*capacity)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*capacity + capacity)

class Solution {
  public:
    int solve(int i, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if (i == val.size()){
            if (capacity == 0)
                return 0;
            else
                return INT_MIN;
        }
        
        if (capacity == 0)
            return 0;
            
        if (dp[i][capacity] != -1)
            return dp[i][capacity];
        
        int take=0, notTake=0;
        
        if (capacity - wt[i] >= 0)
            take = val[i] + solve(i, capacity - wt[i], val, wt, dp);
        
        notTake = solve(i+1, capacity, val, wt, dp);
        
        return dp[i][capacity] = max(take, notTake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        
        return solve(0, capacity, val, wt, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*capacity)

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));
        
        for (int i=0; i<capacity+1; i++){
            dp[n][i] = (i == 0) ? 0 : INT_MIN;
        }
        
        for (int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int cap=0; cap<=capacity; cap++){
                if (cap == 0) continue;
                
                int take = 0, notTake = 0;
                
                if (cap - wt[i] >= 0)
                    take = val[i] + dp[i][cap - wt[i]];
                
                notTake = dp[i+1][cap];
                
                dp[i][cap] = max(take, notTake);
            }
        }
        
        return dp[0][capacity];
    }
};