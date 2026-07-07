/*
Problem: 322. Coin Change
Link: https://leetcode.com/problems/coin-change/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(nlogn + n*amount) => O(n*amount)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*amount + amount)

class Solution {
public:
    int solve(int i, int crsum, int& amount, vector<int>& coins, vector<vector<int>>& dp){
        if (i == coins.size()){
            if (crsum == amount)
                return 0;
            else
                return 1e5;
        }

        if (crsum == amount)
            return 0;

        if (dp[i][crsum] != -1)
            return dp[i][crsum];

        int take=1e5, notTake=1e5;

        if (crsum + coins[i] <= amount)
            take = 1 + solve(i, crsum + coins[i], amount, coins, dp);
        
        notTake = solve(i+1, crsum, amount, coins, dp);

        return dp[i][crsum] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), [](const int &a, const int &b){
            return a > b;
        });
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = solve(0, 0, amount, coins, dp);

        if (ans >= 1e5)
            return -1;
        
        return ans;
    }
};

// DP Tabulation, Space Complexity: O(n*amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), [](const int& a, const int& b){
            return a > b;
        });

        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        for (int i=0; i<amount+1; i++){
            dp[n][i] = (i == amount) ? 0 : 1e5;
        }

        for (int i=0; i<n+1; i++){
            dp[i][amount] = 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int crsum=amount; crsum>=0; crsum--){
                if (crsum == amount) continue;      // base case already defined
                int take=1e5, notTake=1e5;
                
                long long next = 1LL*crsum + coins[i];

                if (next <= amount)
                    take = 1 + dp[i][next];
                
                notTake = dp[i+1][crsum];

                dp[i][crsum] = min(take, notTake);
            }
        }

        int ans = dp[0][0];

        if (ans >= 1e5)
            return -1;
        
        return ans;
    }
};