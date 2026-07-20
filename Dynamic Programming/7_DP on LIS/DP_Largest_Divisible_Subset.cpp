/*
Problem: 368. Largest Divisible Subset
Link: https://leetcode.com/problems/largest-divisible-subset/
Difficulty: Medium
Approach: DP 
Time Complexity: O(n^2)
Note:
    
*/

// DP Tabulation, Space Complexity: O(n^2 + n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int last=-1; last<n; last++)
            dp[n][last+1] = 0;

        for (int i=n-1; i>=0; i--){
            for (int last=n-1; last>=-1; last--){
                int take = 0;
                if (last == -1 || nums[i]%nums[last] == 0)
                    take = 1 + dp[i+1][i+1];
                
                int skip = dp[i+1][last+1];

                dp[i][last+1] = max(take, skip);
            }
        }

        int i=0;
        int last = -1;
        vector<int> ans;

        while (i<n){
            int take = INT_MIN;

            if (last == -1 || nums[i]%nums[last] == 0)
                take = 1 + dp[i+1][i+1];
            
            int skip = dp[i+1][last+1];

            if (take >= skip){
                ans.push_back(nums[i]);
                last = i;
            }

            i++;
        }
        
        return ans;
    }
};