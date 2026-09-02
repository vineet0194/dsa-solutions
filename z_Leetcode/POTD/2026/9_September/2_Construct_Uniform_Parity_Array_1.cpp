/*
Problem: 3875. Construct Uniform Parity Array I
Link: https://leetcode.com/problems/construct-uniform-parity-array-i/description/?envType=daily-question&envId=2026-09-03
Difficulty: Easy
Approach: Logic
Time Complexity: O(1)
Note:
    We need all numbers to be either all even or all odd.

    Using subtraction:

    even - odd = odd
    odd - even = odd
    So we can always convert numbers to odd.
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};