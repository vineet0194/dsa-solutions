/*
Problem: Partitions with Given Difference
Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n*target)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*target + target)

class Solution {
  public:
    int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (i==arr.size()){
            if (target == 0)
                return 1;
            else
                return 0;
        }
        
        if (dp[i][target] != -1)
            return dp[i][target];
            
        int take=0, notTake=0;
        
        if (target-arr[i] >= 0)
            take = solve(i+1, target-arr[i], arr, dp);
        
        notTake = solve(i+1, target, arr, dp);
        
        return dp[i][target] = take+notTake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        
        for (auto& num : arr)
            sum += num;

        int target = (sum+diff);
        
        if (target%2 != 0)
            return 0;
        
        target /= 2;
            
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return solve(0, target, arr, dp);
    }
};

// DP Tabulation, Space Complexity: O(n*target)

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        
        for (auto& num : arr)
            sum += num;

        int target = (sum+diff);
        
        if (target%2 != 0)
            return 0;
        
        target /= 2;
            
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        for (int i=0; i<target+1; i++){
            dp[n][i] = (i==0) ? 1 : 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int tar=0; tar<target+1; tar++){
                int take=0, notTake=0;
                
                if (tar-arr[i] >= 0)
                    take = dp[i+1][tar-arr[i]];
                
                notTake = dp[i+1][tar];
                
                dp[i][tar] = take+notTake;
            }
        }
        
        return dp[0][target];
    }
};