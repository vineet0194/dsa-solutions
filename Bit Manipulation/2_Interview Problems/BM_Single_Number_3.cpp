/*
Problem: 260. Single Number III
Link: https://leetcode.com/problems/single-number-iii/description/
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        
        for (auto& num : nums)
            res ^= num;
        
        int idx = 0;
        for (int i=0; i<32; i++){
            if ((res>>i)&1){
                idx = i;
                break;
            }
        }

        int ans1 = 0;
        int ans2 = 0;
        for (auto& num : nums){
            if (((num>>idx)&1) == 0)
                ans1 ^= num;
            else
                ans2 ^= num;
        }
        
        return {ans1, ans2};
    }
};