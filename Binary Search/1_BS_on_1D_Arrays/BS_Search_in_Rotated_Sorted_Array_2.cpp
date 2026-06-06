/*
Problem: 81. Search in Rotated Sorted Array II
Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
Difficulty: Medium
Approach: Binary Search
Time Complexity: O(logn)
Note:
    check if arr[mid] == target, if found then return mid, if not then:
        check which half is sorted for the current mid,
            if left half then check whether target lies in that range [left, mid]
                if yes   => go left
                else     => go right
            if right half then check whether target lies in that range [mid, right]
                if yes   => go right
                else     => go left
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        while (l<=h){
            int mid = l+(h-l)/2;
            if (target == nums[mid]){
                return true;
            }
            // left part is sorted
            else if (nums[l] <= nums[mid]){
                if (nums[l] <= target && target <= nums[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }
            // right part is sorted
            else if (nums[mid] <= nums[h]){
                if (nums[mid] <= target && target <= nums[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return false;
    }
};