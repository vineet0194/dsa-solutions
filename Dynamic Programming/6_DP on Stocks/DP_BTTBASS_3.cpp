/*
Problem: 123. Best Time to Buy and Sell Stock III
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
Difficulty: Hard
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n + n)

class Solution {
public:
    int solve(int i, int trans, bool buyStatus, vector<int>& prices,  vector<vector<vector<int>>> &dp){
        if (i==prices.size() || trans == 2)
            return 0;

        if (dp[i][trans][buyStatus] != -1)
            return dp[i][trans][buyStatus];

        int buy = 0, sell = 0;

        if (buyStatus){
            int buyNow = 0 - prices[i] + solve(i+1, trans, false, prices, dp);
            int dontBuy = solve(i+1, trans, true, prices, dp);
            buy = max(buyNow, dontBuy);
        }
        else{
            int sellNow = prices[i] + solve(i+1, trans+1, true, prices, dp);
            int dontSell = solve(i+1, trans, false, prices, dp);
            sell = max(sellNow, dontSell);
        }

        return dp[i][trans][buyStatus] = max(buy, sell);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, 0, true, prices, dp);
    }
};

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, -1)));

        for (int trans=0; trans<3; trans++){
            dp[n][trans][0] = 0;
            dp[n][trans][1] = 0;
        }

        for (int i=0; i<n+1; i++){
            dp[i][2][0] = 0;
            dp[i][2][1] = 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int trans=1; trans>=0; trans--){
                for (int buyStatus=1; buyStatus>=0; buyStatus--){
                    int buy = 0, sell = 0;

                    if (buyStatus){
                        int buyNow = 0 - prices[i] + dp[i+1][trans][0];
                        int dontBuy = dp[i+1][trans][1];
                        buy = max(buyNow, dontBuy);
                    }
                    else{
                        int sellNow = prices[i] + dp[i+1][trans+1][1];
                        int dontSell = dp[i+1][trans][0];
                        sell = max(sellNow, dontSell);
                    }

                    dp[i][trans][buyStatus] = max(buy, sell);
                }
            }
        }

        return dp[0][0][1];
    }
};

// Space Optimized, Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(3, vector<int>(2, -1));
        vector<vector<int>> curr(3, vector<int>(2, -1));

        for (int trans=0; trans<3; trans++){
            prev[trans][0] = 0;
            prev[trans][1] = 0;
            curr[trans][0] = 0;
            curr[trans][1] = 0;
        }

        for (int i=n-1; i>=0; i--){
            for (int trans=1; trans>=0; trans--){
                for (int buyStatus=1; buyStatus>=0; buyStatus--){
                    int buy = 0, sell = 0;

                    if (buyStatus){
                        int buyNow = 0 - prices[i] + prev[trans][0];
                        int dontBuy = prev[trans][1];
                        buy = max(buyNow, dontBuy);
                    }
                    else{
                        int sellNow = prices[i] + prev[trans+1][1];
                        int dontSell = prev[trans][0];
                        sell = max(sellNow, dontSell);
                    }

                    curr[trans][buyStatus] = max(buy, sell);
                }
            }
            prev = curr;
        }

        return prev[0][1];
    }
};