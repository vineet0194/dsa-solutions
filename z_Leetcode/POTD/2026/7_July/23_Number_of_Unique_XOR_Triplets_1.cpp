/*
Problem: 3513. Number of Unique XOR Triplets I
Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/?envType=daily-question&envId=2026-07-23
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(log n)
Note:
    
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1 || n == 2)
            return n;

        int bitCount = 0;
        while (n>0){
            n /= 2;
            bitCount++;
        }

        return 1 << bitCount;
    }
};