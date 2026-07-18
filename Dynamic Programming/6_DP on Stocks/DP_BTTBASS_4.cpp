/*
Problem: 188. Best Time to Buy and Sell Stock IV
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
Difficulty: Hard
Approach: DP
Time Complexity: O(n*k*2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*k*2 => (n*k) + n =>CS height)

class Solution {
public:
    int n;
    int solve(int i, int trans, int buyStatus, vector<int>& prices, int& k, vector<vector<vector<int>>>& dp){
        if (i == n || trans == k)
            return 0;
        
        if (dp[i][trans][buyStatus] != -1)
            return dp[i][trans][buyStatus];

        int buy=0, sell=0;
        if (buyStatus){
            int buyNow = 0 - prices[i] + solve(i+1, trans, false, prices, k, dp);
            int skip = solve(i+1, trans, true, prices, k, dp);
            buy = max(buyNow, skip);
        } else{
            int sellNow = prices[i] + solve(i+1, trans+1, true, prices, k, dp);
            int skip  = solve(i+1, trans, false, prices, k, dp);
            sell = max(sellNow, skip);
        }

        return dp[i][trans][buyStatus] = max(buy, sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        this->n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2, -1)));
        return solve(0, 0, true, prices, k, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*k)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));

        for (int i=0; i<n; i++){
            dp[i][k][0] = 0;
            dp[i][k][1] = 0;
        }

        for (int trans=0; trans<k+1; trans++){
            dp[n][trans][0] = 0;
            dp[n][trans][1] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int trans=k-1; trans>=0; trans--){
                for (int buyStatus=1; buyStatus>=0; buyStatus--){
                    int buy=0, sell=0;

                    if (buyStatus){
                        int buyNow = 0 - prices[i] + dp[i+1][trans][0];
                        int skip = dp[i+1][trans][1];
                        buy = max(buyNow, skip);
                    } else{
                        int sellNow = prices[i] + dp[i+1][trans+1][1];
                        int skip  = dp[i+1][trans][0];
                        sell = max(sellNow, skip);
                    }

                    dp[i][trans][buyStatus] = max(buy, sell);
                }
            }
        }

        return dp[0][0][1];
    }
};

// Space Optimization, Space Complexity: O(k)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(k+1, vector<int>(2, -1));
        vector<vector<int>> curr(k+1, vector<int>(2, -1));

        for (int trans=0; trans<k+1; trans++){
            prev[trans][0] = 0;
            prev[trans][1] = 0;
            curr[trans][0] = 0;
            curr[trans][1] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int trans=k-1; trans>=0; trans--){
                for (int buyStatus=1; buyStatus>=0; buyStatus--){
                    int buy=0, sell=0;

                    if (buyStatus){
                        int buyNow = 0 - prices[i] + prev[trans][0];
                        int skip = prev[trans][1];
                        buy = max(buyNow, skip);
                    } else{
                        int sellNow = prices[i] + prev[trans+1][1];
                        int skip  = prev[trans][0];
                        sell = max(sellNow, skip);
                    }

                    curr[trans][buyStatus] = max(buy, sell);
                }
                prev = curr;
            }
        }

        return prev[0][1];
    }
};