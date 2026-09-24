/*
Problem: 3550. Smallest Index With Digit Sum Equal to Index
Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/?envType=daily-question&envId=2026-09-24
Difficulty: Easy
Approach: Linear Search + Digit Sum
Time Complexity: O(n*D)
Note:
    
*/

class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while (n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (digitSum(nums[i]) == i)
                return i;
        }

        return -1;
    }
};