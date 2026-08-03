/*
Problem: 1406. Stone Game III
Link: https://leetcode.com/problems/stone-game-iii/description/?envType=daily-question&envId=2026-08-03
Difficulty: Hard
Approach: DP
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n+3, -1);

        for (int i=n; i<n+3; i++)
            dp[i] = 0;
        
        for (int i=n-1; i>=0; i--){
            int take1 = stoneValue[i] - dp[i+1];
        
            int take2 = INT_MIN;
            if (i+1 < n)
                take2 = stoneValue[i] + stoneValue[i+1] - dp[i+2];

            int take3 = INT_MIN;
            if (i+2 < n)
                take3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];

            dp[i] = max({take1, take2, take3});
        }
        
        int res = dp[0];

        if (res > 0)
            return "Alice";
        if (res < 0)
            return "Bob";

        return "Tie";
    }
};