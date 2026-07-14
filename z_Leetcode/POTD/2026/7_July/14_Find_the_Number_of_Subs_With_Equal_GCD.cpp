/*
Problem: 3336. Find the Number of Subsequences With Equal GCD
Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14
Difficulty: Hard
Approach: DP
Time Complexity: O(n * V^2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n * V^2  +  n)

class Solution {
public:
    const int MOD = 1e9+7;
    int dp[201][201][201];
    int solve(int i, int first, int second, vector<int>& nums){
        if (i == nums.size()){
            bool bothNonEmpty = (first!=0 && second!=0);
            bool gcdsMatch = (first == second);

            return (bothNonEmpty && gcdsMatch);
        }

        if (dp[i][first][second] != -1)
            return dp[i][first][second];
        
        int skip = solve(i+1, first, second, nums);
        int take1 = solve(i+1, gcd(first, nums[i]), second, nums);
        int take2 = solve(i+1, first, gcd(second, nums[i]), nums);

        return dp[i][first][second] = (0LL + skip + take1 + take2)%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};