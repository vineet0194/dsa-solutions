/*
Problem: 518. Coin Change II
Link: https://leetcode.com/problems/coin-change-ii/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n*amount)
Note:
    ? tried solve(i, remainingAmount)    instead of      solve(i, currentSum)
*/

// Recursive Memoization, Space Complexity: O(n*amount + amount)

class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if (i == coins.size()){
            if (amount == 0)
                return 1;
            else
                return 0;
        }

        if (amount == 0)
            return 1;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take=0, notTake=0;
        if (amount - coins[i] >= 0)
            take = solve(i, amount - coins[i], coins, dp);
        
        notTake = solve(i+1, amount, coins, dp);

        return dp[i][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), [](const int& a, const int& b){
            return a > b;
        });
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        
        return solve(0, amount, coins, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*amount)


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        sort(coins.begin(), coins.end(), [](const int& a, const int& b){
            return a > b;
        });        

        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, -1));

        for (int i=0; i<amount+1; i++){
            dp[n][i] = (i == 0) ? 1 : 0;
        }

        for (int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }

        for (int i=n-1; i>=0; i--){
            for (int crsum=0; crsum<amount+1; crsum++){
                if (crsum == 0) continue;
                
                unsigned long long take=0, notTake=0;

                if (crsum - coins[i] >= 0)
                    take = dp[i][crsum-coins[i]];
                
                notTake = dp[i+1][crsum];

                dp[i][crsum] = take+notTake;
            }
        }
        
        return dp[0][amount];
    }
};