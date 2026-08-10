/*
Problem: 1510. Stone Game IV
Link: https://leetcode.com/problems/stone-game-iv/?envType=daily-question&envId=2026-08-10
Difficulty: Hard
Approach: DP
Time Complexity: O(n*sqrt(n))
Note:
    
*/

// Recursive Memoization, SC: O(n + n + n)

class Solution {
public:
    bool solve(int n, vector<bool> &dp, vector<bool> &visited){
        if (n==0)
            return false;
        
        if (visited[n])
            return dp[n];
        
        visited[n] = true;

        for (int k=1; k*k<=n; k++){
            if (solve(n-(k*k), dp, visited) == false)
                return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<bool> visited(n+1, false);
        vector<bool> dp(n+1, false);
        return solve(n, dp, visited);
    }
};

// DP Tabulation, SC: O(n + n)

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        dp[0] = false;

        for (int i=1; i<n+1; i++){
            for (int k=1; k*k<=i; k++){
                if (dp[i-(k*k)] == false){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};