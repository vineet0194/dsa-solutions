/*
Problem: 34. Find First and Last Position of Element in Sorted Array
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
Difficulty: Medium
Approach: BS and Lower Bound Calc
Time Complexity: O(logn)
Note:
    if we try to find the lower bound, we must check that the number actually exists in the array
    and we are not just searching for an insertion position. after we find that, we simply iterate +1 till the
    last occurence of that element.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        
        bool exists = false;

        int l=0, h=nums.size()-1, temp=-1;
        while (l<=h){
            int m = l+(h-l)/2;
            if (nums[m]>=target){
                if (nums[m]==target)
                    exists=true;
                temp=m;
                h=m-1;
            }
            else
                l=m+1;
        }

        if (!exists)
            return ans;
        
        ans[0] = temp;
        while (temp<nums.size() && nums[temp]==target)
            temp++;
        ans[1] = temp-1;

        return ans;
    }
};