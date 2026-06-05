/*
Problem: 283. Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/description/
Difficulty: Easy
Approach: 2 Pointer
Time Complexity: O(n)
Note:
    1 pointer is the insertor and the other is the iterator
    j searches for non-zero integers and swaps with i which is expected
    to be sitting at a position where a zero is present
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size()==1)
            return;
        
        int i=0, j=0;
        while (i<nums.size() && j<nums.size()){
            while (j<nums.size() && nums[j] == 0)
                j++;
            if (j >= nums.size())
                break;
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j++] = temp;
        }
        return;
    }
};