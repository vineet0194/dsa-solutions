/*
Problem: 137. Single Number II
Link: https://leetcode.com/problems/single-number-ii/description/
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(32*n) => O(n)
Note:
    count the number of set bits,
    if %3 == 0 => unique num has 0 in that bit
    else => unique num has 1 in that bit (that is why it's not letting it be a multiple of 3)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i=0; i<32; i++){
            int setBitCount = 0;

            for (auto& num : nums)
                setBitCount += (num>>i)&1;
            
            if (setBitCount % 3 != 0)
                ans = ans | (1<<i);
        }
        
        return ans;
    }
};