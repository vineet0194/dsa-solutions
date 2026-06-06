/*
Problem: 53. Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/description/
Difficulty: Medium
Approach: Kadane's Algo
Time Complexity: O(n)
Note:
    iterate through the nums array keeping currSum (init. with INT_MIN) and maxSum
    add curr elem to the currSum, if currSum > maxSum => maxSum = currSum,
    if at any point, currSum < 0 => currSum = 0     // GREEDY
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int currSum=0, maxSum=INT_MIN;
        for (int i=0; i<nums.size(); i++){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};