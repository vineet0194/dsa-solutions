/*
Problem: 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/?envType=daily-question&envId=2026-08-11
Difficulty: Easy
Approach: Hash Set + Prefix Consecutive Sum
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0]+1;

        unordered_set<int> set;
        set.insert(nums[0]);

        for (int i=1; i<n; i++)
            set.insert(nums[i]);

        int sum = nums[0];
        for (int i=1; i<n; i++){
            if (nums[i] == nums[i-1]+1)
                sum += nums[i];
            else
                break;
        }

        while (set.find(sum)!=set.end())
            sum++;

        return sum;
    }
};