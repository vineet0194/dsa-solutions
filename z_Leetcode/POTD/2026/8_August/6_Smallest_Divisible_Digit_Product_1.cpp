/*
Problem: 3345. Smallest Divisible Digit Product I
Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06
Difficulty: Easy
Approach: Brute Force Linear Search
Time Complexity: Prod => O(logn)
                 Program => O(klogn)    k => no. of numbers examined before getting ans
Note:
    
*/

class Solution {
public:
    int productOfDigits(int n){
        int prod = 1;
        while (n > 0){
            prod *= n%10;
            n /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        int i = n;
        while (true){
            int prod = productOfDigits(i);
            if (prod % t == 0)
                return i;
            i++;
        }
        return -1;
    }
};