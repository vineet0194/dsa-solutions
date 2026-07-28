/*
Problem: 191. Number of 1 Bits
Link: https://leetcode.com/problems/number-of-1-bits/
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(logn)
Note:
    
*/

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n>0){
            ans += n%2;
            n /= 2;
        }
        return ans;
    }
};