/*
Problem: Print Longest Increasing Subsequence
Link: https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i>=0; i--) {
            for (int last = i-1; last>=-1; last--) {
                int take = 0;

                if (last == -1 || arr[i] > arr[last])
                    take = 1 + dp[i + 1][i + 1];

                int skip = dp[i + 1][last + 1];

                dp[i][last + 1] = max(take, skip);
            }
        }

        vector<int> ans;
    
        int i = 0;
        int last = -1;
        
        while (i < n){
            int take = INT_MIN;
            
            if (last == -1 || arr[last] < arr[i])
                take = 1 + dp[i+1][i+1];
            
            int skip = dp[i+1][last+1];
            
            if (take >= skip) {
                ans.push_back(arr[i]);
                last = i;
            }
            i++;
        }

        return ans;
    }
};