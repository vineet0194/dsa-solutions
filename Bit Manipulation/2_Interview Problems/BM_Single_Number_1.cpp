/*
Problem: 136. Single Number 1
Link: https://leetcode.com/problems/single-number/description/
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];

        int ans=0;
        for (int i=0; i<nums.size(); i++)
            ans ^= nums[i];
        
        return ans;
    }
};