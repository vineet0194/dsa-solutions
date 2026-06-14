/*
Problem: 3959. Check Good Integer
Link: https://leetcode.com/problems/check-good-integer/description/
Difficulty: Easy
Approach: Linear Search + Bit manipulation
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool checkGoodInteger(int n) {
        int temp=n, sum=0, squareSum=0;
        while (temp>0){
            int digit = temp%10;
            sum += digit;
            squareSum += digit*digit;
            temp = temp/10;
        }
        return (squareSum - sum >= 50);
    }
};