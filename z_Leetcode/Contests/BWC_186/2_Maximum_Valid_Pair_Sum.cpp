/*
Problem: Maximum Valid Pair Sum
Link: https://leetcode.com/contest/biweekly-contest-186/problems/maximum-valid-pair-sum/description/
Difficulty: Medium
Approach: Sliding Prefix Maximum
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = nums[0], ans=0;

        for (int j=k; j<n; j++){
            maxi = max(maxi, nums[j-k]);
            ans = max(ans, maxi+nums[j]);
        }

        return ans;
    }
};