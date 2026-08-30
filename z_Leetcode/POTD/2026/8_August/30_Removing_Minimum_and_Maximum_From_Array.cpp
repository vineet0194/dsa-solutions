/*
Problem: 2091. Removing Minimum and Maximum From Array
Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/?envType=daily-question&envId=2026-08-30
Difficulty: Medium
Approach: Enumeration
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = 0, maxi = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mini])
                mini = i;

            if (nums[i] > nums[maxi])
                maxi = i;
        }

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        int ans = min({right+1, n-left, left+1 + n-right});

        return ans;
    }
};
