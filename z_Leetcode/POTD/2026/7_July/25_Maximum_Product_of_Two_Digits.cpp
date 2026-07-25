/*
Problem: 3536. Maximum Product of Two Digits
Link: https://leetcode.com/problems/maximum-product-of-two-digits/?envType=daily-question&envId=2026-07-25
Difficulty: Easy
Approach: Brute Force Enumeration
Time Complexity: O(logn)
Note:
    
*/

class Solution {
public:
    int maxProduct(int n) {

    int maxi = n % 10;
    int smaxi = -1;
    n /= 10;

    while (n > 0){
        int digit = n % 10;

        if (digit > maxi){
            smaxi = maxi;
            maxi = digit;
        }
        else if (digit > smaxi)
            smaxi = digit;

        n /= 10;
    }

        return maxi*smaxi;
    }
};