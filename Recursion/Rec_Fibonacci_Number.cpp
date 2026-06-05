/*
Problem: 509. Fibonacci Number
Link: https://leetcode.com/problems/fibonacci-number/
Difficulty: Easy
Approach: Recursion
Time Complexity: O(2^n)
Note:
    can be done in O(n) if done iteratively
*/

class Solution {
public:
    int fib(int n) {
        if (n==0 || n==1)
            return n;

        return fib(n-1) + fib(n-2);
    }
};