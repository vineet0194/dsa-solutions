/*
Problem: 3904. Smallest Stable Index II
Link: https://leetcode.com/problems/smallest-stable-index-ii/description/?envType=daily-question&envId=2026-09-04
Difficulty: Easy
Approach: Array + Prefix Sum
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxs(n);
        vector<int> mins(n);

        int maxi = nums[0];
        int mini = nums[n-1];

        for (int i=0; i<n; i++){
            if (nums[i] > maxi)
                maxi = nums[i];
            maxs[i] = maxi;
            
            if (nums[n-1-i] < mini)
                mini = nums[n-1-i];
            mins[n-1-i] = mini;
        }
        
        for (int i=0; i<n; i++){
            if (maxs[i]-mins[i] <= k)
                return i;
        }

        return -1;
    }
};