/*
Problem: 309. Best Time to Buy and Sell Stock with Cooldown
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n + n)

class Solution {
public:
    int solve(int i, int buyStatus, vector<int>& prices, vector<vector<int>>& dp){
        if (i>=prices.size())
            return 0;
        
        if (dp[i][buyStatus] != -1)
            return dp[i][buyStatus];
        
        int buy = 0, sell = 0;
        if (buyStatus){
            int buyNow = 0-prices[i] + solve(i+1, false, prices, dp);
            int dontBuy = solve(i+1, true, prices, dp);
            buy = max(buyNow, dontBuy);
        }
        else{
            int sellNow = prices[i] + solve(i+2, true, prices, dp);
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
        vector<vector<int>> dp(n+2, vector<int>(2, -1));

        for (int i=n; i<n+2; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int buyStatus=1; buyStatus>=0; buyStatus--){
                int buy = 0, sell = 0;

                if (buyStatus){
                    int buyNow = 0-prices[i] + dp[i+1][0];
                    int dontBuy = dp[i+1][1];
                    buy = max(buyNow, dontBuy);
                }
                else{
                    int sellNow = prices[i] + dp[i+2][1];
                    int dontSell = dp[i+1][0];
                    sell = max(sellNow, dontSell);
                }

                dp[i][buyStatus] = max(buy, sell);
            }
        }

        return dp[0][1];
    }
};

// Space Optimization, Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, -1));

        vector<int> prev2(2, -1);
        vector<int> prev1(2, -1);
        vector<int> curr(2, -1);

        prev1[0] = 0; prev1[1] = 0;
        prev2[0] = 0; prev2[1] = 0;

        for (int i=n-1; i>=0; i--){
            for (int buyStatus=1; buyStatus>=0; buyStatus--){
                int buy = 0, sell = 0;

                if (buyStatus){
                    int buyNow = 0-prices[i] + prev1[0];
                    int dontBuy = prev1[1];
                    buy = max(buyNow, dontBuy);
                }
                else{
                    int sellNow = prices[i] + prev2[1];
                    int dontSell = prev1[0];
                    sell = max(sellNow, dontSell);
                }

                curr[buyStatus] = max(buy, sell);
            }
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1[1];
    }
};