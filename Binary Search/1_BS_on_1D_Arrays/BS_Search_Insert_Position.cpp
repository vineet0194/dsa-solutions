/*
Problem: 35. Search Insert Position
Link: https://leetcode.com/problems/search-insert-position/description/
Difficulty: Easy
Approach: BS Lower Bound Calculation
Time Complexity: O(logn)
Note:
    insertion should be done at an index where a value exists that is just >= target
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1, ans=nums.size();
        while (l<=h){
            int m = l+(h-l)/2;
            if (nums[m]>=target){
                if (nums[m]==target)
                    return m;
                ans = m;
                h = m-1;
            }
            else
                l = m+1;
        }
        return ans;
    }
};