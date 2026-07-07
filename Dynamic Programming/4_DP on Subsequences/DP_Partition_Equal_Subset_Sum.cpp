/*
Problem: 416. Partition Equal Subset Sum
Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*target) => O(n*sum) [since target = sum/2]
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*target + n)

class Solution {
public:
    bool solve(int i, int crsum, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (i==nums.size()){
            if (crsum == target)
                return true;
            else
                return false;
        }

        if (crsum == target)
            return true;

        if (dp[i][crsum] != -1)
            return dp[i][crsum];

        bool take = false, notTake = false;

        if (crsum + nums[i] <= target)
            take = solve(i+1, crsum + nums[i], target, nums, dp);
        
        notTake = solve(i+1, crsum, target, nums, dp);

        return dp[i][crsum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for (int i=0; i<n; i++)
            sum += nums[i];

        if (sum%2 != 0)
            return false;
        
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return solve(0, 0, target, nums, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*Sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (auto& num : nums)
            sum += num;

        if (sum%2 != 0)
            return false;
        
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        for (int crsum = 0; crsum < (sum/2)+1; crsum ++){
            dp[n][crsum] = (crsum == target) ? 1 : 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int crsum=target; crsum>=0; crsum--){
                bool take = false, notTake = false;
                
                if (crsum + nums[i] <= target)
                    take = dp[i+1][crsum+nums[i]];
                
                notTake = dp[i+1][crsum];
                
                dp[i][crsum] = take || notTake;
            }
        }

        return dp[0][0];
    }
};