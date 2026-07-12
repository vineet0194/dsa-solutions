/*
Problem: 122. Best Time to Buy and Sell Stock II
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n + n)

class Solution {
public:
    int solve(int i, int buyStatus, vector<int>& prices, vector<vector<int>>& dp){
        if (i==prices.size())
            return 0;

        if (dp[i][buyStatus] != -1)
            return dp[i][buyStatus];
        
        int buy=0, sell=0;
        if (buyStatus){
            // bought, moved to next (next should be a sell)
            int buyNow = 0 - prices[i] + solve(i+1, false, prices, dp);

            // didnt buy, moved to next (next should be buy)
            int dontBuy = solve(i+1, true, prices, dp);

            buy = max(buyNow, dontBuy);
        }
        else{
            // sold, moved to next (next should be buy)
            int sellNow = prices[i] + solve(i+1, true, prices, dp);

            // didnt sell, moved to next (next should be sell)
            int dontSell = solve(i+1, false, prices, dp);

            sell = max(sellNow, dontSell);
        }
        
        return dp[i][buyStatus] = max(buy, sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, true, prices, dp);
    }
};


// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i=n-1; i>=0; i--){
            for (int buyStatus=1; buyStatus>=0; buyStatus--){
                int buy=0, sell=0;

                if (buyStatus){
                    // bought, moved to next (next should be a sell)
                    int buyNow = 0 - prices[i] + dp[i+1][0];

                    // didnt buy, moved to next (next should be buy)
                    int dontBuy = dp[i+1][1];

                    buy = max(buyNow, dontBuy);
                }
                else{
                    // sold, moved to next (next should be buy)
                    int sellNow = prices[i] + dp[i+1][1];

                    // didnt sell, moved to next (next should be sell)
                    int dontSell = dp[i+1][0];

                    sell = max(sellNow, dontSell);
                }
                
                dp[i][buyStatus] = max(buy, sell);
            }
        }

        return dp[0][1];
    }
};


// Space Optimization, Space Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> prev = {0, 0};
        vector<int> curr = prev;

        for (int i=n-1; i>=0; i--){
            for (int buyStatus=1; buyStatus>=0; buyStatus--){
                int buy=0, sell=0;

                if (buyStatus){
                    // bought, moved to next (next should be a sell)
                    int buyNow = 0 - prices[i] + prev[0];

                    // didnt buy, moved to next (next should be buy)
                    int dontBuy = prev[1];

                    buy = max(buyNow, dontBuy);
                }
                else{
                    // sold, moved to next (next should be buy)
                    int sellNow = prices[i] + prev[1];

                    // didnt sell, moved to next (next should be sell)
                    int dontSell = prev[0];

                    sell = max(sellNow, dontSell);
                }
                curr[buyStatus] = max(buy, sell);
            }
            prev = curr;
        }

        return prev[1];
    }
};