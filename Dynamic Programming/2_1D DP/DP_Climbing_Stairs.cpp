/*
Problem: 
Link: https://leetcode.com/problems/climbing-stairs/description/
Difficulty: Easy
Approach: DP
Time Complexity: O(n)
Note:
    think of recursive approach first
    apply memoization there
    then convert it to tabulation
*/

// Recursive Memoization, Space Complexity: O(2n)

class Solution {
public:
    int climb(int i, int n, vector<int> &dp){
        if (i==n) return 1;
        if (i>n) return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneStep = climb(i+1, n, dp);
        int twoSteps = climb(i+2, n, dp);
        
        return dp[i] = oneStep + twoSteps;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climb(0, n, dp);
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        for (int i=n-1; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }
};

// Optimized DP, Space Complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2 = 0;
        for (int i=n-1; i>=0; i--){
            int curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};