/*
Problem: 540. Single Element in a Sorted Array
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/
Difficulty: Medium
Approach: BS
Time Complexity: O(logn)
Note:
    to the left of the single element, the twins are as follows : first one of them is at an odd index, next is at even
    to the right, first is at an even index and the second at an odd index. this data can be used to direct l and h's behaviour
    during the BS traversal.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int left=0, right=nums.size()-1;
        while (left<=right){
            int mid = left+(right-left)/2;
            if (mid == 0){
                if (nums[mid]!=nums[mid+1])
                    return nums[mid];
            }
            else if (mid == nums.size()-1){
                if (nums[mid]!=nums[mid-1])
                    return nums[mid];
            }
            else{
                if (nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
                    return nums[mid];
                else if (
                    (mid%2==0 && nums[mid]==nums[mid+1]) ||
                    (mid%2==1 && nums[mid]==nums[mid-1])
                )
                    left=mid+1;
                else if (
                    (mid%2==0 && nums[mid]==nums[mid-1]) ||
                    (mid%2==1 && nums[mid]==nums[mid+1])
                )
                    right=mid-1;
            }
        }
        return -1;
    }
};