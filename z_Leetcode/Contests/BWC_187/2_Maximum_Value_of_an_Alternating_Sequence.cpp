/*
Problem: Maximum Value of an Alternating Sequence©leetcode
Link: https://leetcode.com/contest/biweekly-contest-187/problems/maximum-value-of-an-alternating-sequence/description/
Difficulty: Medium
Approach: Math
Time Complexity: O(1)
Note:
    
*/

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        
        long long k = n / 2;
        
        return s + (k * m) - (k - 1);
    }
};