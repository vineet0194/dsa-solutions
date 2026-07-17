/*
Problem: 300. Longest Increasing Subsequence
Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n^2 + n)

class Solution {
public:
    int n;
    int solve(int i, int last, vector<int>& nums, vector<vector<int>>& dp){
        if (i == n)
            return 0;

        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];

        int take = 0;
        if (last == -1 || nums[i] > nums[last])
            take = 1 + solve(i+1, i, nums, dp);

        int skip = solve(i+1, last, nums, dp);

        return dp[i][last + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        this->n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // for (int last=0; last<n+1; last++)       // redundant as we already init with 0
        //     dp[n][last] = 0;

        for (int i = n-1; i>=0; i--) {
            for (int last = i-1; last>=-1; last--) {
                int take = 0;

                if (last == -1 || nums[i] > nums[last])
                    take = 1 + dp[i + 1][i + 1];

                int skip = dp[i + 1][last + 1];

                dp[i][last + 1] = max(take, skip);
            }
        }

        return dp[0][0];    // dp[0][-1] is stored in dp[0][0]
    }
};

// Space Optimized, Space Complexity: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        // for (int last=0; last<n+1; last++){      // redundant as we already init with 0
        //     prev[last] = 0;
        //     curr[last] = 0;
        // }

        for (int i = n-1; i>=0; i--) {
            for (int last = i-1; last>=-1; last--) {
                int take = 0;

                if (last == -1 || nums[i] > nums[last])
                    take = 1 + prev[i + 1];

                int skip = prev[last + 1];

                curr[last + 1] = max(take, skip);
            }
            prev = curr;
        }

        return prev[0];    // prev[-1] is stored in prev[0]
    }
};

/* ------------------------------------------------------------------------------------------- */

// ! Bottom Up DP Tabulation Another Method, TC: O(n^2), SC: O(n)
// t[i] => max LIS ending at i
// Explanation: https://leetcode.com/problems/longest-increasing-subsequence/solutions/8402245/classic-dp-longest-increasing-subsequenc-tobx

// ! THIS IS THE NATURAL/EASIER/PREFERRED WAY FOR LIS BASED DP QUESTIONS ===> LEARN IT!

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    t[i] = max(t[i], 1+t[j]);
                }
            }
        }

        int maxi = t[0];
        for (int i=0; i<n; i++){
            if (maxi < t[i])
                maxi = t[i];
        }

        return maxi;
    }
};