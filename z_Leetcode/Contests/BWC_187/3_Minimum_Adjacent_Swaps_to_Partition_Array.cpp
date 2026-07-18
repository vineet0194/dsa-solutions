/*
Problem: Minimum Adjacent Swaps to Partition Array©leetcode
Link: https://leetcode.com/contest/biweekly-contest-187/problems/minimum-adjacent-swaps-to-partition-array/
Difficulty: Medium
Approach: Counting Inversions
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    const int MOD = 1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long count1 = 0; // elements in range [a, b]
        long long count2 = 0; // elements > b
        long long swaps = 0;

        for (auto& num: nums){
            if (num < a)
                swaps = (swaps+count1+count2)%MOD;
            else if (num >= a && num <= b){
                swaps = (swaps+count2)%MOD;
                count1++;
            }
            else
                count2++;
        }

        return swaps;
    }
};©leetcode