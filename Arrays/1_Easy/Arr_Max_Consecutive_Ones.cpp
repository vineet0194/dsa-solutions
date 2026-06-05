/*
Problem: 485. Max Consecutive Ones
Link: https://leetcode.com/problems/max-consecutive-ones/
Difficulty: Easy
Approach: Linear Traversal and comparison
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int max = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 1)
                curr++;

            if (curr > max)
                max = curr;
            
            if (nums[i] == 0)
                curr = 0;
        }

        return max;
    }
};