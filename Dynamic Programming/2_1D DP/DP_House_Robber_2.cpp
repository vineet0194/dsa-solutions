/*
Problem: 213. House Robber II
Link: https://leetcode.com/problems/house-robber-ii/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(2n)

class Solution {
public:
    int solve(int i, int end, vector<int>& dp, vector<int>& nums){
        if (i == end)
            return nums[i];
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i+2, end, dp, nums);
        int notTake = solve(i+1, end, dp, nums);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        int start0 = solve(0, n-2, dp1, nums);
        int start1 = solve(1, n-1, dp2, nums);

        return max(start0, start1);
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n+1, -1);
        dp1[n-2] = nums[n-2];
        dp1[n-1] = 0;

        for (int i=n-3; i>=0; i--){
            dp1[i] = max(dp1[i+1], nums[i]+dp1[i+2]);
        }

        vector<int> dp2(n+1, -1);
        dp2[n-1] = nums[n-1];
        dp2[n] = 0;

        for (int i=n-2; i>=1; i--){
            dp2[i] = max(dp2[i+1], nums[i]+dp2[i+2]);
        }

        return max(dp1[0], dp2[1]);
    }
};