/*
Problem: 26. Remove Duplicates from Sorted Array
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Difficulty: Easy
Approach: 2 Pointer
Time Complexity: O(n)
Note:
    1 pointer works as the insertor, the other as the iterator
    skip through duplicates and insert only the first occurence of a new element
    first occurence ==> nums[j] != nums[j-1]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int i,j;
        for (i=1, j=1; j<nums.size();){
            while (j<nums.size() && nums[j]==nums[j-1])
                j++;
            if (j>=nums.size())
                break;
            nums[i] = nums[j];
            i++; j++;
        }
        return i;
    }
};