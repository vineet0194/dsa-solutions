/*
Problem: 121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
Difficulty: Easy
Approach: Space Optimized DP / Greedy
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxProfit = 0;
        
        for (int i=0; i<prices.size(); i++){
            int profit = prices[i] - mini;
            maxProfit = max(maxProfit, profit);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};