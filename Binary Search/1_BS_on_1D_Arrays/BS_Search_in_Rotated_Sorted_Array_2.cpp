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
    
    Duplicates can hide the rotation point, so sometimes you cannot determine which half is sorted.
    The trick
        If all three are equal:

        nums[l] == nums[mid] && nums[mid] == nums[h]

        we simply throw away the duplicates at the ends:

        l++;
        h--;

        Now the ambiguity is gone, and we can continue the normal binary search logic.
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
            if (nums[l] == nums[mid] && nums[mid] == nums[h]){
                l++;
                h--;
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