/*
Problem: 136. Single Number
Link: https://leetcode.com/problems/single-number/
Difficulty: Easy
Approach: Bit Manipulation or XOR
Time Complexity: O(n)
Note:
    for XOR, A^A = 0, this implies that every value that occurs twice gets cancelled by its twin
    only the single number remains at the end, hence the answer
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];

        int ans=0;
        for (int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};