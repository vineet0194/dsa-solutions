/*
Problem: 231. Power of Two
Link: https://leetcode.com/problems/power-of-two/description/
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(logN)
Note:
    
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0)
            return false;

        int ans = 0;
        while (n>0){
            ans += n%2;
            n /= 2;
        }
        return (ans > 1) ? false : true;
    }
};