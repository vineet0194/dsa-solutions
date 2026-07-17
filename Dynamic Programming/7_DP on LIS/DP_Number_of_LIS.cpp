/*
Problem: 673. Number of Longest Increasing Subsequence
Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// DP Tabulation, Space Complexity: O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);
        vector<int> count(n, 1);

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    if (t[i] == 1 + t[j])
                        count[i] += count[j];
                    else if (t[i] < 1+t[j]){
                        t[i] = 1 + t[j];
                        count[i] = count[j];
                    }
                }
            }
        }

        int maxi = t[0];
        for (int i=0; i<n; i++){
            if (maxi < t[i])
                maxi = t[i];
        }

        int ans = 0;
        for (int i=0; i<n; i++){
            if (t[i] == maxi)
                ans += count[i];
        }

        return ans;
    }
};