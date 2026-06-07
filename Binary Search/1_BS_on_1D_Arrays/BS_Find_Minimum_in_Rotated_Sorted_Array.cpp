/*
Problem: 153. Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
Difficulty: Medium
Approach: Binary Search
Time Complexity: O(logn)
Note:
    there is no targt value to search for, you need to find the minimum.
    the trick is to find whether to go left or right after you find mid.
    intuition:
        [4 5 6 7 0 1 2] or [0 1 2 4 5 6 7]
        can clearly see that if nums[mid] > nums[h] for the first iteration, then the array is def rotated
        and the minimum must lie on the right side of mid, => l = mid+1;
        if nums[mid] < nums[h] => the minimum must lie on the left, therefore h = mid.
        h = mid is important and not h = mid-1, as mid can still be an answer, ex: [3 1 2] where nums[mid] = 1,
        nums[mid] = 1 < nums[mid] = 2. so 1 can still be the answer, for next iteration => h = mid
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h=nums.size()-1, mid;
        while (l<=h){
            mid = l+(h-l)/2;
            if (nums[mid] <= nums[h]){
                h = mid;
            }
            else
                l = mid+1;
        }
        return nums[mid];
    }
};