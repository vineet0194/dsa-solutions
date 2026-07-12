/*
Problem: Sum of Compatible Numbers in Range I©leetcode
Link: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
Contest: Weekly Contest 505
Difficulty: Easy
Approach: Linear Search, maths
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for (int i=max(1, n-k); i<=n+k; i++){
            if ((n&i) == 0){
                sum += i;
            }
        }
        return sum;
    }
};