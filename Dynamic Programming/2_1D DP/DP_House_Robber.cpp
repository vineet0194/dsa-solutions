/*
Problem: 198. House Robber
Link: https://leetcode.com/problems/house-robber/
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(2n)

class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& nums){
        if (i==nums.size()-1)
            return nums[i];
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i+2, dp, nums);
        int notTake = solve(i+1, dp, nums);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, dp, nums);        
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1, -1);
        dp[n-1] = nums[n-1];
        dp[n] = 0;

        for (int i=n-2; i>=0; i--){
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }

        return dp[0];
    }
};