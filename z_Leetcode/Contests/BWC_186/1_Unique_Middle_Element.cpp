/*
Problem: Unique Middle Element
Link: https://leetcode.com/contest/biweekly-contest-186/problems/unique-middle-element/
Difficulty: Easy
Approach: Linear Search
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size()/2;
        int count = 0;
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == nums[mid])
                count++;
        }
        return count == 1;
    }
};