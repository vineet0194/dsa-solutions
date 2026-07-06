/*
Problem: 494. Target Sum
Link: https://leetcode.com/problems/target-sum/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*sum)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*sum + n)

class Solution {
public:
    int solve(int i, int crsum, int& totalSum, int& target, vector<int>& nums, vector<vector<int>>& dp){
        if (i==nums.size()){
            if (crsum == target)
                return 1;
            else
                return 0;
        }

        if (dp[i][totalSum + crsum] != -1)
            return dp[i][totalSum + crsum];

        int neg = solve(i+1, crsum-(2*nums[i]), totalSum, target, nums, dp);
        int pos = solve(i+1, crsum, totalSum, target, nums, dp);

        return dp[i][totalSum + crsum] = neg+pos;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum=0;
        for (int i=0; i<nums.size(); i++)
            sum += nums[i];

        vector<vector<int>> dp(n, vector<int>((2*sum)+1, -1));

        return solve(0, sum, sum, target, nums, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int i=0; i<nums.size(); i++)
            sum += nums[i];

        vector<vector<int>> dp(n+1, vector<int>((2*sum)+1, -1));

        for (int crsum=0; crsum<(2*sum)+1; crsum++){
            dp[n][crsum] = (crsum-sum == target) ? 1 : 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int crsum=(2*sum); crsum>=0; crsum--){
                int neg=0, pos=0;

                if (crsum - 2*nums[i] >= 0)
                    neg = dp[i+1][crsum-(2*nums[i])];

                pos = dp[i+1][crsum];
             
                dp[i][crsum] = neg+pos;
            }
        }

        return dp[0][2*sum];
    }
};