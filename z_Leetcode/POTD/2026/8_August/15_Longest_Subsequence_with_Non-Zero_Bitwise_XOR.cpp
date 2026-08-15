/*
Problem: 3702. Longest Subsequence With Non-Zero Bitwise XOR
Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int val = 0;

        int n = nums.size();
        bool allZeros = true;

        for (int i=0; i<n; i++){
            if (nums[i] != 0)
                allZeros = false;
            val ^= nums[i];
        }

        if (allZeros)
            return 0;

        if (val != 0)
            return n;
        else
            return n-1;
    }
};