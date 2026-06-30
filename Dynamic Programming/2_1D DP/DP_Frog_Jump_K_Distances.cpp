/*
Problem: Frog jump with K distances
Link: https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances?source=strivers-a2z-dsa-track
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(2n)

class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& heights, int k){
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int minCost = INT_MAX;
        for (int j=1; j<=k; j++){
            if (i-j >= 0)
                minCost = min(minCost, abs(heights[i]-heights[i-j]) + solve(i-j, dp, heights, k));
        }

        return dp[i] = minCost;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(n-1, dp, heights, k);
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i=1; i<n; i++){
            int minCost = INT_MAX;
            for (int j=k; j>=1; j--){
                if (i-j >= 0)
                    minCost = min(minCost, abs(heights[i]-heights[i-j]) + dp[i-j]);
            }
            dp[i] = minCost;
        }

        return dp[n-1];
    }
};
