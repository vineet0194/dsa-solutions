/*
Problem: Longest Bitonic Subsequence
Link: https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    dp1[i] = max(dp1[i], 1+dp1[j]);
                }
            }
        }
        
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>i; j--){
                if (nums[j] < nums[i])
                    dp2[i] = max(dp2[i], 1+dp2[j]);
            }
        }

        int maxi = 0;
        for (int i=1; i<n-1; i++){
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i]+dp2[i]-1);
            }
        }
        
        return maxi;
        
    }
};
