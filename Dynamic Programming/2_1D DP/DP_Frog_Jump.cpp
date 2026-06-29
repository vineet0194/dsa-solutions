/*
Problem: Frog Jump
Link: https://www.geeksforgeeks.org/problems/geek-jump/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    dp[i] stores cost for 0 to 1
*/

// Recursive Memoization, Space Complexity: O(2n)

class Solution {
  public:
    int frogJump(int i, vector<int>& height, vector<int>& dp){
        if (i==0)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int oneStep=INT_MAX, twoSteps=INT_MAX;
        oneStep = abs(height[i]-height[i-1]) + frogJump(i-1, height, dp);
        
        if (i>1)
            twoSteps = abs(height[i]-height[i-2]) + frogJump(i-2, height, dp);
        
        return dp[i] = min(oneStep, twoSteps);
    }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);

        return frogJump(n-1, height, dp);
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
  public:
  
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for (int i=1; i<n; i++){
            int oneStep = abs(height[i]-height[i-1]);
            if (i==1){
                dp[i] = oneStep + dp[i-1];
                continue;
            }
            int twoStep = 0;
            twoStep = abs(height[i]-height[i-2]);
            dp[i] = min(oneStep + dp[i-1], twoStep + dp[i-2]);
        }

        return dp[n-1];
    }
};