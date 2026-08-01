/*
Problem: 486. Predict the Winner
Link: https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// Recursive Memoization

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if (i > j)
            return 0;
        
        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];
        
        int takeI = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));
        int takeJ = nums[j] + min(solve(i, j-2, nums, dp), solve(i+1, j-1, nums, dp));

        return dp[i][j] = max(takeI, takeJ);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        if (n%2 == 0)
            return true;

        int sum = 0;
        for (auto& num : nums)
            sum += num;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int p1 = solve(0, n-1, nums, dp);
        int p2 = sum - p1;

        return p1 >= p2;
    }
};

